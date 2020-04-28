open Jest;
open Expect;

open JestDom;

let el: Dom.element = [%bs.raw
  {|
    (function() {
      var el = document.createElement("div");
      el.innerHTML = "Hello";
      document.body.appendChild(el);
      return el;
    })()
  |}
];

test("toBeInTheDocument", () => {
  el |> expect |> toBeInTheDocument
});

test("toHaveTextContent", () => {
  el |> expect |> toHaveTextContent("Hello")
});
