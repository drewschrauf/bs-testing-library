module ByAltTextOptions = {
  type t = {
    exact: option(bool),
    normalizer: option(string => string),
  };

  let make = (~exact, ~normalizer) => {exact, normalizer};
};

[@bs.module "@testing-library/dom"]
external _getByAltText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByAltTextOptions.t
  ) =>
  Dom.element =
  "getByAltText";

[@bs.module "@testing-library/dom"]
external _getAllByAltText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByAltTextOptions.t
  ) =>
  array(Dom.element) =
  "getAllByAltText";

[@bs.module "@testing-library/dom"]
external _queryByAltText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByAltTextOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByAltText";

[@bs.module "@testing-library/dom"]
external _queryAllByAltText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByAltTextOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByAltText";

[@bs.module "@testing-library/dom"]
external _findByAltText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByAltTextOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByAltText";

[@bs.module "@testing-library/dom"]
external _findAllByAltText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByAltTextOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByAltText";

module type ByAltText = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByAltTextOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByAltText) => {
  let byAltText =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Str(text), ByAltTextOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byAltTextRe =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Re(re), ByAltTextOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;

  let byAltTextFn =
      (
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(el, `Fn(fn), ByAltTextOptions.make(~exact, ~normalizer))
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByAltText;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByAltText = Get.byAltText;
let getByAltTextRe = Get.byAltTextRe;
let getByAltTextFn = Get.byAltTextFn;

module GetAll =
  Make({
    let fn = _getAllByAltText;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByAltText = GetAll.byAltText;
let getAllByAltTextRe = GetAll.byAltTextRe;
let getAllByAltTextFn = GetAll.byAltTextFn;

module Query =
  Make({
    let fn = _queryByAltText;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByAltText = Query.byAltText;
let queryByAltTextRe = Query.byAltTextRe;
let queryByAltTextFn = Query.byAltTextFn;

module QueryAll =
  Make({
    let fn = _queryAllByAltText;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByAltText = QueryAll.byAltText;
let queryAllByAltTextRe = QueryAll.byAltTextRe;
let queryAllByAltTextFn = QueryAll.byAltTextFn;

module Find =
  Make({
    let fn = _findByAltText;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByAltText = Find.byAltText;
let findByAltTextRe = Find.byAltTextRe;
let findByAltTextFn = Find.byAltTextFn;

module FindAll =
  Make({
    let fn = _findAllByAltText;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByAltText = FindAll.byAltText;
let findAllByAltTextRe = FindAll.byAltTextRe;
let findAllByAltTextFn = FindAll.byAltTextFn;
