  [@react.component]
  let make = (~state: Model.State.t) => {
    let deck =
      ""
      ++ Utils.dimensionsInWords(state.dimensions)
      ++ ", "
      ++ Utils.degreeInWords(state.degree)
      ++ ", "
      ++ string_of_int(String.length(state.exponentsArray))
      ++ " rows.";

    let title = "Matrix";

    <div> <SectionHeader title deck /> </div>;
  };
