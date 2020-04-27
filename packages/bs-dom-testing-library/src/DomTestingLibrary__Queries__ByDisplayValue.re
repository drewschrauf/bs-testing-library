module ByDisplayValueOptions = {
  type t = {
    exact: option(bool),
    normalizer: option(string => string),
  };

  let make = (~exact, ~normalizer) => {exact, normalizer};
};

[@bs.module "@testing-library/dom"]
external _getByDisplayValue:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByDisplayValueOptions.t
  ) =>
  Dom.element =
  "getByDisplayValue";

[@bs.module "@testing-library/dom"]
external _getAllByDisplayValue:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByDisplayValueOptions.t
  ) =>
  array(Dom.element) =
  "getAllByDisplayValue";

[@bs.module "@testing-library/dom"]
external _queryByDisplayValue:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByDisplayValueOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByDisplayValue";

[@bs.module "@testing-library/dom"]
external _queryAllByDisplayValue:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByDisplayValueOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByDisplayValue";

[@bs.module "@testing-library/dom"]
external _findByDisplayValue:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByDisplayValueOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByDisplayValue";

[@bs.module "@testing-library/dom"]
external _findAllByDisplayValue:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByDisplayValueOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByDisplayValue";

module type ByDisplayValue = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByDisplayValueOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByDisplayValue) => {
  let byDisplayValue =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Str(text), ByDisplayValueOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byDisplayValueRe =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Re(re), ByDisplayValueOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byDisplayValueFn =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Fn(fn), ByDisplayValueOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByDisplayValue;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByDisplayValue = Get.byDisplayValue;
let getByDisplayValueRe = Get.byDisplayValueRe;
let getByDisplayValueFn = Get.byDisplayValueFn;

module GetAll =
  Make({
    let fn = _getAllByDisplayValue;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByDisplayValue = GetAll.byDisplayValue;
let getAllByDisplayValueRe = GetAll.byDisplayValueRe;
let getAllByDisplayValueFn = GetAll.byDisplayValueFn;

module Query =
  Make({
    let fn = _queryByDisplayValue;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByDisplayValue = Query.byDisplayValue;
let queryByDisplayValueRe = Query.byDisplayValueRe;
let queryByDisplayValueFn = Query.byDisplayValueFn;

module QueryAll =
  Make({
    let fn = _queryAllByDisplayValue;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByDisplayValue = QueryAll.byDisplayValue;
let queryAllByDisplayValueRe = QueryAll.byDisplayValueRe;
let queryAllByDisplayValueFn = QueryAll.byDisplayValueFn;

module Find =
  Make({
    let fn = _findByDisplayValue;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByDisplayValue = Find.byDisplayValue;
let findByDisplayValueRe = Find.byDisplayValueRe;
let findByDisplayValueFn = Find.byDisplayValueFn;

module FindAll =
  Make({
    let fn = _findAllByDisplayValue;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByDisplayValue = FindAll.byDisplayValue;
let findAllByDisplayValueRe = FindAll.byDisplayValueRe;
let findAllByDisplayValueFn = FindAll.byDisplayValueFn;
