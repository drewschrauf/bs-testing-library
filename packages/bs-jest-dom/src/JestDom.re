[%bs.raw {| require("@testing-library/jest-dom/extend-expect") |}];

module HaveClassOptions = {
  type t = {exact: option(bool)};

  let make = (~exact) => {exact: exact};
};

module HaveTextContentOptions = {
  type t = {normalizeWhitespace: option(bool)};

  let make = (~normalizeWhitespace) => {
    normalizeWhitespace: normalizeWhitespace,
  };
};

type expect;
[@bs.val] external _expect: Dom.element => expect = "expect";
[@bs.get] external _not: expect => expect = "not";

[@bs.send.pipe: expect] external _toBeDisabled: unit => unit = "toBeDisabled";
[@bs.send.pipe: expect] external _toBeEnabled: unit => unit = "toBeEnabled";
[@bs.send.pipe: expect] external _toBeEmpty: unit => unit = "toBeEmpty";
[@bs.send.pipe: expect]
external _toBeInTheDocument: unit => unit = "toBeInTheDocument";
[@bs.send.pipe: expect] external _toBeInvalid: unit => unit = "toBeInvalid";
[@bs.send.pipe: expect] external _toBeRequired: unit => unit = "toBeRequired";
[@bs.send.pipe: expect] external _toBeValid: unit => unit = "toBeValid";
[@bs.send.pipe: expect] external _toBeVisible: unit => unit = "toBeVisible";
[@bs.send.pipe: expect]
external _toContainElement: Dom.element => unit = "toContainElement";
[@bs.send.pipe: expect]
external _toContainHTML: string => unit = "toContainHTML";
[@bs.send.pipe: expect]
external _toHaveAttribute: (string, Js.Undefined.t(string)) => unit =
  "toHaveAttribute";
[@bs.send.pipe: expect]
external _toHaveClass: (string, HaveClassOptions.t) => unit = "toHaveClass";
[@bs.send.pipe: expect] external _toHaveFocus: unit => unit = "toHaveFocus";
[@bs.send.pipe: expect]
external _toHaveFormValues: Js.t({..}) => unit = "toHaveFormValues";
[@bs.send.pipe: expect] external _toHaveStyle: string => unit = "toHaveStyle";
[@bs.send.pipe: expect]
external _toHaveTextContent:
  (
    [@bs.unwrap] [ | `Str(string) | `Re(Js.Re.t)],
    HaveTextContentOptions.t
  ) =>
  unit =
  "toHaveTextContent";
[@bs.send.pipe: expect] external _toHaveValue: string => unit = "toHaveValue";
[@bs.send.pipe: expect]
external _toHaveDisplayValue: string => unit = "toHaveDisplayValue";
[@bs.send.pipe: expect] external _toBeChecked: unit => unit = "toBeChecked";

