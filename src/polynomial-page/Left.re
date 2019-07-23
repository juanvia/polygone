
[@react.component]
let make = (~state: Model.State.t) => {

  let dimensions         = state.dimensions
  let variables_notation = state.variables_notation
  let letter_from_index  = i => Char.escaped(Constants.variableNames.[i])
  let dependent_variable = switch (variables_notation) { | Pedantic => "y" | Traditional => dimensions |> letter_from_index }

  let independent_variables = n => <>{

    let span_from_index = i => {

      let key           = i |> string_of_int;
      let the_letter    = i |> letter_from_index |> ReasonReact.string
      let the_xsub      = <> {"x" -> ReasonReact.string } <sub> { (i + 1) -> string_of_int -> ReasonReact.string} </sub></>
      let the_separator = (i < dimensions - 1 ? " , " : "")            |> ReasonReact.string
      let the_variable  = <> { switch (variables_notation) { | Traditional => the_letter | Pedantic => the_xsub } } </>;
      
      <span key> the_variable the_separator </span>;
    };

    Array.init(n, span_from_index) |> ReasonReact.array;

  }</>;

  module Cacho   = {[@react.component] let make = (~children) => <span className="surly">      children </span>}; 
  module Cachito = {[@react.component] let make = (~children) => <span className="half-surly"> children </span>}; 
  module Tocachi = {[@react.component] let make = (~children) => <span className="surly-half"> children </span>}; 

  <>
    <Cacho> dependent_variable -> ReasonReact.string </Cacho>
    <Cacho> " = " -> ReasonReact.string </Cacho>
    <Cacho>
      <Cachito> "f(" -> ReasonReact.string </Cachito> 
        {independent_variables(dimensions)} 
      <Tocachi> ")" -> ReasonReact.string </Tocachi>
    </Cacho>
    <Cacho> ":" -> ReasonReact.string </Cacho>
    <Cacho>
      {js|ℝ|js} -> ReasonReact.string // "ℝ"
      {dimensions > 1 ? <sup>{dimensions -> string_of_int -> ReasonReact.string}</sup> : "" -> ReasonReact.string}
      {js|￫|js} -> ReasonReact.string // "￫"
      {js|ℝ|js} -> ReasonReact.string // "ℝ"
    </Cacho>
    <Cacho>{ReasonReact.string(" = ")}</Cacho>
  </>;

};
