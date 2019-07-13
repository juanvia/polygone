/** This module defines 2 things for our application:

    * Action, with the possible actions we can use in our application
    * State, representing the state of our application and its reducer

*/

module Polynomial = {

  type flavor = Traditional | Pedantic;

  /** The type of a task in the ToDo app. */
  type t = {
    exponentsArray:      array(array(int)),
    variablesNotation:   flavor,
    coefficientNotation: flavor,
    dimensions:          int,
    degree:              int,
  };
};

module Action = {
  /** The possible actions of our application */
  let flavor_of_string = s =>
    Polynomial.(
      switch (s) {
      | "traditional" => Traditional
      | "pedantic"    => Pedantic
      | _             => Pedantic
      }
    );
  let string_of_flavor = f =>
    Polynomial.(
      switch (f) {
      | Traditional => "traditional"
      | Pedantic    => "pedantic"
      }
    );
  type t =
    | SetExponentsArrayValue(array(array(int)))
    | SetVariablesNotationValue(Polynomial.flavor)
    | SetCoefficientNotationValue(Polynomial.flavor)
    | SetDimensionsValue(int)
    | SetDegreeValue(int);
};

module State = {

  /** The type of the state of the application. */
  type t = {
    exponentsArray:       array(array(int)),
    variablesNotation:    Polynomial.flavor,
    coefficientNotation:  Polynomial.flavor,
    dimensions:           int,
    degree:               int,
  };

  /** Let's pick some initial values */
  let dimensions          = 3;
  let degree              = 6;
  let coefficientNotation = Polynomial.Traditional;
  let variablesNotation   = Polynomial.Traditional;
  let exponentsArray      = Exponents.exponents(dimensions, degree);

  /** The initial state of the application */
  let initial_state = {
    variablesNotation,
    coefficientNotation,
    dimensions,
    degree,
    exponentsArray
  };

  /** Our reducer works very similarly to other reducers you may have seen
      before. If receives the current state, and an action, and will compute
      a new state for the application to continue with. */
  let reducer = (state, action) => {

    let new_state =

      switch (action) {
      | Action.SetExponentsArrayValue(exponentsArray)           => {...state, exponentsArray,      }
      | Action.SetVariablesNotationValue(variablesNotation)     => {...state, variablesNotation,   }
      | Action.SetCoefficientNotationValue(coefficientNotation) => {...state, coefficientNotation, }
      | Action.SetDimensionsValue(dimensions)                   => {...state, dimensions,          }
      | Action.SetDegreeValue(degree)                           => {...state, degree               }
      };

    /* We log the state for convenience when developing */
    Js.log(new_state);

    new_state;
  };
};
