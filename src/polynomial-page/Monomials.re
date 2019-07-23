[@react.component]
let make = (~state: Model.State.t) => {

  let terms                = state.terms;
  let coefficient_notation = state.coefficient_notation;
  let variables_notation   = state.variables_notation;

  // Ok. We have a array of terms. Each term is a ordered array of exponents. 
  // Our mission here is transform the array of terms in a array of monomials. 
  // A monomial is composed by a) The coefficient and b) the variables and its exponents
  // Here we go...

  // First make up a transformation function...
  
  let terms_length = Array.length(terms);
  
  module TermsSeparator = { 
    [@react.component] let make = (~term_index) => 
      term_index < terms_length 
        ? " + " |> ReasonReact.string 
        : <span/> 
  };

  let monomial_of_term = (term_index, term) => <span key={term_index |> string_of_int}>
    <Coefficient    term_index   coefficient_notation   terms_length />
    <Variables      term         variables_notation                  />
    <TermsSeparator term_index                                       />
  </span>;

  // ...next use that transformation function in each of terms given.

  // And embed the monomials array in a fragment.
  <> {Array.mapi(monomial_of_term, terms) |> ReasonReact.array} </>;
};