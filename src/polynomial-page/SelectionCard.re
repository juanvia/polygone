let spoiledTitle = "uu";
[@react.component]
let make = (~title, ~defaultValue, ~text, ~options, ~handleChange) =>
  <GridColumn>
    <div className="selectioncard">
      <h5 className="selectioncard-title"> {React.string(title)} </h5>
      <div className="selectioncard-text"> {React.string(text)} </div>
      <select
        className="form-control bottom" defaultValue onChange=handleChange>
        options
      </select>
    </div>
  </GridColumn>;