

  [@react.component]
  let make = (~state: Model.State.t, ~dispatch: Model.Action.t => unit) => {

    let title               =  "How to get it?"
    let deck                =  "Change some values here and look down. It is waiting for you there."

    let dim                 =  state.dimensions           |> string_of_int
    let deg                 =  state.degree               |> string_of_int
    let cof                 =  state.coefficient_notation |> Flavor.string_of_flavor
    let var                 =  state.variables_notation   |> Flavor.string_of_flavor
  
    let dim_options         =  Utils.many_number_options(1, Constants.max_dimensions) |> ReasonReact.array
    let deg_options         =  Utils.many_number_options(0, Constants.max_degree)     |> ReasonReact.array
    let cof_options         =  Flavor.flavor_options  
    let var_options         =  Flavor.flavor_options  
       
    let dim_action          =  value =>  value -> Model.Action.SetDimensionsValue
    let deg_action          =  value =>  value -> Model.Action.SetDegreeValue
    let cof_action          =  value =>  value -> Model.Action.SetCoefficientNotationValue
    let var_action          =  value =>  value -> Model.Action.SetVariablesNotationValue
  
    let dim_title           =  "Dimensions"
    let var_title           =  "Variables notation"
    let cof_title           =  "Coefficient notation"
    let deg_title           =  "Degree"
        
    let dim_text            =  "The polynomial's dimensions i.e. the number of independent variables."
    let deg_text            =  "The polynomial's degree i.e. the maximum among the each term's exponents sum."
    let cof_text            =  "Traditional notation is in the form A,B,C,... Pedantic notation uses subindices of a."
    let var_text            =  "Traditional notation is in the form x,y,z,... Pedantic notation uses subindices of x."
  
    let event_value         =  event =>  ReactEvent.Form.target(event)##value
    let dim_change_handler  =  event =>  event_value(event) |> int_of_string           |> dim_action |> dispatch
    let deg_change_handler  =  event =>  event_value(event) |> int_of_string           |> deg_action |> dispatch
    let cof_change_handler  =  event =>  event_value(event) |> Flavor.flavor_of_string |> cof_action |> dispatch
    let var_change_handler  =  event =>  event_value(event) |> Flavor.flavor_of_string |> var_action |> dispatch
     
    ;

    <>
    
      
      <Grid.Row>
        <Grid.Columns cols={12}>
          <SectionHeader title deck />
        </Grid.Columns>
      </Grid.Row>
      
      <Grid.Row>

        <Grid.Columns cols={1}>
          <SelectionCard
            defaultValue  = dim
            title         = dim_title
            text          = dim_text
            options       = dim_options
            handleChange  = dim_change_handler
          />
        </Grid.Columns>
        
        <Grid.Columns cols={1}>
          <SelectionCard
            defaultValue  = deg
            title         = deg_title
            text          = deg_text
            options       = deg_options
            handleChange  = deg_change_handler
          />
        </Grid.Columns>
        
        <Grid.Columns cols={1}>
          <SelectionCard
            defaultValue  = cof
            title         = cof_title
            text          = cof_text
            options       = cof_options
            handleChange  = cof_change_handler
          />
        </Grid.Columns>
        
        <Grid.Columns cols={1}>
          <SelectionCard
            defaultValue  = var
            title         = var_title
            text          = var_text
            options       = var_options
            handleChange  = var_change_handler
          />
        </Grid.Columns>

      </Grid.Row>

    </>
    
    ;

  };
