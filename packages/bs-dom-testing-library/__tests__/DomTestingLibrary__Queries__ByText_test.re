open Jest;
open Expect;

open DomTestingLibrary__Queries__ByText;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByText: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByText: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByText: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByText: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByText: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByText: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
    }))
  |}
];

let root: Dom.element = [%bs.raw {| document.createElement("div") |}];

beforeEach(() => {
  %bs.raw
  {|
    jest.clearAllMocks()
  |}
});

module type TestCase = {
  let name: string;
  let setupExternalFunction: unit => unit;
  type returnType;
  let fn:
    (
      ~selector: string=?,
      ~exact: bool=?,
      ~normalizer: string => string=?,
      ~ignore: bool=?,
      ~ignoreTags: string=?,
      string,
      Dom.element
    ) =>
    returnType;
  let fnRe:
    (
      ~selector: string=?,
      ~exact: bool=?,
      ~normalizer: string => string=?,
      ~ignore: bool=?,
      ~ignoreTags: string=?,
      Js.Re.t,
      Dom.element
    ) =>
    returnType;
  let fnFn:
    (
      ~selector: string=?,
      ~exact: bool=?,
      ~normalizer: string => string=?,
      ~ignore: bool=?,
      ~ignoreTags: string=?,
      (string, Dom.element) => bool,
      Dom.element
    ) =>
    returnType;
  let result: returnType;
};

module Make = (TC: TestCase) => {
  test(
    TC.name ++ "without options",
    () => {
      let result = TC.fn("text", root);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, "text", {
          exact: undefined,
          selector: undefined,
          normalizer: undefined,
          ignore: undefined
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );

  test(
    TC.name ++ "with options",
    () => {
      let result =
        TC.fn(
          "text",
          root,
          ~selector="div",
          ~exact=true,
          ~normalizer=a => a,
          ~ignoreTags="div",
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, "text", {
          exact: true,
          selector: "div",
          normalizer: expect.any(Function),
          ignore: "div"
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );

  test(
    TC.name ++ "Re no options",
    () => {
      let result = TC.fnRe([%re "/text/"], root);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, /text/, {
          exact: undefined,
          selector: undefined,
          normalizer: undefined,
          ignore: undefined
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );

  test(
    TC.name ++ "Re with options",
    () => {
      let result =
        TC.fnRe(
          [%re "/text/"],
          root,
          ~selector="div",
          ~exact=true,
          ~normalizer=a => a,
          ~ignoreTags="div",
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, /text/, {
          exact: true,
          selector: "div",
          normalizer: expect.any(Function),
          ignore: "div"
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );

  test(
    TC.name ++ "Fn no options",
    () => {
      let result = TC.fnFn((_, _) => true, root);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, expect.any(Function), {
          exact: undefined,
          selector: undefined,
          normalizer: undefined,
          ignore: undefined
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );

  test(
    TC.name ++ "Fn with options",
    () => {
      let result =
        TC.fnFn(
          (_, _) => true,
          root,
          ~selector="div",
          ~exact=true,
          ~normalizer=a => a,
          ~ignoreTags="div",
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, expect.any(Function), {
          exact: true,
          selector: "div",
          normalizer: expect.any(Function),
          ignore: "div"
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );
};

include Make({
  let name = "getByText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByText"|}
  ];
  let fn = getByText;
  let fnRe = getByTextRe;
  let fnFn = getByTextFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByText"|}
  ];
  let fn = getAllByText;
  let fnRe = getAllByTextRe;
  let fnFn = getAllByTextFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByText"|}
  ];
  let fn = queryByText;
  let fnRe = queryByTextRe;
  let fnFn = queryByTextFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByText"|}
  ];
  let fn = queryAllByText;
  let fnRe = queryAllByTextRe;
  let fnFn = queryAllByTextFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByText"|}
  ];
  let fn = findByText;
  let fnRe = findByTextRe;
  let fnFn = findByTextFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByText"|}
  ];
  let fn = findAllByText;
  let fnRe = findAllByTextRe;
  let fnFn = findAllByTextFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
