let getByAltText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Dom.element;
let getByAltTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Dom.element;
let getByAltTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByAltText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  array(Dom.element);
let getAllByAltTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  array(Dom.element);
let getAllByAltTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByAltText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(Dom.element);
let queryByAltTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(Dom.element);
let queryByAltTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByAltText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(array(Dom.element));
let queryAllByAltTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(array(Dom.element));
let queryAllByAltTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByAltText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByAltTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByAltTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByAltText:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByAltTextRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByAltTextFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
