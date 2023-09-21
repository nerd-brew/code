#elixir school notes

#list - can contain multiple types
[1, 3, "bob"]

#list concatenation uses "++" operator
[1, 2] ++ [3, 4] = [1, 2, 3, 4]

#list subtraction is done with "--"
[1, 2, 3] -- [2] = [1, 3]

#hd and tl are functions in elixir
hd [1, 2, 3] #returns 1

#[head | tail] can be used with the cons operator "|"
[head | tail] = [1, 2, 3] # head = [1] tail = [2, 3]

#Map.put example
izzy = %{"name" => "Izzy", "age" => "30ish", "gender" => "Female"}
izzy = Map.put(izzy, "age", "40ish")

izzy |> Map.put("age", "40ish") |> Map.put("country", "Australia")
# %{"age" => "40ish", "country" => "Australia", "gender" => "Female", "name" => "Izzy"}
#in the above code the original izzy map isn't changed. We would need to rebind by adding
# "izzy = " before the code
izzy = izzy |> Map.put("age", "40ish") |> Map.put("country", "Australia")

#the same could be done with Map.merge
izzy = Map.merge(izzy, %{"age" = "40ish", "country" = "Australia"})

#pipe merging can be used to update key values but not to add new keys
