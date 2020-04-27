open Jest;
open Expect;

open DomTestingLibrary__Queries__ByTitle;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByTitle: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByTitle: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByTitle: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByTitle: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByTitle: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByTitle: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
  let name = "getByTitle";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByTitle"|}
  ];
  let fn = getByTitle;
  let fnRe = getByTitleRe;
  let fnFn = getByTitleFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByTitle";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByTitle"|}
  ];
  let fn = getAllByTitle;
  let fnRe = getAllByTitleRe;
  let fnFn = getAllByTitleFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByTitle";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByTitle"|}
  ];
  let fn = queryByTitle;
  let fnRe = queryByTitleRe;
  let fnFn = queryByTitleFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByTitle";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByTitle"|}
  ];
  let fn = queryAllByTitle;
  let fnRe = queryAllByTitleRe;
  let fnFn = queryAllByTitleFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByTitle";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByTitle"|}
  ];
  let fn = findByTitle;
  let fnRe = findByTitleRe;
  let fnFn = findByTitleFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByTitle";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByTitle"|}
  ];
  let fn = findAllByTitle;
  let fnRe = findAllByTitleRe;
  let fnFn = findAllByTitleFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
