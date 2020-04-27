open Jest;
open Expect;

open DomTestingLibrary__Queries__ByLabelText;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByLabelText: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByLabelText: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByLabelText: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByLabelText: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByLabelText: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByLabelText: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
      string,
      Dom.element
    ) =>
    returnType;
  let fnRe:
    (
      ~selector: string=?,
      ~exact: bool=?,
      ~normalizer: string => string=?,
      Js.Re.t,
      Dom.element
    ) =>
    returnType;
  let fnFn:
    (
      ~selector: string=?,
      ~exact: bool=?,
      ~normalizer: string => string=?,
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
        TC.fn("text", root, ~selector="div", ~exact=true, ~normalizer=a => a);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, "text", {
          exact: true,
          selector: "div",
          normalizer: expect.any(Function)
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
          normalizer: undefined
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
          [%re "/text/"], root, ~selector="div", ~exact=true, ~normalizer=a =>
          a
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, /text/, {
          exact: true,
          selector: "div",
          normalizer: expect.any(Function)
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
          normalizer: undefined
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
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, expect.any(Function), {
          exact: true,
          selector: "div",
          normalizer: expect.any(Function)
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );
};

include Make({
  let name = "getByLabelText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByLabelText"|}
  ];
  let fn = getByLabelText;
  let fnRe = getByLabelTextRe;
  let fnFn = getByLabelTextFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByLabelText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByLabelText"|}
  ];
  let fn = getAllByLabelText;
  let fnRe = getAllByLabelTextRe;
  let fnFn = getAllByLabelTextFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByLabelText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByLabelText"|}
  ];
  let fn = queryByLabelText;
  let fnRe = queryByLabelTextRe;
  let fnFn = queryByLabelTextFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByLabelText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByLabelText"|}
  ];
  let fn = queryAllByLabelText;
  let fnRe = queryAllByLabelTextRe;
  let fnFn = queryAllByLabelTextFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByLabelText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByLabelText"|}
  ];
  let fn = findByLabelText;
  let fnRe = findByLabelTextRe;
  let fnFn = findByLabelTextFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByLabelText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByLabelText"|}
  ];
  let fn = findAllByLabelText;
  let fnRe = findAllByLabelTextRe;
  let fnFn = findAllByLabelTextFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
