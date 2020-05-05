open Jest;
open Expect;
open ReactHooksTestingLibrary;

test("should render hook", () =>
  renderHook(() => React.useState(_ => 0))
  |> React.Ref.current
  |> fst
  |> expect
  |> toBe(0)
);

test("hooks should be updatable with act", () => {
  let result = renderHook(() => React.useState(_ => 0));

  let (_, setCount) = result->React.Ref.current;
  act(() => setCount(_ => 1));

  let (count, _) = result->React.Ref.current;
  expect(count) |> toBe(1);
});

test("hooks should render with initial props", () => {
  let result =
    renderHook(
      initialCount => React.useState(_ => initialCount),
      ~initialProps=42,
    );

  let (count, _) = result->React.Ref.current;
  expect(count) |> toBe(42);
});
