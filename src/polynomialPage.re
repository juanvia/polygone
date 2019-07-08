
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
  [@react.component]
  let make = (~title, ~defaultValue, ~text, ~options) =>
    <div className="col-md datacard">
      <h5 className="datacard-title"> {React.string(title)} </h5>
      <div className="datacard-text"> {React.string(text)} </div>
      <select className="form-control bottom" defaultValue> options </select>
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
  let title = "How to get it?";
  let deck = "Change some values here and look down. It is waiting for you there.";

  [@react.component]
  let make = (~dimensions, ~degree) => {
    let dimensions = 3;
    let dimensionsList = manyNumberOptions(Constants.maxDimensions);

    let degree = 3;
    let degreeList = manyNumberOptions(Constants.maxDegree);

    // let handleDegreeChange = event => dispatch(App.SetDegree(int_of_string(ReactEvent.Form.target(event)##value)));
    // let handleDimensionsChange = event => dispatch(App.SetDimensions(int_of_string(ReactEvent.Form.target(event)##value)));
    //let handleDegreeChange = event => Js.log(event);

    <div>
      <div className="row"> <SectionHeader title deck /> </div>
      <div> {str(stri(dimensions))} <br /> {str(stri(dimensions))} </div>
      <div className="row">
        <DataCard
          title="Set the dimensions"
          text="Enter the polynomial's dimensions i.e. the number of independent variables."
          options={ReasonReact.array(dimensionsList)}
          defaultValue={string_of_int(dimensions)}
        />
        <DataCard
          title="Set the degree"
          text="Enter the polynomial's degree i.e. the maximum sum of the term exponents."
          options={ReasonReact.array(degreeList)}
          defaultValue={string_of_int(degree)}
        />
        <DataCard
          title="Set the coefficient notation"
          text="Traditional notation is in the form A,B,C,... Pedantic notation uses subindices of a."
          options=flavorOptions
          defaultValue="traditional"
        />
        <DataCard
          title="Set the variables notation"
          text="Traditional notation is in the form x,y,z,... Pedantic notation uses subindices of x."
          options=flavorOptions
          defaultValue="traditional"
        />
      </div>
    </div>;
  };
};

module Page = {
  let str = ReasonReact.string;
  [@react.component]
  let make = (~dimensions, ~degree) => {
    <div>
      <div> <PageTitle /> </div>
      <Form dimensions degree />
      <div> {str("Polynomial")} </div>
      <div> {str("Matrix")} </div>
    </div>;
  };
};