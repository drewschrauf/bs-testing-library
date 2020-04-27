let getByText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    string,
    Dom.element
  ) =>
  Dom.element;
let getByTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    Js.Re.t,
    Dom.element
  ) =>
  Dom.element;
let getByTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    string,
    Dom.element
  ) =>
  array(Dom.element);
let getAllByTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    Js.Re.t,
    Dom.element
  ) =>
  array(Dom.element);
let getAllByTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    string,
    Dom.element
  ) =>
  option(Dom.element);
let queryByTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    Js.Re.t,
    Dom.element
  ) =>
  option(Dom.element);
let queryByTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    string,
    Dom.element
  ) =>
  option(array(Dom.element));
let queryAllByTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    Js.Re.t,
    Dom.element
  ) =>
  option(array(Dom.element));
let queryAllByTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    string,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);
let findByTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    Js.Re.t,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);
let findByTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    string,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
let findAllByTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    Js.Re.t,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
let findAllByTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~ignore: bool=?,
    ~ignoreTags: string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
