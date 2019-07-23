[@react.component]
let make = (~state: Model.State.t) => {
  let exponents =
    switch (Js.Json.stringifyAny(state.terms)) {
    | None => ""
    | Some(transformed) => transformed
    };

  <>
    <Grid.Row>
      <Grid.Columns cols={1}>
        <MatrixTitle state />
      </Grid.Columns>
    </Grid.Row>
    
    <Grid.Row>
      <Grid.Columns cols={12}>
        <code className="the-matrix"> exponents->ReasonReact.string </code>
      </Grid.Columns>
    </Grid.Row>

  </>;
};