let getByTitle:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Dom.element;
let getByTitleRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Dom.element;
let getByTitleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByTitle:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  array(Dom.element);
let getAllByTitleRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  array(Dom.element);
let getAllByTitleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByTitle:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(Dom.element);
let queryByTitleRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(Dom.element);
let queryByTitleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByTitle:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(array(Dom.element));
let queryAllByTitleRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(array(Dom.element));
let queryAllByTitleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByTitle:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByTitleRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByTitleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByTitle:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByTitleRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByTitleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
