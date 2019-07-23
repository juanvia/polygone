type t =
  | Traditional
  | Pedantic;

let flavor_of_string = s =>
  switch (s) {
  | "traditional" => Traditional
  | "pedantic" => Pedantic
  | _ => Pedantic
  };

let string_of_flavor = flavor =>
  switch (flavor) {
  | Traditional => "traditional"
  | Pedantic    => "pedantic"
  };

let flavor_options =
  <>
    <option value="traditional"> "Traditional" -> ReasonReact.string </option>
    <option value="pedantic">    "Pedantic"    -> ReasonReact.string </option>
  </>;