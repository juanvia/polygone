/** This module defines 2 things for our application:

    * Action, with the possible actions we can use in our application
    * State, representing the state of our application and its reducer

*/

module Polynomial = {

  /** The type of a task in the ToDo app. */
  type t = {
    terms:      array(array(int)),
    variables_notation:   Flavor.t,
    coefficient_notation: Flavor.t,
    dimensions:          int,
    degree:              int,
  };
};

module Action = {
  /** The possible actions of our application */

  type t =
    | SetExponentsArrayValue(array(array(int)))
    | SetVariablesNotationValue(Flavor.t)
    | SetCoefficientNotationValue(Flavor.t)
    | SetDimensionsValue(int)
    | SetDegreeValue(int);
};

module State = {

  /** The type of the state of the application. */
  type t = {
    terms:                array(array(int)),
    variables_notation:    Flavor.t,
    coefficient_notation:  Flavor.t,
    dimensions:           int,
    degree:               int,
  };

  
  /** Let's pick some initial values */
  let dimensions                   = 3;
  let degree                       = 3;
  let coefficient_notation:Flavor.t = Traditional;
  let variables_notation:Flavor.t   = Traditional;
  let terms                        = Exponents.exponents(dimensions, degree);

  /** The initial state of the application */
  let initial_state = {
    variables_notation,
    coefficient_notation,
    dimensions,
    degree,
    terms
  };

  /** Our reducer works very similarly to other reducers you may have seen
      before. If receives the current state, and an action, and will compute
      a new state for the application to continue with. */
  let rec reducer = (state, action) => {
    let new_state =
      switch (action) {
      | Action.SetExponentsArrayValue(terms)                    => {...state, terms,               }
      | Action.SetVariablesNotationValue(variables_notation)     => {...state, variables_notation,   }
      | Action.SetCoefficientNotationValue(coefficient_notation) => {...state, coefficient_notation, }
      | Action.SetDimensionsValue(dimensions)                   => {...state, dimensions,          }
      | Action.SetDegreeValue(degree)                           => {...state, degree               }
      };

    /* We log the state for convenience when developing */
    Js.log(new_state);

    /* Ok. But...
       Our state may be 'dirty'. 
       The changes in dimensions or degree are making the exponents array obsolete.
       Then, in those cases, we must recalculate that array before return. 
    */
    let makeTerms = ()             => Exponents.exponents(new_state.dimensions, new_state.degree)
    switch (action) {
    | Action.SetDimensionsValue(_) => reducer(new_state, Action.SetExponentsArrayValue(makeTerms()))
    | Action.SetDegreeValue(_)     => reducer(new_state, Action.SetExponentsArrayValue(makeTerms()));
    | _ => new_state
    };

  };
};
