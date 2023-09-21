let () = print_endline "Hello, World!"

let x = 10;

let square x = x * x;

(* example recursive function*)
let rec range a b =
  if a > b then []
  else a :: range (a + 1) b;

(* example of pattern matching*)
let rec factorial n =
  if n <= 1 then 1
  else n * factorial(n - 1);

(* written with pattern matching*)
let rec factorial n =
  match n with
  | 0 | 1 -> 1
  | x -> x * factorial(x - 1);

(* another example using head and tail*)
let rec total l =
  | [] -> 0
  | h :: t -> h + total t;

let rec length t =
  | [] -> 0
  | _ :: t -> 1 + length t;

(* higher order functions are functions that accept a function as one of it's inputs*)
let rec map f l =
  match l with
  | [] -> []
  | h :: t -> f h :: map f t;
  (* this function takes a list and returns a new list
      with the function applied to each element*)

(* pattern matching must be exhaustive, oCaml will throw a warning if not*)

(* "fun x -> x * x" is a nameless function.
    meaning it won't be saved / usable elsewhere*)

(* partial application is calling a function with only some of it's arguments
  they return a function that will accept the remaining arguments*)
let add a b = a + b;
let f = add 6;
f 7;

map (add 6) [1; 2; 3];
(*returns [7; 8; 9]*)

map (map (fun x -> x * 2)) [[1; 2]; [3; 4]; [5; 6]];
(* returns [[2; 4]; [6; 8]; [10; 12]]*)

(* tuples are a fixed length collection of elements of any type*)
let t = (1, "one")