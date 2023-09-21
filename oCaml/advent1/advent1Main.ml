(* adventOfCode day 1
   given a list of ints separated by blank lines,
   find which elf is carrying the most total calories
   and what the total calories is*)

(* step 1 - read input from file *)
let read_file filename =
  let channel = open_in filename in
  try
    let rec read_lines acc =
      try
        let line = input_line channel in
        read_lines (line :: acc)
      with End_of_file ->
        List.rev acc
    in
    let lines = read_lines [] in
    close_in channel;
    lines
  with e ->
    close_in_noerr channel;
    raise e
;;

let () =
  let filename = "input.txt" in
  let lines = read_file filename in
  List.iter print_endline lines


(* save input to a list *)

(* calculate the total calories each elf is carrying*)

(* return the highest total *)