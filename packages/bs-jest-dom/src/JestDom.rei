type partial('a) = [ | `Just('a) | `Not('a)];

let toBeDisabled: [< partial(Dom.element)] => Jest.assertion;

let toBeEnabled: [< partial(Dom.element)] => Jest.assertion;

let toBeEmpty: [< partial(Dom.element)] => Jest.assertion;

let toBeInTheDocument: [< partial(Dom.element)] => Jest.assertion;

let toBeInvalid: [< partial(Dom.element)] => Jest.assertion;

let toBeRequired: [< partial(Dom.element)] => Jest.assertion;

let toBeValid: [< partial(Dom.element)] => Jest.assertion;

let toBeVisible: [< partial(Dom.element)] => Jest.assertion;

let toContainElement:
  (Dom.element, [< partial(Dom.element)]) => Jest.assertion;

let toContainHTML: (string, [< partial(Dom.element)]) => Jest.assertion;

let toHaveAttribute:
  (~value: string=?, string, [< partial(Dom.element)]) => Jest.assertion;

let toHaveClass:
  (~exact: bool=?, string, [< partial(Dom.element)]) => Jest.assertion;

let toHaveClasses:
  (~exact: bool=?, list(string), [< partial(Dom.element)]) => Jest.assertion;

let toHaveFocus: [< partial(Dom.element)] => Jest.assertion;

let toHaveFormValues:
  (Js.t({..}), [< partial(Dom.element)]) => Jest.assertion;

let toHaveStyle: (string, [< partial(Dom.element)]) => Jest.assertion;

let toHaveStyles: (Js.t({..}), [< partial(Dom.element)]) => Jest.assertion;

let toHaveTextContent:
  (~normalizeWhitespace: bool=?, string, [< partial(Dom.element)]) =>
  Jest.assertion;

let toHaveTextContentRe:
  (~normalizeWhitespace: bool=?, Js.Re.t, [< partial(Dom.element)]) =>
  Jest.assertion;

let toHaveValue: (string, [< partial(Dom.element)]) => Jest.assertion;

let toHaveValueOfType:
  (
    [ | `str(string) | `array(array(string)) | `int(int) | `float(float)],
    [< partial(Dom.element)]
  ) =>
  Jest.assertion;

let toHaveDisplayValue: (string, [< partial(Dom.element)]) => Jest.assertion;

let toHaveDisplayValues:
  (list(string), [< partial(Dom.element)]) => Jest.assertion;

let toBeChecked: [< partial(Dom.element)] => Jest.assertion;
