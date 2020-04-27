open Jest;
open Expect;

open DomTestingLibrary__Queries__ByDisplayValue;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByDisplayValue: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByDisplayValue: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByDisplayValue: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByDisplayValue: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByDisplayValue: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByDisplayValue: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
  let name = "getByDisplayValue";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByDisplayValue"|}
  ];
  let fn = getByDisplayValue;
  let fnRe = getByDisplayValueRe;
  let fnFn = getByDisplayValueFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByDisplayValue";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByDisplayValue"|}
  ];
  let fn = getAllByDisplayValue;
  let fnRe = getAllByDisplayValueRe;
  let fnFn = getAllByDisplayValueFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByDisplayValue";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByDisplayValue"|}
  ];
  let fn = queryByDisplayValue;
  let fnRe = queryByDisplayValueRe;
  let fnFn = queryByDisplayValueFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByDisplayValue";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByDisplayValue"|}
  ];
  let fn = queryAllByDisplayValue;
  let fnRe = queryAllByDisplayValueRe;
  let fnFn = queryAllByDisplayValueFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByDisplayValue";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByDisplayValue"|}
  ];
  let fn = findByDisplayValue;
  let fnRe = findByDisplayValueRe;
  let fnFn = findByDisplayValueFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByDisplayValue";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByDisplayValue"|}
  ];
  let fn = findAllByDisplayValue;
  let fnRe = findAllByDisplayValueRe;
  let fnFn = findAllByDisplayValueFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
