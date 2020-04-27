open Jest;
open Expect;

open DomTestingLibrary__Queries__ByTestId;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByTestId: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByTestId: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByTestId: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByTestId: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByTestId: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByTestId: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
  let name = "getByTestId";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByTestId"|}
  ];
  let fn = getByTestId;
  let fnRe = getByTestIdRe;
  let fnFn = getByTestIdFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByTestId";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByTestId"|}
  ];
  let fn = getAllByTestId;
  let fnRe = getAllByTestIdRe;
  let fnFn = getAllByTestIdFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByTestId";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByTestId"|}
  ];
  let fn = queryByTestId;
  let fnRe = queryByTestIdRe;
  let fnFn = queryByTestIdFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByTestId";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByTestId"|}
  ];
  let fn = queryAllByTestId;
  let fnRe = queryAllByTestIdRe;
  let fnFn = queryAllByTestIdFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByTestId";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByTestId"|}
  ];
  let fn = findByTestId;
  let fnRe = findByTestIdRe;
  let fnFn = findByTestIdFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByTestId";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByTestId"|}
  ];
  let fn = findAllByTestId;
  let fnRe = findAllByTestIdRe;
  let fnFn = findAllByTestIdFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
