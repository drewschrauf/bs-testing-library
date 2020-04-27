let getByPlaceholderText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Dom.element;
let getByPlaceholderTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Dom.element;
let getByPlaceholderTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByPlaceholderText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  array(Dom.element);
let getAllByPlaceholderTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  array(Dom.element);
let getAllByPlaceholderTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByPlaceholderText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(Dom.element);
let queryByPlaceholderTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(Dom.element);
let queryByPlaceholderTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByPlaceholderText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(array(Dom.element));
let queryAllByPlaceholderTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(array(Dom.element));
let queryAllByPlaceholderTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByPlaceholderText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByPlaceholderTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByPlaceholderTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByPlaceholderText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByPlaceholderTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByPlaceholderTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
