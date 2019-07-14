[@react.component]
let make = (~term: array(int), ~variables_notation:Flavor.t) => {
  let variable_traditional_notation = (exponent: int, variableIndex: int) => {
    let name =
      switch (exponent) {
      | 0 => <> ""->ReasonReact.string </> // a**0 = 1 & 1*term == term
      | _ =>
        <>
          {String.sub(Constants.variableNames, variableIndex, 1)
           ->ReasonReact.string}
        </>
      };

    let superindex =
      switch (exponent) {
      | x when x < 2 => <> ""->ReasonReact.string </>
      | _ => <sup> {exponent->string_of_int->ReasonReact.string} </sup>
      };
    <> name superindex </>;
  };

  let variable_pedantic_notation = (exponent: int, variableIndex: int) => {
    let name =
      switch (exponent) {
      | 0 => <> ""->ReasonReact.string </> // a**0 = 1 & 1*term == term
      | _ =>
        <>
          "x"->ReasonReact.string
          <sub> {(variableIndex + 1)->string_of_int->ReasonReact.string} </sub>
        </>
      };

    let superindex =
      switch (exponent) {
      | x when x < 2 => <> ""->ReasonReact.string </>
      | _ => <sup> {exponent->string_of_int->ReasonReact.string} </sup>
      };

    <> name superindex </>;
  };

  let pedantic_variable_of_index = (variableIndex: int, exponent) =>
    <span>
      {variable_pedantic_notation(exponent, variableIndex)}
    </span>;

  let traditional_variable_of_index = (variableIndex: int, exponent) =>
    <span>
      {variable_traditional_notation(exponent, variableIndex)}
    </span>;

  // Next use that transformation function in each of terms given
  <span>
  {
    switch (variables_notation) {
    | Traditional => Array.mapi(traditional_variable_of_index, term)->ReasonReact.array
    | Pedantic    => Array.mapi(pedantic_variable_of_index,    term)->ReasonReact.array
    };
  }
  </span>;

};