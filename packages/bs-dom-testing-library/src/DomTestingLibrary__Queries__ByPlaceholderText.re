module ByPlaceholderTextOptions = {
  type t = {
    exact: option(bool),
    normalizer: option(string => string),
  };

  let make = (~exact, ~normalizer) => {exact, normalizer};
};

[@bs.module "@testing-library/dom"]
external _getByPlaceholderText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByPlaceholderTextOptions.t
  ) =>
  Dom.element =
  "getByPlaceholderText";

[@bs.module "@testing-library/dom"]
external _getAllByPlaceholderText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByPlaceholderTextOptions.t
  ) =>
  array(Dom.element) =
  "getAllByPlaceholderText";

[@bs.module "@testing-library/dom"]
external _queryByPlaceholderText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByPlaceholderTextOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByPlaceholderText";

[@bs.module "@testing-library/dom"]
external _queryAllByPlaceholderText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByPlaceholderTextOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByPlaceholderText";

[@bs.module "@testing-library/dom"]
external _findByPlaceholderText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByPlaceholderTextOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByPlaceholderText";

[@bs.module "@testing-library/dom"]
external _findAllByPlaceholderText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByPlaceholderTextOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByPlaceholderText";

module type ByPlaceholderText = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByPlaceholderTextOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByPlaceholderText) => {
  let byPlaceholderText =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Str(text), ByPlaceholderTextOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byPlaceholderTextRe =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Re(re), ByPlaceholderTextOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byPlaceholderTextFn =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Fn(fn), ByPlaceholderTextOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByPlaceholderText;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByPlaceholderText = Get.byPlaceholderText;
let getByPlaceholderTextRe = Get.byPlaceholderTextRe;
let getByPlaceholderTextFn = Get.byPlaceholderTextFn;

module GetAll =
  Make({
    let fn = _getAllByPlaceholderText;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByPlaceholderText = GetAll.byPlaceholderText;
let getAllByPlaceholderTextRe = GetAll.byPlaceholderTextRe;
let getAllByPlaceholderTextFn = GetAll.byPlaceholderTextFn;

module Query =
  Make({
    let fn = _queryByPlaceholderText;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByPlaceholderText = Query.byPlaceholderText;
let queryByPlaceholderTextRe = Query.byPlaceholderTextRe;
let queryByPlaceholderTextFn = Query.byPlaceholderTextFn;

module QueryAll =
  Make({
    let fn = _queryAllByPlaceholderText;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByPlaceholderText = QueryAll.byPlaceholderText;
let queryAllByPlaceholderTextRe = QueryAll.byPlaceholderTextRe;
let queryAllByPlaceholderTextFn = QueryAll.byPlaceholderTextFn;

module Find =
  Make({
    let fn = _findByPlaceholderText;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByPlaceholderText = Find.byPlaceholderText;
let findByPlaceholderTextRe = Find.byPlaceholderTextRe;
let findByPlaceholderTextFn = Find.byPlaceholderTextFn;

module FindAll =
  Make({
    let fn = _findAllByPlaceholderText;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByPlaceholderText = FindAll.byPlaceholderText;
let findAllByPlaceholderTextRe = FindAll.byPlaceholderTextRe;
let findAllByPlaceholderTextFn = FindAll.byPlaceholderTextFn;
