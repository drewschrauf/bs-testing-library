open Jest;
open Expect;

open DomTestingLibrary__Queries__ByAltText;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByAltText: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByAltText: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByAltText: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByAltText: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByAltText: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByAltText: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
    (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
    returnType;
  let fnRe:
    (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
    returnType;
  let fnFn:
    (
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
      let result = TC.fn("text", root, ~exact=true, ~normalizer=a => a);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, "text", {
          exact: true,
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
        TC.fnRe([%re "/text/"], root, ~exact=true, ~normalizer=a => a);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, /text/, {
          exact: true,
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
        TC.fnFn((_, _) => true, root, ~exact=true, ~normalizer=a => a);
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, expect.any(Function), {
          exact: true,
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
  let name = "getByAltText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByAltText"|}
  ];
  let fn = getByAltText;
  let fnRe = getByAltTextRe;
  let fnFn = getByAltTextFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByAltText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByAltText"|}
  ];
  let fn = getAllByAltText;
  let fnRe = getAllByAltTextRe;
  let fnFn = getAllByAltTextFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByAltText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByAltText"|}
  ];
  let fn = queryByAltText;
  let fnRe = queryByAltTextRe;
  let fnFn = queryByAltTextFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByAltText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByAltText"|}
  ];
  let fn = queryAllByAltText;
  let fnRe = queryAllByAltTextRe;
  let fnFn = queryAllByAltTextFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByAltText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByAltText"|}
  ];
  let fn = findByAltText;
  let fnRe = findByAltTextRe;
  let fnFn = findByAltTextFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByAltText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByAltText"|}
  ];
  let fn = findAllByAltText;
  let fnRe = findAllByAltTextRe;
  let fnFn = findAllByAltTextFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
