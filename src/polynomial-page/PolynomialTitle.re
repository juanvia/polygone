  [@react.component]
  let make = (~state: Model.State.t) => {
    let deck =
      ""
      ++ state.dimensions     -> Utils.dimensionsInWords         ++ ", "
      ++ state.degree         -> Utils.degreeInWords             ++ ", "
      ++ state.exponentsArray -> string_of_int -> String.length  ++ " terms.";

    let title = "Polynomial";

    <div> <SectionHeader title deck /> </div>;
  };