module PageTitle = {
  [@react.component]
  let make = () =>
    <div className="PageTitle">
      <h1> {React.string("Get your polynomial")} </h1>
    </div>;
};

module SectionHeader = {
  let str = ReasonReact.string;
  [@react.component]
  let make = (~title, ~deck) =>
    <div className="col-md-12 section-header">
      <h3 className="nogutter"> {str(title)} </h3>
      <div> {str(deck)} </div>
    </div>;
};

module DataCard = {
  let spoiledTitle = "uu";
  [@react.component]
  let make = (~title, ~defaultValue, ~text, ~options, ~handleChange) =>
    <div className="col-md datacard">
      <h5 className="datacard-title"> {React.string(title)} </h5>
      <div className="datacard-text"> {React.string(text)} </div>
      <select
        className="form-control bottom" defaultValue onChange=handleChange>
        options
      </select>
    </div>;
};

module Form = {
  let str = ReasonReact.string;
  let strindex = index => string_of_int(index + 1);
  let stri = string_of_int;
  let manyNumberOptions = howMany =>
    Array.init(howMany, index =>
      <option key={strindex(index)} value={strindex(index)}>
        {str(strindex(index))}
      </option>
    );
  let flavorOptions =
    <>
      <option value="traditional"> {str("Traditional")} </option>
      <option value="pedantic"> {str("Pedantic")} </option>
    </>;

  [@react.component]
  let make =
      (
        ~state: PolygoneModel.State.t,
        ~dispatch: PolygoneModel.Action.t => unit,
      ) => {
    let dimensions = string_of_int(state.dimensions);
    let degree = string_of_int(state.degree);
    let coefficientNotation = state.coefficientNotation;
    let variablesNotation = state.variablesNotation;
    let dimensionsList = manyNumberOptions(Constants.maxDimensions);
    let degreeList = manyNumberOptions(Constants.maxDegree);
    let title = "How to get it?";
    let deck = "Change some values here and look down. It is waiting for you there.";
    // let handleDegreeChange = event => dispatch(App.SetDegree(int_of_string(ReactEvent.Form.target(event)##value)));
    // let handleDimensionsChange = event => dispatch(App.SetDimensions(int_of_string(ReactEvent.Form.target(event)##value)));
    //let handleDegreeChange = event => Js.log(event);

    <div>
      <div className="row"> <SectionHeader title deck /> </div>
      <div className="row">
        <DataCard
          title="Dimensions"
          text="The polynomial's dimensions i.e. the number of independent variables."
          options={ReasonReact.array(dimensionsList)}
          defaultValue=dimensions
          handleChange={e => {
            let value = int_of_string(ReactEvent.Form.target(e)##value);
            PolygoneModel.Action.SetDimensionsValue(value) |> dispatch;
          }}
        />
        <DataCard
          title="Degree"
          text="The polynomial's degree i.e. the maximum among the sums of the term exponents."
          options={ReasonReact.array(degreeList)}
          defaultValue=degree
          handleChange={e => {
            let value = int_of_string(ReactEvent.Form.target(e)##value);
            PolygoneModel.Action.SetDegreeValue(value) |> dispatch;
          }}
        />
        <DataCard
          title="Coefficient notation"
          text="Traditional notation is in the form A,B,C,... Pedantic notation uses subindices of a."
          options=flavorOptions
          defaultValue =PolygoneModel.Action.string_of_flavor(coefficientNotation)
          handleChange={e => {
            let value = PolygoneModel.Action.flavor_of_string( ReactEvent.Form.target(e)##value );
            PolygoneModel.Action.SetCoefficientNotationValue(value) |> dispatch;
          }}
          /* PolygoneModel.Action.SetDimensionsValue(value) |> App.dispatch; */
        />
        <DataCard
          title="Variables notation"
          text="Traditional notation is in the form x,y,z,... Pedantic notation uses subindices of x."
          options=flavorOptions
          defaultValue=PolygoneModel.Action.string_of_flavor(variablesNotation)
          handleChange={e => {
            let value = ReactEvent.Form.target(e)##value;
            let value = PolygoneModel.Action.flavor_of_string( value );
            PolygoneModel.Action.SetVariablesNotationValue(value) |> dispatch;
          }}
          /* PolygoneModel.Action.SetDimensionsValue(value) |> App.dispatch; */
        />
      </div>
    </div>;
  };
};

module Page = {
  let str = ReasonReact.string;
  [@react.component]
  let make =
      (
        ~state: PolygoneModel.State.t,
        ~dispatch: PolygoneModel.Action.t => unit,
      ) => {
    <div>
      <div> <PageTitle /> </div>
      <Form state dispatch />
      <div> {str("Polynomial")} </div>
      <div> {str("Matrix")} </div>
    </div>;
  };
};