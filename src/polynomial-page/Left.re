
[@react.component]
let make = (~state: Model.State.t) => {

  let dimensions = state.dimensions;
  let variables_notation = state.variables_notation;

  let dependent_variable =
    switch (variables_notation) {
    | Pedantic => "y"
    | Traditional => Char.escaped(Constants.variableNames.[dimensions])
    };

  let letters = n =>
    <> {
        Array.init(n, i =>
         <span key={i -> string_of_int}>
           {
             let itsLetter = String.make(1, Constants.variableNames.[i]);
             
             itsLetter
             ++ (i < dimensions - 1 ? " , " : "")
             |> ReasonReact.string;
           }
         </span>
        ) |> ReasonReact.array
      }
    </>;

  let subindicatedXs = n =>
    <>
      {Array.init(n, i =>
         <span key={i -> string_of_int}>
           "x" -> ReasonReact.string
           <sub> {(i + 1) -> string_of_int -> ReasonReact.string} </sub>
           (i < dimensions - 1 ? " , " : "") -> ReasonReact.string
         </span>
       )
       |> ReasonReact.array}
    </>;

  let independentVariables = <>
    {switch (variables_notation) {
      | Pedantic    => subindicatedXs(dimensions)
      | Traditional => letters(dimensions)
      }}
  </>;

  <>
    <span className="surly"> dependent_variable->ReasonReact.string </span>
    <span className="surly"> " = "->ReasonReact.string </span>
    <span className="surly">
      <span className="half-surly"> "f("->ReasonReact.string </span>
      <span>{independentVariables}</span>
      <span className="surly-half"> ")" -> ReasonReact.string </span>
    </span>
    <span className="surly"> ":" -> ReasonReact.string </span>
    <span className="surly">
      {js|ℝ|js} -> ReasonReact.string // "ℝ"
      {dimensions > 1 ? <sup>{dimensions -> string_of_int -> ReasonReact.string}</sup> : "" -> ReasonReact.string}
      {js|￫|js} -> ReasonReact.string // "￫"
      {js|ℝ|js} -> ReasonReact.string // "ℝ"
    </span>
    <span className="surly">{ReasonReact.string(" = ")}</span>
  </>;

};
