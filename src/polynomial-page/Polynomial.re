  [@react.component]
  let make = (~state: Model.State.t) =>
    <div className="row"> <PolynomialTitle state /> <Handwriting state /> </div>;