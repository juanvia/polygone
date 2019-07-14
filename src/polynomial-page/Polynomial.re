  [@react.component]
  let make = (~state: Model.State.t) => <>

    <GridRow>
      <GridTwelveColumns> 
        <PolynomialTitle state /> 
      </GridTwelveColumns> 
    </GridRow> 

    <GridRow>
      <GridTwelveColumns> 
        <Handwriting state /> 
      </GridTwelveColumns> 
    </GridRow>
    
  </>; 
