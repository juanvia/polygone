
  let manyNumberOptions = (start, howMany) => {
    Array.init(
      howMany + 1 - start, 
      index => {

        let key = (index + start) -> string_of_int;
        
        <option key value=key>
          key -> ReasonReact.string
        </option>

      }
    )
  }

  let flavorOptions = <>
    <option value="traditional"> "Traditional" -> ReasonReact.string </option>
    <option value="pedantic">    "Pedantic"    -> ReasonReact.string </option>
  </>;

  [@react.component]
  let make = (~state: Model.State.t, ~dispatch: Model.Action.t => unit) => {

    let dimensions          = state.dimensions -> string_of_int;
    let degree              = state.dimensions -> string_of_int;
    let coefficientNotation = state.coefficientNotation;
    let variablesNotation   = state.variablesNotation;
    let dimensionsList      = Constants.maxDimensions -> manyNumberOptions(1);
    let degreeList          = Constants.maxDegree     -> manyNumberOptions(0);
    let title               = "How to get it?";
    let deck                = "Change some values here and look down. It is waiting for you there.";

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
          handleChange={e => {
            
            let value = int_of_string(ReactEvent.Form.target(e)##value);
            Model.Action.SetDimensionsValue(value) -> dispatch;
          }}
        />
        
        <SelectionCard
          title="Degree"
          text="The polynomial's degree i.e. the maximum among the sums of exponents of each term."
          options={ReasonReact.array(degreeList)}
          defaultValue=degree
          handleChange={e => {
            let value = int_of_string(ReactEvent.Form.target(e)##value);
            Model.Action.SetDegreeValue(value) -> dispatch;
          }}
        />
        
        <SelectionCard
          title="Coefficient notation"
          text="Traditional notation is in the form A,B,C,... Pedantic notation uses subindices of a."
          options=flavorOptions
          defaultValue={Model.Action.string_of_flavor(coefficientNotation)}
          handleChange={e => {
            let value =
              Model.Action.flavor_of_string(ReactEvent.Form.target(e)##value);
            Model.Action.SetCoefficientNotationValue(value) |> dispatch;
          }}
          /* Model.Action.SetDimensionsValue(value) |> App.dispatch; */
        />
        
        <SelectionCard
          title="Variables notation"
          text="Traditional notation is in the form x,y,z,... Pedantic notation uses subindices of x."
          options=flavorOptions
          defaultValue={Model.Action.string_of_flavor(variablesNotation)}
          handleChange={e => {
            let value = ReactEvent.Form.target(e)##value;
            let value = Model.Action.flavor_of_string(value);
            Model.Action.SetVariablesNotationValue(value) |> dispatch;
          }}
          /* Model.Action.SetDimensionsValue(value) |> App.dispatch; */
        />

      </GridRow>

    </>;
  };
