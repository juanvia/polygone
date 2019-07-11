
  let dimensionsInWords = (dimensions: int) =>
    switch (dimensions) {
    | 0 => "Constant"
    | 1 => "Unidimensional"
    | 2 => "Bidimensional"
    | 3 => "Tridimensional"
    | 4 => "Four-dimensional"
    | 5 => "Five-dimensional"
    | 6 => "Six-dimensional"
    | _ => string_of_int(dimensions) ++ "-dimensional"
    };

  let degreeInWords = (degree: int) =>
    switch (degree) {
    | 0 => "constant"
    | 1 => "linear or monic"
    | 2 => "quadratic"
    | 3 => "cubic"
    | 4 => "quartic o bi-cuadratic"
    | 5 => "quintic"
    | 6 => "sextic or hexic"
    | 7 => "septic or heptic"
    | 8 => "octic"
    | 9 => "nonic"
    | _ => string_of_int(degree) ++ "th degree"
    };
