[@react.component]
let make = (~state: Model.State.t) => {
  let exponents =
    switch (Js.Json.stringifyAny(state.terms)) {
    | None => ""
    | Some(transformed) => transformed
    };

  <>
    <GridRow>
      <GridColumn>
        <MatrixTitle state />
      </GridColumn>
    </GridRow>
    
    <GridRow>
      <GridTwelveColumns>
        <code className="the-matrix"> exponents->ReasonReact.string </code>
      </GridTwelveColumns>
    </GridRow>

  </>;
};