/** This module creates an App component, that will glue together the whole application
   The main component of our application, it initializes App app with
        an initial state and hooks up the reducer and actions with the DOM
        events. */

/*

### ToDo

- Convert all variable names from camelCase to underscore_separated
- Refactor recursive call in reducer
- Async web service call. Use  https://quotes.rest/ to retrieve quotes and put them in the sidebar.
- Try to enable OCaml syntax
- Go mobile & desktop via Cordova, platforms android and electron.

*/

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
