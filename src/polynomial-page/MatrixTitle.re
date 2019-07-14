  [@react.component]
  let make = (~state: Model.State.t) => {
    
    let deck = ""
      ++ Utils.dimensionsInWords(state.dimensions)
      ++ ", "
      ++ Utils.degreeInWords(state.degree)
      ++ ", "
      ++ string_of_int(Array.length(state.terms))
      ++ " rows.";

    let title = "Matrix";

    <SectionHeader title deck />;
  };
