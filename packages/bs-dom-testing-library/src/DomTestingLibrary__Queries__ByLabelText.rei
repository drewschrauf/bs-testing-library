let getByLabelText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    string,
    Dom.element
  ) =>
  Dom.element;
let getByLabelTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    Js.Re.t,
    Dom.element
  ) =>
  Dom.element;
let getByLabelTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByLabelText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    string,
    Dom.element
  ) =>
  array(Dom.element);
let getAllByLabelTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    Js.Re.t,
    Dom.element
  ) =>
  array(Dom.element);
let getAllByLabelTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByLabelText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    string,
    Dom.element
  ) =>
  option(Dom.element);
let queryByLabelTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    Js.Re.t,
    Dom.element
  ) =>
  option(Dom.element);
let queryByLabelTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByLabelText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    string,
    Dom.element
  ) =>
  option(array(Dom.element));
let queryAllByLabelTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    Js.Re.t,
    Dom.element
  ) =>
  option(array(Dom.element));
let queryAllByLabelTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByLabelText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    string,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);
let findByLabelTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    Js.Re.t,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);
let findByLabelTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByLabelText:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    string,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
let findAllByLabelTextRe:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    Js.Re.t,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
let findAllByLabelTextFn:
  (
    ~selector: string=?,
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
