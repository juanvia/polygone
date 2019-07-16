/** This module creates an App component, that will glue together the whole application
   The main component of our application, it initializes App app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */
[@react.component]
let make = () => {
  let (state, dispatch) = Model.State.(React.useReducer(reducer, initial_state));

  <GridContainer>

    <GridRow>

      <GridTwoColumns>

        <Sidebar />
      
      </GridTwoColumns>


      <GridNineColumns>
        
        <PolynomialPage state dispatch/>
      
      </GridNineColumns>
      

      <GridOneColumn>

        <span/>

      </GridOneColumn>
    
    </GridRow>
  
  </GridContainer>
  
};
