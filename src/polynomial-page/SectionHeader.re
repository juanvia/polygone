  [@react.component]
  let make = (~title, ~deck) =>
    <div className="section-header">
      <h3 className="nogutter"> {title -> ReasonReact.string} </h3>
      <div> {deck -> ReasonReact.string} </div>
    </div>;