type screen = {container: Dom.element};

[@bs.module "@testing-library/dom"] external _screen: screen = "screen";

let screen = _screen.container;
