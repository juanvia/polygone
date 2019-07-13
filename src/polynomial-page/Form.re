
  let manyNumberOptions = (start, howMany) => {
    Array.init(
      howMany + 1 - start, 
      index => <option key={(index+start) -> string_of_int} value={(index+start) -> string_of_int} >
          (index + start) -> string_of_int -> ReasonReact.string
        </option>
    ) 
  }

  let flavorOptions = <>
    <option value="traditional"> "Traditional" -> ReasonReact.string </option>
    <option value="pedantic">    "Pedantic"    -> ReasonReact.string </option>
  </>;

  let eventValue     = event   => ReactEvent.Form.target(event)##value;

  let flavor_of_string = Model.Action.flavor_of_string;

  [@react.component]
  let make = (~state: Model.State.t, ~dispatch: Model.Action.t => unit) => {

    let dimensions          = state.dimensions -> string_of_int;
    let degree              = state.dimensions -> string_of_int;
    let coefficientNotation = state.coefficientNotation;
    let variablesNotation   = state.variablesNotation;

    let dimensionsList      =  manyNumberOptions(1, Constants.maxDimensions);
    let degreeList          =  manyNumberOptions(0, Constants.maxDegree);
    
    let title               = "How to get it?";
    let deck                = "Change some values here and look down. It is waiting for you there.";
    
    let dimensionsAction    = dim =>  Model.Action.SetDimensionsValue(dim);
    let degreeAction        = deg =>  Model.Action.SetDegreeValue(deg);
    let coefficientAction   = dim =>  Model.Action.SetCoefficientNotationValue(dim);
    let variablesAction     = var =>  Model.Action.SetCoefficientNotationValue(var);
    let exponentsAction     = exp =>  Model.Action.SetExponentsArrayValue(exp);
    
    let dispatchDimChange     = event => event |> eventValue |> int_of_string    |> dimensionsAction   |> dispatch;
    let dispatchDegChange     = event => event |> eventValue |> int_of_string    |> degreeAction       |> dispatch;
    let dispatchCofChange     = event => event |> eventValue |> flavor_of_string |> coefficientAction  |> dispatch;
    let dispatchVarChange     = event => event |> eventValue |> flavor_of_string |> variablesAction    |> dispatch;

    let dim                   = dimensions -> int_of_string;
    let deg                   = degree     -> int_of_string;
    let makeExponentsArray    = () => Exponents.exponents (dim, deg) |> exponentsAction |> dispatch;

    let handleDimChange     = event => {event |> dispatchDimChange; makeExponentsArray()};
    let handleDegChange     = event => {event |> dispatchDegChange; makeExponentsArray()};
    let handleCofChange     = event => {event |> dispatchCofChange; makeExponentsArray()};
    let handleVarChange     = event => {event |> dispatchVarChange; makeExponentsArray()};

    <>
      
      <GridRow>
        
        <SectionHeader title deck />
      
      </GridRow>
      
      <GridRow>

        <SelectionCard
          title="Dimensions"
          text="The polynomial's dimensions i.e. the number of independent variables."
          options={ReasonReact.array(dimensionsList)}
          defaultValue=dimensions
          handleChange=handleDimChange
        />
        
        <SelectionCard
          title="Degree"
          text="The polynomial's degree i.e. the maximum among the sums of exponents of each term."
          options={ReasonReact.array(degreeList)}
          defaultValue=degree
          handleChange=handleDegChange
        />
        
        <SelectionCard
          title="Coefficient notation"
          text="Traditional notation is in the form A,B,C,... Pedantic notation uses subindices of a."
          options=flavorOptions
          defaultValue={Model.Action.string_of_flavor(coefficientNotation)}
          handleChange=handleCofChange
        />
        
        <SelectionCard
          title="Variables notation"
          text="Traditional notation is in the form x,y,z,... Pedantic notation uses subindices of x."
          options=flavorOptions
          defaultValue={Model.Action.string_of_flavor(variablesNotation)}
          handleChange=handleVarChange
        />

      </GridRow>

    </>;
  };
