  [@react.component]
  let make = (~state:Model.State.t) => {
    let terms               = state.terms;
    let coefficient_notation = state.coefficient_notation;
    let variables_notation   = state.variables_notation;
    
    /* Ok. We have a list of terms. Each term is a ordered list of exponents. Our mission here is transform the
       list of terms in a list of monomials. Here we go... 
    */  
    
    // First make up a transformation function
    // A monomial is composed by a) The coefficient and b) the variables and its exponents
    let terms_length     = Array.length(terms);
    let monomial_of_term = (termIndex:int, term: array(int)) =>
    <span key={termIndex->string_of_int}>
      <Coefficient termIndex coefficient_notation terms_length/>
      <Variables term variables_notation />
      {
        switch(termIndex) {
        | x when x < terms_length - 1 => " + " ->ReasonReact.string
        | _                           => ""    ->ReasonReact.string;
        }
      }
    </span>;

    // Next use that transformation function in each of terms given
    <>
       {Array.mapi(monomial_of_term, terms) -> ReasonReact.array}
    </>
    
  };
