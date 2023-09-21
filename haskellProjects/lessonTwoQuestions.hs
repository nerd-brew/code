-- chapter questions for lesson 2

inc :: Integer -> Integer
inc x = x + 1

double :: Integer -> Integer
double x = x * 2

square :: Integer -> Integer
square x = x * x

evenOrOdd :: Integer -> Integer
evenOrOdd x = if even x
              then x - 2
              else 3 * x + 1

-- example use of a lambda function within another function
-- (x * 2) is passed into the lambda function preceding it
doubleDouble :: Integer -> Integer
doubleDouble x = let dubs = (x * 2)
                 in
                  dubs * 2

friendAge :: String -> Integer
friendAge name =
  case name of
    "Andy" -> 33
    _ -> 0

