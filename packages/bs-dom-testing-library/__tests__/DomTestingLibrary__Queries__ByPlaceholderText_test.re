open Jest;
open Expect;

open DomTestingLibrary__Queries__ByPlaceholderText;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByPlaceholderText: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByPlaceholderText: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByPlaceholderText: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByPlaceholderText: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByPlaceholderText: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByPlaceholderText: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
  let name = "getByPlaceholderText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByPlaceholderText"|}
  ];
  let fn = getByPlaceholderText;
  let fnRe = getByPlaceholderTextRe;
  let fnFn = getByPlaceholderTextFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByPlaceholderText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByPlaceholderText"|}
  ];
  let fn = getAllByPlaceholderText;
  let fnRe = getAllByPlaceholderTextRe;
  let fnFn = getAllByPlaceholderTextFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByPlaceholderText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByPlaceholderText"|}
  ];
  let fn = queryByPlaceholderText;
  let fnRe = queryByPlaceholderTextRe;
  let fnFn = queryByPlaceholderTextFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByPlaceholderText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByPlaceholderText"|}
  ];
  let fn = queryAllByPlaceholderText;
  let fnRe = queryAllByPlaceholderTextRe;
  let fnFn = queryAllByPlaceholderTextFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByPlaceholderText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByPlaceholderText"|}
  ];
  let fn = findByPlaceholderText;
  let fnRe = findByPlaceholderTextRe;
  let fnFn = findByPlaceholderTextFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByPlaceholderText";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByPlaceholderText"|}
  ];
  let fn = findAllByPlaceholderText;
  let fnRe = findAllByPlaceholderTextRe;
  let fnFn = findAllByPlaceholderTextFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
