module Columns   = { [@react.component] let make = ( ~children, ~cols ) => <div className={"col-md-" ++ string_of_int(cols)} > children </div> };
module Container = { [@react.component] let make = ( ~children )        => <div className="container-fluid"                  > children </div> };
module Row       = { [@react.component] let make = ( ~children )        => <div className="row"                              > children </div> };
