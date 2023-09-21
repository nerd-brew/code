(* adventOfCode day 1
   given a list of ints separated by blank lines,
   find which elf is carrying the most total calories
   and what the total calories is*)

open core;
open In_channel;

(* step 1 - read input from file *)
let read_file file =
  In_channel.with_open_bin file In_channel.input_all

(* read lines *)
let read_lines file =
  let contents = In_channel.with_open_bin file In_channel.input_all in
  String.split_on_char '\n' contents

List.iter print_endline (read_lines advent1InputFile)


(* save input to a list *)

(* calculate the total calories each elf is carrying*)

(* return the highest total *)