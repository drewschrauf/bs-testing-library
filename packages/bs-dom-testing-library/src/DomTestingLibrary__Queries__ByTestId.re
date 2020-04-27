module ByTestIdOptions = {
  type t = {
    exact: option(bool),
    normalizer: option(string => string),
  };

  let make = (~exact, ~normalizer) => {exact, normalizer};
};

[@bs.module "@testing-library/dom"]
external _getByTestId:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTestIdOptions.t
  ) =>
  Dom.element =
  "getByTestId";

[@bs.module "@testing-library/dom"]
external _getAllByTestId:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTestIdOptions.t
  ) =>
  array(Dom.element) =
  "getAllByTestId";

[@bs.module "@testing-library/dom"]
external _queryByTestId:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTestIdOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByTestId";

[@bs.module "@testing-library/dom"]
external _queryAllByTestId:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTestIdOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByTestId";

[@bs.module "@testing-library/dom"]
external _findByTestId:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTestIdOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByTestId";

[@bs.module "@testing-library/dom"]
external _findAllByTestId:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTestIdOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByTestId";

module type ByTestId = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByTestIdOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByTestId) => {
  let byTestId =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Str(text), ByTestIdOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byTestIdRe =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Re(re), ByTestIdOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byTestIdFn =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Fn(fn), ByTestIdOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByTestId;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByTestId = Get.byTestId;
let getByTestIdRe = Get.byTestIdRe;
let getByTestIdFn = Get.byTestIdFn;

module GetAll =
  Make({
    let fn = _getAllByTestId;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByTestId = GetAll.byTestId;
let getAllByTestIdRe = GetAll.byTestIdRe;
let getAllByTestIdFn = GetAll.byTestIdFn;

module Query =
  Make({
    let fn = _queryByTestId;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByTestId = Query.byTestId;
let queryByTestIdRe = Query.byTestIdRe;
let queryByTestIdFn = Query.byTestIdFn;

module QueryAll =
  Make({
    let fn = _queryAllByTestId;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByTestId = QueryAll.byTestId;
let queryAllByTestIdRe = QueryAll.byTestIdRe;
let queryAllByTestIdFn = QueryAll.byTestIdFn;

module Find =
  Make({
    let fn = _findByTestId;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByTestId = Find.byTestId;
let findByTestIdRe = Find.byTestIdRe;
let findByTestIdFn = Find.byTestIdFn;

module FindAll =
  Make({
    let fn = _findAllByTestId;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByTestId = FindAll.byTestId;
let findAllByTestIdRe = FindAll.byTestIdRe;
let findAllByTestIdFn = FindAll.byTestIdFn;
