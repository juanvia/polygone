[@react.component]
let make = (~state: Model.State.t) =>
  <div className="Handwriting">
    <Left state /> 
    <Monomials state />
  </div>;