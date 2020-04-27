let getByTestId:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Dom.element;
let getByTestIdRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Dom.element;
let getByTestIdFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByTestId:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  array(Dom.element);
let getAllByTestIdRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  array(Dom.element);
let getAllByTestIdFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByTestId:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(Dom.element);
let queryByTestIdRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(Dom.element);
let queryByTestIdFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByTestId:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  option(array(Dom.element));
let queryAllByTestIdRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  option(array(Dom.element));
let queryAllByTestIdFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByTestId:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByTestIdRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(Dom.element);
let findByTestIdFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByTestId:
  (~exact: bool=?, ~normalizer: string => string=?, string, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByTestIdRe:
  (~exact: bool=?, ~normalizer: string => string=?, Js.Re.t, Dom.element) =>
  Js.Promise.t(array(Dom.element));
let findAllByTestIdFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
