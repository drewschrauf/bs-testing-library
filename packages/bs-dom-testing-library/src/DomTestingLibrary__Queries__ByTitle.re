module ByTitleOptions = {
  type t = {
    exact: option(bool),
    normalizer: option(string => string),
  };

  let make = (~exact, ~normalizer) => {exact, normalizer};
};

[@bs.module "@testing-library/dom"]
external _getByTitle:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTitleOptions.t
  ) =>
  Dom.element =
  "getByTitle";

[@bs.module "@testing-library/dom"]
external _getAllByTitle:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTitleOptions.t
  ) =>
  array(Dom.element) =
  "getAllByTitle";

[@bs.module "@testing-library/dom"]
external _queryByTitle:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTitleOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByTitle";

[@bs.module "@testing-library/dom"]
external _queryAllByTitle:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTitleOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByTitle";

[@bs.module "@testing-library/dom"]
external _findByTitle:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTitleOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByTitle";

[@bs.module "@testing-library/dom"]
external _findAllByTitle:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTitleOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByTitle";

module type ByTitle = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByTitleOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByTitle) => {
  let byTitle =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Str(text), ByTitleOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byTitleRe =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Re(re), ByTitleOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byTitleFn =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Fn(fn), ByTitleOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByTitle;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByTitle = Get.byTitle;
let getByTitleRe = Get.byTitleRe;
let getByTitleFn = Get.byTitleFn;

module GetAll =
  Make({
    let fn = _getAllByTitle;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByTitle = GetAll.byTitle;
let getAllByTitleRe = GetAll.byTitleRe;
let getAllByTitleFn = GetAll.byTitleFn;

module Query =
  Make({
    let fn = _queryByTitle;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByTitle = Query.byTitle;
let queryByTitleRe = Query.byTitleRe;
let queryByTitleFn = Query.byTitleFn;

module QueryAll =
  Make({
    let fn = _queryAllByTitle;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByTitle = QueryAll.byTitle;
let queryAllByTitleRe = QueryAll.byTitleRe;
let queryAllByTitleFn = QueryAll.byTitleFn;

module Find =
  Make({
    let fn = _findByTitle;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByTitle = Find.byTitle;
let findByTitleRe = Find.byTitleRe;
let findByTitleFn = Find.byTitleFn;

module FindAll =
  Make({
    let fn = _findAllByTitle;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByTitle = FindAll.byTitle;
let findAllByTitleRe = FindAll.byTitleRe;
let findAllByTitleFn = FindAll.byTitleFn;
