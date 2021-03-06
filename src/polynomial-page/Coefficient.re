[@react.component]
let make = (~term_index, ~coefficient_notation, ~terms_length) => {
  // Let's check some things before acting.
  let max_allowed = String.length(Constants.coefficientNames);
  let effective_notation: Flavor.t =
    switch (terms_length) {
    | x when x > max_allowed =>  Pedantic
    | _                       => coefficient_notation
    };

  // Ok. Let's do it
  switch (effective_notation) {
  | Traditional => <> {String.sub(Constants.coefficientNames, term_index, 1)->ReasonReact.string} </>
  | _ =>
    <>
      "a"->ReasonReact.string
      <sub className="slightly-displaced"> {(terms_length-term_index-1)->string_of_int->ReasonReact.string} </sub>
    </>
  };
};
