/** This module creates an App component, that will glue together the whole application
   The main component of our application, it initializes App app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */
[@react.component]
let make = () => {
  let (state, dispatch: Model.Action.t => unit) = Model.State.(React.useReducer(reducer, initial_state));

  <GridContainer>

    <GridRow>

      <GridTwoColumns> 
        "Sidebar" -> ReasonReact.string 
      </GridTwoColumns>

      <GridNineColumns>
        <PolynomialPage state dispatch/>
      </GridNineColumns>
      
      <GridOneColumn> 
        state.dimensions          -> string_of_int                 -> ReasonReact.string <br/> 
        state.degree              -> string_of_int                 -> ReasonReact.string <br/>
        state.coefficientNotation -> Model.Action.string_of_flavor -> ReasonReact.string <br/> 
        state.variablesNotation   -> Model.Action.string_of_flavor -> ReasonReact.string <br/> 
      </GridOneColumn>
    
    </GridRow>
  
  </GridContainer>
};