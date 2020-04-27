module ByLabelTextOptions = {
  type t = {
    selector: option(string),
    exact: option(bool),
    normalizer: option(string => string),
  };

  let make = (~selector, ~exact, ~normalizer) => {
    selector,
    exact,
    normalizer,
  };
};

[@bs.module "@testing-library/dom"]
external _getByLabelText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByLabelTextOptions.t
  ) =>
  Dom.element =
  "getByLabelText";

[@bs.module "@testing-library/dom"]
external _getAllByLabelText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByLabelTextOptions.t
  ) =>
  array(Dom.element) =
  "getAllByLabelText";

[@bs.module "@testing-library/dom"]
external _queryByLabelText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByLabelTextOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByLabelText";

[@bs.module "@testing-library/dom"]
external _queryAllByLabelText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByLabelTextOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByLabelText";

[@bs.module "@testing-library/dom"]
external _findByLabelText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByLabelTextOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByLabelText";

[@bs.module "@testing-library/dom"]
external _findAllByLabelText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByLabelTextOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByLabelText";

module type ByLabelText = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByLabelTextOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByLabelText) => {
  let byLabelText =
      (
        ~selector: option(string)=?,
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Str(text),
      ByLabelTextOptions.make(~selector, ~exact, ~normalizer),
    )
    ->T.mapReturnType;

  let byLabelTextRe =
      (
        ~selector: option(string)=?,
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Re(re),
      ByLabelTextOptions.make(~selector, ~exact, ~normalizer),
    )
    ->T.mapReturnType;

  let byLabelTextFn =
      (
        ~selector: option(string)=?,
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Fn(fn),
      ByLabelTextOptions.make(~selector, ~exact, ~normalizer),
    )
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByLabelText;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByLabelText = Get.byLabelText;
let getByLabelTextRe = Get.byLabelTextRe;
let getByLabelTextFn = Get.byLabelTextFn;

module GetAll =
  Make({
    let fn = _getAllByLabelText;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByLabelText = GetAll.byLabelText;
let getAllByLabelTextRe = GetAll.byLabelTextRe;
let getAllByLabelTextFn = GetAll.byLabelTextFn;

module Query =
  Make({
    let fn = _queryByLabelText;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByLabelText = Query.byLabelText;
let queryByLabelTextRe = Query.byLabelTextRe;
let queryByLabelTextFn = Query.byLabelTextFn;

module QueryAll =
  Make({
    let fn = _queryAllByLabelText;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByLabelText = QueryAll.byLabelText;
let queryAllByLabelTextRe = QueryAll.byLabelTextRe;
let queryAllByLabelTextFn = QueryAll.byLabelTextFn;

module Find =
  Make({
    let fn = _findByLabelText;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByLabelText = Find.byLabelText;
let findByLabelTextRe = Find.byLabelTextRe;
let findByLabelTextFn = Find.byLabelTextFn;

module FindAll =
  Make({
    let fn = _findAllByLabelText;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByLabelText = FindAll.byLabelText;
let findAllByLabelTextRe = FindAll.byLabelTextRe;
let findAllByLabelTextFn = FindAll.byLabelTextFn;
