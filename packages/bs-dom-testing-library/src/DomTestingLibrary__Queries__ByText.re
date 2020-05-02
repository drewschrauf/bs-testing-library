module ByTextOptions = {
  module StringOrBool = {
    [@unboxed]
    type t =
      | Any('a): t;
    let makeString = s => Any(s);
    let makeBool = b => Any(b);
  };

  type t = {
    selector: option(string),
    exact: option(bool),
    ignore: option(StringOrBool.t),
    normalizer: option(string => string),
  };

  let make = (~selector, ~exact, ~normalizer, ~ignore) => {
    selector,
    exact,
    normalizer,
    ignore:
      switch (ignore) {
      | Some(`disable) => Some(StringOrBool.makeBool(false))
      | Some(`selector(s)) => Some(StringOrBool.makeString(s))
      | None => None
      },
  };
};

[@bs.module "@testing-library/dom"]
external _getByText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTextOptions.t
  ) =>
  Dom.element =
  "getByText";

[@bs.module "@testing-library/dom"]
external _getAllByText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTextOptions.t
  ) =>
  array(Dom.element) =
  "getAllByText";

[@bs.module "@testing-library/dom"]
external _queryByText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTextOptions.t
  ) =>
  Js.Nullable.t(Dom.element) =
  "queryByText";

[@bs.module "@testing-library/dom"]
external _queryAllByText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTextOptions.t
  ) =>
  Js.Nullable.t(array(Dom.element)) =
  "queryAllByText";

[@bs.module "@testing-library/dom"]
external _findByText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTextOptions.t
  ) =>
  Js.Promise.t(Dom.element) =
  "findByText";

[@bs.module "@testing-library/dom"]
external _findAllByText:
  (
    Dom.element,
    [@bs.unwrap] [
      | `Str(string)
      | `Re(Js.Re.t)
      | `Fn((string, Dom.element) => bool)
    ],
    ByTextOptions.t
  ) =>
  Js.Promise.t(array(Dom.element)) =
  "findAllByText";

module type ByText = {
  type returnType;
  type externalReturnType;
  let mapReturnType: externalReturnType => returnType;
  let fn:
    (
      Dom.element,
      [ | `Str(string) | `Re(Js.Re.t) | `Fn((string, Dom.element) => bool)],
      ByTextOptions.t
    ) =>
    externalReturnType;
};

module Make = (T: ByText) => {
  let byText =
      (
        ~selector: option(string)=?,
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        ~ignore: option([ | `disable | `selector(string)])=?,
        text: string,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Str(text),
      ByTextOptions.make(~selector, ~exact, ~normalizer, ~ignore),
    )
    ->T.mapReturnType;

  let byTextRe =
      (
        ~selector: option(string)=?,
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        ~ignore: option([ | `disable | `selector(string)])=?,
        re: Js.Re.t,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Re(re),
      ByTextOptions.make(~selector, ~exact, ~normalizer, ~ignore),
    )
    ->T.mapReturnType;

  let byTextFn =
      (
        ~selector: option(string)=?,
        ~exact: option(bool)=?,
        ~normalizer: option(string => string)=?,
        ~ignore: option([ | `disable | `selector(string)])=?,
        fn: (string, Dom.element) => bool,
        el: Dom.element,
      )
      : T.returnType =>
    T.fn(
      el,
      `Fn(fn),
      ByTextOptions.make(~selector, ~exact, ~normalizer, ~ignore),
    )
    ->T.mapReturnType;
};

module Get =
  Make({
    let fn = _getByText;
    type returnType = Dom.element;
    type externalReturnType = Dom.element;
    let mapReturnType = a => a;
  });
let getByText = Get.byText;
let getByTextRe = Get.byTextRe;
let getByTextFn = Get.byTextFn;

module GetAll =
  Make({
    let fn = _getAllByText;
    type returnType = array(Dom.element);
    type externalReturnType = array(Dom.element);
    let mapReturnType = a => a;
  });
let getAllByText = GetAll.byText;
let getAllByTextRe = GetAll.byTextRe;
let getAllByTextFn = GetAll.byTextFn;

module Query =
  Make({
    let fn = _queryByText;
    type returnType = option(Dom.element);
    type externalReturnType = Js.Nullable.t(Dom.element);
    let mapReturnType = Js.Nullable.toOption;
  });
let queryByText = Query.byText;
let queryByTextRe = Query.byTextRe;
let queryByTextFn = Query.byTextFn;

module QueryAll =
  Make({
    let fn = _queryAllByText;
    type returnType = option(array(Dom.element));
    type externalReturnType = Js.Nullable.t(array(Dom.element));
    let mapReturnType = Js.Nullable.toOption;
  });
let queryAllByText = QueryAll.byText;
let queryAllByTextRe = QueryAll.byTextRe;
let queryAllByTextFn = QueryAll.byTextFn;

module Find =
  Make({
    let fn = _findByText;
    type returnType = Js.Promise.t(Dom.element);
    type externalReturnType = Js.Promise.t(Dom.element);
    let mapReturnType = a => a;
  });
let findByText = Find.byText;
let findByTextRe = Find.byTextRe;
let findByTextFn = Find.byTextFn;

module FindAll =
  Make({
    let fn = _findAllByText;
    type returnType = Js.Promise.t(array(Dom.element));
    type externalReturnType = Js.Promise.t(array(Dom.element));
    let mapReturnType = a => a;
  });
let findAllByText = FindAll.byText;
let findAllByTextRe = FindAll.byTextRe;
let findAllByTextFn = FindAll.byTextFn;
