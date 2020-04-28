[%bs.raw {| require("@testing-library/jest-dom/extend-expect") |}];

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
external _toHaveTextContent:
  ([@bs.unwrap] [ | `Str(string) | `Re(Js.Re.t)]) => unit =
  "toBeInTheDocument";

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
  | ToHaveTextContent(
      partial((Dom.element, [ | `Str(string) | `Re(Js.Re.t)])),
    );

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
  | ToHaveTextContent(`Just(e, s)) => e |> _expect |> _toHaveTextContent(s)
  | ToHaveTextContent(`Not(e, s)) =>
    e |> _expect |> _not |> _toHaveTextContent(s)
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

let toHaveTextContent =
    (str: string, p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveTextContent(mapMod(exp => (exp, `Str(str)), p))->affirm;
};

let toHaveTextContentRe =
    (re: Js.Re.t, p: [< partial(Dom.element)]): Jest.assertion => {
  ToHaveTextContent(mapMod(exp => (exp, `Re(re)), p))->affirm;
};
