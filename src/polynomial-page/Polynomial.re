  [@react.component]
  let make = (~state: Model.State.t) => <>

    <Grid.Row>

      <Grid.Columns cols={12}>

        <PolynomialTitle state /> 
        
        <Handwriting state /> 
      
      </Grid.Columns> 
    
    </Grid.Row>
    
  </>; 
