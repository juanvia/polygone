  [@react.component]
  let make = (~state: Model.State.t) => {
    Js.log(state);
    <div> <div className="HandWriting" /> </div>;
  };
