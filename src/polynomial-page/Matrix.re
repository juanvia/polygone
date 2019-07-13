[@react.component]
let make = (~state: Model.State.t) => {
  let exponents =
    switch (Js.Json.stringifyAny(state.exponentsArray)) {
    | None => ""
    | Some(transformed) => transformed
    };

  <>
    <div className="row">
      <MatrixTitle state />
    </div>
    <div className="row">
      <GridColumn>
        <code className="the-matrix"> exponents -> ReasonReact.string </code>
      </GridColumn>
    </div>
  </>;
};