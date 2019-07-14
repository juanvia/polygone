  [@react.component]
  let make = (~state: Model.State.t) => {
    
    let deck = ""
      ++ state.dimensions     -> Utils.dimensionsInWords         ++ ", "
      ++ state.degree         -> Utils.degreeInWords             ++ ", "
      ++ state.terms -> Array.length -> string_of_int   ++ " terms.";

    let title = "Polynomial";

    <SectionHeader title deck />;
  };
