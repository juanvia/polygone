/*
     <span>
       <span className="surly"> {dependentVariable} </span>
       <span className="surly">ReasonReact.string(" = ")</span>
       <span className="surly">
         <span className="half-surly">ReasonReact.string("f")(</span>
         <span>{independentVariables}</span>
         <span className="surly-half"></span>
         <span>)<span>
       </span>
       <span className="surly">ReasonReact.string(":")</span>
       <span className="surly">
         {ReasonReact.string("ℝ")}
         {superIndex}
         {ReasonReact.string("￫")}
         {ReasonReact.string("ℝ")}
       </span>
       <span className="surly">{ReasonReact.string(" = ")}</span>
     </span>;


 */

let str = ReasonReact.string;
[@react.component]
let make = (~state: Model.State.t, ~dispatch: Model.Action.t => unit) => {
  <div>
    <div> <PageTitle /> </div>
    <Form state dispatch />
    <Polynomial state />
    <div> "Matrix"->ReasonReact.string </div>
  </div>;
};