module TypeOptions = {
  type t = {
    allAtOnce: option(bool),
    delay: option(int),
  };

  let make = (~allAtOnce, ~delay) => {allAtOnce, delay};
};

module TabOptions = {
  type t = {
    shift: option(bool),
    focusTrap: option(Dom.element),
  };

  let make = (~shift, ~focusTrap) => {shift, focusTrap};
};

[@bs.module "@testing-library/user-event"]
external _click: Dom.element => unit = "click";

[@bs.module "@testing-library/user-event"]
external _dblClick: Dom.element => unit = "dblClick";

[@bs.module "@testing-library/user-event"]
external _type: (Dom.element, string, TypeOptions.t) => Js.Promise.t(unit) =
  "type";

[@bs.module "@testing-library/user-event"]
external _clear: Dom.element => unit = "clear";

[@bs.module "@testing-library/user-event"]
external _selectOptions:
  (Dom.element, [@bs.unwrap] [ | `str(string) | `array(array(string))]) =>
  unit =
  "selectOptions";

[@bs.module "@testing-library/user-event"]
external _tab: TabOptions.t => unit = "tab";

let click = (e: Dom.element): unit => _click(e);

let dblClick = (e: Dom.element): unit => _dblClick(e);

let type_ =
    (
      ~allAtOnce: option(bool)=?,
      ~delay: option(int)=?,
      t: string,
      e: Dom.element,
    )
    : Js.Promise.t(unit) =>
  _type(e, t, TypeOptions.make(~allAtOnce, ~delay))
  |> Js.Promise.then_(_ => Js.Promise.resolve());

let clear = (e: Dom.element): unit => _clear(e);

let selectOption = (o: string, e: Dom.element): unit =>
  _selectOptions(e, `str(o));

let selectOptions = (os: list(string), e: Dom.element): unit =>
  _selectOptions(e, `array(os->Array.of_list));

let tab =
    (~shift: option(bool)=?, ~focusTrap: option(Dom.element)=?, ()): unit =>
  _tab(TabOptions.make(~shift, ~focusTrap));
