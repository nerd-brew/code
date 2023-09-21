let rec map f x =
  match x with
  | [] -> []
  | h :: t -> f h :: map f t

let calm list = map 
 (fun list ->
  match list with
  | '!' :: tail -> '.' :: tail
  | _ -> list
  )

let testList = ['H'; 'e'; 'l'; 'p'; '!']
let result = calm testList

