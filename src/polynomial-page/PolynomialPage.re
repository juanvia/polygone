

[@react.component]
let make = (~state: Model.State.t, ~dispatch: Model.Action.t => unit) => 
  
  <div>

    <PageTitle />
    
    <Form state dispatch />
    
    <Polynomial state />
    
    <Matrix state />
    
  </div>;