/** This module creates an App component, that will glue together the whole application
   The main component of our application, it initializes App app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */
[@react.component]
let make = () => {
  let (state, dispatch: PolygoneModel.Action.t => unit) =
    PolygoneModel.State.(React.useReducer(reducer, initial_state));

  <div className="container-fluid">
    <div className="row">
      <div className="col-md-2"> {ReasonReact.string("Sidecar")} </div>
      <div className="col-md-9">
        <PolynomialPage.Page state dispatch />
      </div>
      <div className="col-md-1"> 
        {ReasonReact.string(state.dimensions |> string_of_int)}
        <br/> 
        {ReasonReact.string(state.degree |> string_of_int)}
      </div>
    </div>
  </div>;
};