type partial('a) = [ | `Just('a) | `Not('a)];

let mapMod = (f, a) =>
  switch (a) {
  | `Just(expected) => `Just(f(expected))
  | `Not(expected) => `Not(f(expected))
  };

type assertion =
  | ToBeDisabled(partial(Dom.element))
  | ToBeEnabled(partial(Dom.element))
  | ToBeEmpty(partial(Dom.element))
  | ToBeInTheDocument(partial(Dom.element))
  | ToBeInvalid(partial(Dom.element))
  | ToBeRequired(partial(Dom.element))
  | ToBeValid(partial(Dom.element))
  | ToBeVisible(partial(Dom.element))
  | ToContainElement(partial((Dom.element, Dom.element)))
  | ToContainHTML(partial((Dom.element, string)))
  | ToHaveAttribute(partial((Dom.element, string, option(string))))
  | ToHaveClass(partial((Dom.element, string, HaveClassOptions.t)))
  | ToHaveFocus(partial(Dom.element))
  | ToHaveFormValues(partial((Dom.element, Js.t({..})))): assertion
  | ToHaveStyle(partial((Dom.element, string)))
  | ToHaveTextContent(
      partial(
        (
          Dom.element,
          [ | `Str(string) | `Re(Js.Re.t)],
          HaveTextContentOptions.t,
        ),
      ),
    )
  | ToHaveValue(partial((Dom.element, string)))
  | ToHaveDisplayValue(partial((Dom.element, string)))
  | ToBeChecked(partial(Dom.element));

let affirm = e => {
  switch (e) {
  | ToBeDisabled(`Just(e)) => e |> _expect |> _toBeDisabled()
  | ToBeDisabled(`Not(e)) => e |> _expect |> _not |> _toBeDisabled()
  | ToBeEnabled(`Just(e)) => e |> _expect |> _toBeEnabled()
  | ToBeEnabled(`Not(e)) => e |> _expect |> _not |> _toBeEnabled()
  | ToBeEmpty(`Just(e)) => e |> _expect |> _toBeEmpty()
  | ToBeEmpty(`Not(e)) => e |> _expect |> _not |> _toBeEmpty()
  | ToBeInTheDocument(`Just(e)) => e |> _expect |> _toBeInTheDocument()
  | ToBeInTheDocument(`Not(e)) => e |> _expect |> _not |> _toBeInTheDocument()
  | ToBeInvalid(`Just(e)) => e |> _expect |> _toBeInvalid()
  | ToBeInvalid(`Not(e)) => e |> _expect |> _not |> _toBeInvalid()
  | ToBeRequired(`Just(e)) => e |> _expect |> _toBeRequired()
  | ToBeRequired(`Not(e)) => e |> _expect |> _not |> _toBeRequired()
  | ToBeValid(`Just(e)) => e |> _expect |> _toBeValid()
  | ToBeValid(`Not(e)) => e |> _expect |> _not |> _toBeValid()
  | ToBeVisible(`Just(e)) => e |> _expect |> _toBeVisible()
  | ToBeVisible(`Not(e)) => e |> _expect |> _not |> _toBeVisible()
  | ToContainElement(`Just(e, c)) => e |> _expect |> _toContainElement(c)
  | ToContainElement(`Not(e, c)) =>
    e |> _expect |> _not |> _toContainElement(c)
  | ToContainHTML(`Just(e, h)) => e |> _expect |> _toContainHTML(h)
  | ToContainHTML(`Not(e, h)) => e |> _expect |> _not |> _toContainHTML(h)
  | ToHaveAttribute(`Just(e, a, v)) =>
    e |> _expect |> _toHaveAttribute(a, v->Js.Undefined.fromOption)
  | ToHaveAttribute(`Not(e, a, v)) =>
    e |> _expect |> _not |> _toHaveAttribute(a, v->Js.Undefined.fromOption)
  | ToHaveClass(`Just(e, c, o)) => e |> _expect |> _toHaveClass(c, o)
  | ToHaveClass(`Not(e, c, o)) => e |> _expect |> _not |> _toHaveClass(c, o)
  | ToHaveFocus(`Just(e)) => e |> _expect |> _toHaveFocus()
  | ToHaveFocus(`Not(e)) => e |> _expect |> _not |> _toHaveFocus()
  | ToHaveFormValues(`Just(e, v)) => e |> _expect |> _toHaveFormValues(v)
  | ToHaveFormValues(`Not(e, v)) =>
    e |> _expect |> _not |> _toHaveFormValues(v)
  | ToHaveStyle(`Just(e, s)) => e |> _expect |> _toHaveStyle(s)
  | ToHaveStyle(`Not(e, s)) => e |> _expect |> _not |> _toHaveStyle(s)
  | ToHaveTextContent(`Just(e, s, o)) =>
    e |> _expect |> _toHaveTextContent(s, o)
  | ToHaveTextContent(`Not(e, s, o)) =>
    e |> _expect |> _not |> _toHaveTextContent(s, o)
  | ToHaveValue(`Just(e, v)) => e |> _expect |> _toHaveValue(v)
  | ToHaveValue(`Not(e, v)) => e |> _expect |> _not |> _toHaveValue(v)
  | ToHaveDisplayValue(`Just(e, v)) =>
    e |> _expect |> _toHaveDisplayValue(v)
  | ToHaveDisplayValue(`Not(e, v)) =>
    e |> _expect |> _not |> _toHaveDisplayValue(v)
  | ToBeChecked(`Just(e)) => e |> _expect |> _toBeChecked()
  | ToBeChecked(`Not(e)) => e |> _expect |> _not |> _toBeChecked()
  };
  Jest.pass;
};

let toBeDisabled = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeDisabled(mapMod(exp => exp, p))->affirm;
};

let toBeEnabled = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeEnabled(mapMod(exp => exp, p))->affirm;
};

let toBeEmpty = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeEmpty(mapMod(exp => exp, p))->affirm;
};

let toBeInTheDocument = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeInTheDocument(mapMod(exp => exp, p))->affirm;
};

let toBeInvalid = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeInvalid(mapMod(exp => exp, p))->affirm;
};

let toBeRequired = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeRequired(mapMod(exp => exp, p))->affirm;
};

let toBeValid = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeValid(mapMod(exp => exp, p))->affirm;
};

let toBeVisible = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeVisible(mapMod(exp => exp, p))->affirm;
};

let toContainElement =
    (e: Dom.element, p: [< partial(Dom.element)]): Jest.assertion => {
  ToContainElement(mapMod(exp => (exp, e), p))->affirm;
};

let toContainHTML =
    (html: string, p: [< partial(Dom.element)]): Jest.assertion => {
  ToContainHTML(mapMod(exp => (exp, html), p))->affirm;
};

let toHaveAttribute =
    (
      ~value: option(string)=?,
      attribute: string,
      p: [< partial(Dom.element)],
    )
    : Jest.assertion => {
  ToHaveAttribute(mapMod(exp => (exp, attribute, value), p))->affirm;
};

let toHaveClass =
    (~exact: option(bool)=?, c: string, p: [< partial(Dom.element)])
    : Jest.assertion => {
  ToHaveClass(mapMod(exp => (exp, c, HaveClassOptions.make(~exact)), p))
  ->affirm;
};

let toHaveFocus = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveFocus(mapMod(exp => exp, p))->affirm;
};

let toHaveFormValues =
    (v: Js.t({..}), p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveFormValues(mapMod(exp => (exp, v), p))->affirm;
};

let toHaveStyle = (s: string, p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveStyle(mapMod(exp => (exp, s), p))->affirm;
};

let toHaveTextContent =
    (
      ~normalizeWhitespace: option(bool)=?,
      str: string,
      p: [< partial(Dom.element)],
    )
    : Jest.assertion => {
  ToHaveTextContent(
    mapMod(
      exp =>
        (exp, `Str(str), HaveTextContentOptions.make(~normalizeWhitespace)),
      p,
    ),
  )
  ->affirm;
};

let toHaveTextContentRe =
    (
      ~normalizeWhitespace: option(bool)=?,
      re: Js.Re.t,
      p: [< partial(Dom.element)],
    )
    : Jest.assertion => {
  ToHaveTextContent(
    mapMod(
      exp =>
        (exp, `Re(re), HaveTextContentOptions.make(~normalizeWhitespace)),
      p,
    ),
  )
  ->affirm;
};

let toHaveValue = (v: string, p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveValue(mapMod(exp => (exp, v), p))->affirm;
};

let toHaveDisplayValue =
    (v: string, p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveDisplayValue(mapMod(exp => (exp, v), p))->affirm;
};

let toBeChecked = (p: [< partial(Dom.element)]): Jest.assertion => {
  ToBeChecked(mapMod(exp => exp, p))->affirm;
};
