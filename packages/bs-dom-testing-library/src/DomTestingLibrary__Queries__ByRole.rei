let getByRole:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    string,
    Dom.element
  ) =>
  Dom.element;
let getByRoleRe:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    Js.Re.t,
    Dom.element
  ) =>
  Dom.element;
let getByRoleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Dom.element;

let getAllByRole:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    string,
    Dom.element
  ) =>
  array(Dom.element);
let getAllByRoleRe:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    Js.Re.t,
    Dom.element
  ) =>
  array(Dom.element);
let getAllByRoleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  array(Dom.element);

let queryByRole:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    string,
    Dom.element
  ) =>
  option(Dom.element);
let queryByRoleRe:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    Js.Re.t,
    Dom.element
  ) =>
  option(Dom.element);
let queryByRoleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(Dom.element);

let queryAllByRole:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    string,
    Dom.element
  ) =>
  option(array(Dom.element));
let queryAllByRoleRe:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    Js.Re.t,
    Dom.element
  ) =>
  option(array(Dom.element));
let queryAllByRoleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  option(array(Dom.element));

let findByRole:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    string,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);
let findByRoleRe:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    Js.Re.t,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);
let findByRoleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(Dom.element);

let findAllByRole:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    string,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
let findAllByRoleRe:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    Js.Re.t,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
let findAllByRoleFn:
  (
    ~exact: bool=?,
    ~normalizer: string => string=?,
    ~hidden: bool=?,
    ~name: [
             | `str(string)
             | `re(Js.Re.t)
             | `fn((string, Dom.element) => bool)
           ]
             =?,
    (string, Dom.element) => bool,
    Dom.element
  ) =>
  Js.Promise.t(array(Dom.element));
