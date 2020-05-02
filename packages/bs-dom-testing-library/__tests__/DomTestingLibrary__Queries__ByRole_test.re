open Jest;
open Expect;

open DomTestingLibrary__Queries__ByRole;

let tl = [%bs.raw {| require("@testing-library/dom") |}];
[%bs.raw
  {|
    jest.mock("@testing-library/dom", () => ({
      getByRole: jest.fn().mockImplementation(function(el) { return el; }),
      getAllByRole: jest.fn().mockImplementation(function(el) { return [el]; }),
      queryByRole: jest.fn().mockImplementation(function(el) { return el; }),
      queryAllByRole: jest.fn().mockImplementation(function(el) { return [el]; }),
      findByRole: jest.fn().mockImplementation(function(el) { return Promise.resolve(el); }),
      findAllByRole: jest.fn().mockImplementation(function(el) { return Promise.resolve([el]); }),
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
      ~exact: bool=?,
      ~normalizer: string => string=?,
      ~hidden: bool=?,
      ~name: [
               | `str(string)
               | `re(Js.Re.t)
               | `fn((string, Dom.element) => bool)
             ]
               =?,
      string,
      Dom.element
    ) =>
    returnType;
  let fnRe:
    (
      ~exact: bool=?,
      ~normalizer: string => string=?,
      ~hidden: bool=?,
      ~name: [
               | `str(string)
               | `re(Js.Re.t)
               | `fn((string, Dom.element) => bool)
             ]
               =?,
      Js.Re.t,
      Dom.element
    ) =>
    returnType;
  let fnFn:
    (
      ~exact: bool=?,
      ~normalizer: string => string=?,
      ~hidden: bool=?,
      ~name: [
               | `str(string)
               | `re(Js.Re.t)
               | `fn((string, Dom.element) => bool)
             ]
               =?,
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
          hidden: undefined,
          name: undefined
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
          ~exact=true,
          ~normalizer=a => a,
          ~hidden=true,
          ~name=`str("test"),
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, "text", {
          exact: true,
          normalizer: expect.any(Function),
          hidden: true,
          name: "test"
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
          normalizer: undefined,
          hidden: undefined,
          name: undefined
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
          ~exact=true,
          ~normalizer=a => a,
          ~hidden=true,
          ~name=`re([%re "/test/"]),
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, /text/, {
          exact: true,
          normalizer: expect.any(Function),
          hidden: true,
          name: /test/
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
          normalizer: undefined,
          hidden: undefined,
          name: undefined
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
          ~exact=true,
          ~normalizer=a => a,
          ~hidden=true,
          ~name=`fn((s, _) => s === "test"),
        );
      TC.setupExternalFunction();
      [%bs.raw
        {|
        expect(tl[global.externalFunction]).toHaveBeenCalledWith(root, expect.any(Function), {
          exact: true,
          normalizer: expect.any(Function),
          hidden: true,
          name: expect.any(Function)
        })
      |}
      ]
      ->ignore;
      expect(result) |> toEqual(TC.result);
    },
  );
};

include Make({
  let name = "getByRole";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getByRole"|}
  ];
  let fn = getByRole;
  let fnRe = getByRoleRe;
  let fnFn = getByRoleFn;
  type returnType = Dom.element;
  let result = root;
});

include Make({
  let name = "getAllByRole";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "getAllByRole"|}
  ];
  let fn = getAllByRole;
  let fnRe = getAllByRoleRe;
  let fnFn = getAllByRoleFn;
  type returnType = array(Dom.element);
  let result = [|root|];
});

include Make({
  let name = "queryByRole";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryByRole"|}
  ];
  let fn = queryByRole;
  let fnRe = queryByRoleRe;
  let fnFn = queryByRoleFn;
  type returnType = option(Dom.element);
  let result = Some(root);
});

include Make({
  let name = "queryAllByRole";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "queryAllByRole"|}
  ];
  let fn = queryAllByRole;
  let fnRe = queryAllByRoleRe;
  let fnFn = queryAllByRoleFn;
  type returnType = option(array(Dom.element));
  let result = Some([|root|]);
});

include Make({
  let name = "findByRole";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findByRole"|}
  ];
  let fn = findByRole;
  let fnRe = findByRoleRe;
  let fnFn = findByRoleFn;
  type returnType = Js.Promise.t(Dom.element);
  let result = Js.Promise.resolve(root);
});

include Make({
  let name = "findAllByRole";
  let setupExternalFunction = () => [%bs.raw
    {| global.externalFunction = "findAllByRole"|}
  ];
  let fn = findAllByRole;
  let fnRe = findAllByRoleRe;
  let fnFn = findAllByRoleFn;
  type returnType = Js.Promise.t(array(Dom.element));
  let result = Js.Promise.resolve([|root|]);
});
