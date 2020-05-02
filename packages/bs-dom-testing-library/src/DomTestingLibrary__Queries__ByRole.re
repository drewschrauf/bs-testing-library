module ByRoleOptions = {
  module TextMatch = {
    [@unboxed]
    type t =
      | Any('a): t;
    let makeString = s => Any(s);
    let makeRe = r => Any(r);
    let makeFn = f => Any(f);
  };

  type t = {
    exact: option(bool),
    hidden: option(bool),
    name: option(TextMatch.t),
    normalizer: option(string => string),
  };

  let make = (~exact, ~hidden, ~normalizer, ~name) => {
    exact,
    hidden,
    normalizer,
    name:
      switch (name) {
      | Some(`str(s)) => Some(TextMatch.makeString(s))
      | Some(`re(r)) => Some(TextMatch.makeRe(r))
      | Some(`fn(f)) => Some(TextMatch.makeFn(f))
      | None => None
      },
  };
};

[@bs.module "@testing-library/dom"]
external _getByRole:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByRoleOptions.t
  ) =>
  Dom.element =
  "getByRole";

[@bs.module "@testing-library/dom"]
external _getAllByRole:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByRoleOptions.t
  ) =>
  array(Dom.element) =
  "getAllByRole";

[@bs.module "@testing-library/dom"]
external _queryByRole:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByRoleOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByRole";

[@bs.module "@testing-library/dom"]
external _queryAllByRole:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByRoleOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByRole";

[@bs.module "@testing-library/dom"]
external _findByRole:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByRoleOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByRole";

[@bs.module "@testing-library/dom"]
external _findAllByRole:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByRoleOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByRole";

module type ByRole = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByRoleOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByRole) => {
  let byRole =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        ~hidden: option(bool)=?,
        ~name:
           option(
             [
               | `str(string)
               | `re(Js.Re.t)
               | `fn((string, Dom.element) => bool)
             ],
           )=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Str(text),
      ByRoleOptions.make(~exact, ~normalizer, ~hidden, ~name),
    )
    ->T.mapReturnType;

  let byRoleRe =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        ~hidden: option(bool)=?,
        ~name:
           option(
             [
               | `str(string)
               | `re(Js.Re.t)
               | `fn((string, Dom.element) => bool)
             ],
           )=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Re(re),
      ByRoleOptions.make(~exact, ~normalizer, ~hidden, ~name),
    )
    ->T.mapReturnType;

  let byRoleFn =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        ~hidden: option(bool)=?,
        ~name:
           option(
             [
               | `str(string)
               | `re(Js.Re.t)
               | `fn((string, Dom.element) => bool)
             ],
           )=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Fn(fn),
      ByRoleOptions.make(~exact, ~normalizer, ~hidden, ~name),
    )
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByRole;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByRole = Get.byRole;
let getByRoleRe = Get.byRoleRe;
let getByRoleFn = Get.byRoleFn;

module GetAll =
  Make({
    let fn = _getAllByRole;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByRole = GetAll.byRole;
let getAllByRoleRe = GetAll.byRoleRe;
let getAllByRoleFn = GetAll.byRoleFn;

module Query =
  Make({
    let fn = _queryByRole;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByRole = Query.byRole;
let queryByRoleRe = Query.byRoleRe;
let queryByRoleFn = Query.byRoleFn;

module QueryAll =
  Make({
    let fn = _queryAllByRole;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByRole = QueryAll.byRole;
let queryAllByRoleRe = QueryAll.byRoleRe;
let queryAllByRoleFn = QueryAll.byRoleFn;

module Find =
  Make({
    let fn = _findByRole;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByRole = Find.byRole;
let findByRoleRe = Find.byRoleRe;
let findByRoleFn = Find.byRoleFn;

module FindAll =
  Make({
    let fn = _findAllByRole;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByRole = FindAll.byRole;
let findAllByRoleRe = FindAll.byRoleRe;
let findAllByRoleFn = FindAll.byRoleFn;
