type renderResult('a) = {result: React.Ref.t('a)};
type renderHookOptions('p) = {initialProps: option('p)};

[@bs.module "@testing-library/react-hooks"]
external _renderHook: ('p => 'a, renderHookOptions('p)) => renderResult('a) =
  "renderHook";

[@bs.module "@testing-library/react-hooks"]
external act: (unit => unit) => unit = "act";

let renderHook =
    (~initialProps: option('p)=?, cb: 'p => 'a): React.Ref.t('a) =>
  _renderHook(cb, {initialProps: initialProps}).result;
