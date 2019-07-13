  /*
       <span>
         <span className="surly"> {dependentVariable} </span>
         <span className="surly">ReasonReact.string(" = ")</span>
         <span className="surly">
           <span className="half-surly">ReasonReact.string("f")(</span>
           <span>{independentVariables}</span>
           <span className="surly-half"></span>
           <span>)<span>
         </span>
         <span className="surly">ReasonReact.string(":")</span>
         <span className="surly">
           {ReasonReact.string("ℝ")}
           {superIndex}
           {ReasonReact.string("￫")}
           {ReasonReact.string("ℝ")}
         </span>
         <span className="surly">{ReasonReact.string(" = ")}</span>
       </span>;


   */
   [@react.component]
  let make = (~dimensions: int, variablesNotation: Model.Polynomial.flavor) => {
    let _dependentVariable =
      switch (variablesNotation) {
      | Pedantic    => "y"
      | Traditional => Char.escaped(Constants.variablesNames.[dimensions])
      };

    let _independentVariables =
      switch (variablesNotation) {
      | Pedantic =>
        Array.init(dimensions, i =>
          <span key={string_of_int(i)}>
            {ReasonReact.string("x")}
            <sub> {ReasonReact.string(string_of_int(i + 1))} </sub>
            {ReasonReact.string(i < dimensions - 1 ? ", " : "")}
          </span>
        )
      | Traditional =>
        Array.init(dimensions, i =>
          <span key={string_of_int(i)}>
            {
              let itsLetter = String.make(1, Constants.variablesNames.[i]);
              ReasonReact.string(itsLetter ++ (i < dimensions - 1 ? ", " : ""));
            }
          </span>
        )
      };
    ();
  };
