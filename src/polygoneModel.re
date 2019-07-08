/** This module defines 2 things for our application:

    * Action, with the possible actions we can use in our application
    * State, representing the state of our application and its reducer

*/
module Flavor = {

};
module Polynomial = {

  type flavor =
    | Traditional
    | Pedantic;

  /** The type of a task in the ToDo app. */
  type t = {
    exponentsArray: string,
    variablesNotation: flavor,
    coefficientNotation: flavor,
    dimensions: int,
    degree: int
  };

};

module Action = {
  /** The possible actions of our application */
  type t =
    | SetExponentsArrayValue(string)
    | SetVariablesNotationValue(Polynomial.flavor)
    | SetCoefficientNotationValue(Polynomial.flavor)
    | SetDimensionsValue(int)
    | SetDegreeValue(int);
};

module State = {
  /** The type of the state of the application. */
  type t = {
    exponentsArray: string,
    variablesNotation: Polynomial.flavor,
    coefficientNotation: Polynomial.flavor,
    dimensions: int,
    degree: int,
  };

  /** The initial state of the application */
  let initial_state = {
    exponentsArray: "",
    variablesNotation: Traditional,
    coefficientNotation: Pedantic,
    dimensions: 3,
    degree: 6,
  };

  /** Our reducer works very similarly to other reducers you may have seen
      before. If receives the current state, and an action, and will compute
      a new state for the application to continue with. */
  let reducer = (state, action) => {
    let new_state =
      switch (action) {
        | Action.SetExponentsArrayValue(exponentsArray) => {...state, exponentsArray: exponentsArray }
        | Action.SetVariablesNotationValue(selection) => { ...state, variablesNotation: selection, }
        | Action.SetCoefficientNotationValue(selection) => { ...state, coefficientNotation: selection, }
        | Action.SetDimensionsValue(selection) => {...state, dimensions: selection}
        | Action.SetDegreeValue(selection) => {...state, degree: selection}
      };
    /* We log the state for convenience when developing */
    Js.log(new_state);
    new_state;
  };
};