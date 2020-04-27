let getByDisplayValue:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Dom.element;
let getByDisplayValueRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Dom.element;
let getByDisplayValueFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByDisplayValue:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  array(Dom.element);
let getAllByDisplayValueRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  array(Dom.element);
let getAllByDisplayValueFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByDisplayValue:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(Dom.element);
let queryByDisplayValueRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(Dom.element);
let queryByDisplayValueFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByDisplayValue:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(array(Dom.element));
let queryAllByDisplayValueRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(array(Dom.element));
let queryAllByDisplayValueFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByDisplayValue:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByDisplayValueRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByDisplayValueFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByDisplayValue:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByDisplayValueRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByDisplayValueFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
