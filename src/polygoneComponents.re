/** This module creates all the components we will need in our App
      application:

      * A Task component, that will show a single task
      * An App component, that will glue together the whole application
  */
module Task = {
  [@react.component]
  let make = (~task, ~onDone) => {
    <li
      className=Model.Task.(
        switch (task.status) {
        | Pending => "pending"
        | Done => "done"
        }
      )>
      <button title="done" onClick={_ => onDone(Model.Task.(task.id))} />
      <span> Model.Task.(React.string(task.label)) </span>
    </li>;
  };
};

module App = {
  /** The main component of our application, it initializes App app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */
  [@react.component]
  let make = () => {

    let (state, _dispatch) = PolygoneModel.State.(React.useReducer(reducer, initial_state));

    let dimensions = state.dimensions |> string_of_int;
    let degree = state.degree |> string_of_int;

    <div className="container-fluid">
      <div className="row">

        <div className="col-md-2">{ReasonReact.string("Sidecar")}</div>
        <div className="col-md-9"> 
          <PolynomialPage.Page dimensions degree />
        </div>
        <div className="col-md-1"> {ReasonReact.string(degree)} </div>

      </div>
    </div>;
  };
};