cToF = fn (celsius) -> celsius * 1.8 + 32 end

cToF.(32)

seconds = fn (numDays) ->
  seconds = 60 * 60 * 24
  numDays * seconds
end

seconds.(3)

averageAge = fn (map1 map2) ->
  (map1.age + map2.age) / 2
end

#assign the first three elements, like in h::t, to the first three items in list
[first, second, third | others] = list

thoseWhoAreAssembled = [
  %{age: "30ish", gender: female, name: "Izzy"},
  %{age: "30ish", gender: male, name: "The Author"},
  %{age: "Unknowable", gender: unknown, name: "The Reader"},
]

#assign thoseWhoAreAssembled.name to the var firstName
#assign the whole first entry map to firstPerson
#assign the rest of the maps in the list to others
#aka "destructuring"
[firstPerson = %{name: firstName} | others] = thoseWhoAreAssembled

road = fn
  "high" -> "You take the high road!"
  "low" -> "I'll take the low road!"
  _ -> "Take the 'high' road or the 'low' road, thanks!"
end

nameAge = fn
  %{"name" => name, "age" => age} -> "Hello #{name}, age: #{age}"
  %{"age" => age} -> "You are #{age}"
end

#called with
nameAge.(%{"name" => "Tyler", "age" => 31})

name = IO.gets "What's your name?"
#returns string with \n
name = String.trim(name)
#removes \n

name = IO.gets "What is your name?"
age = IO.gets "How old are you?"
IO.puts "Hello, #{String.trim(name)}. You're #{String.trime(age)} years old."

person = IO.gets "Person: "
place = IO.gets "Place: "
thing = IO.gets "Thing: "

IO.puts "#{String.trim(person)} went to #{String.trim(place)} to get #{String.trim(thing)}.}"

Enum.each(cities, &IO.puts)
#prints each item in the cities list

Enum.map(cities, &String.capitalize)
#unlike each, map will iterate through the list and save the results to a new list

#anonymous functions inside map
Enum.map(numList, fn (x) -> x * 2 end)

#Enum.reduce iterates through a list to return a single value
#basically just calling the function on the list with tail-recursion
Enum.reduce(scores, fn (score, sum))

replaceE = fn (list) ->
  Enum.map(list, fn(x) -> String.replace(x, "e", "i")end)
end

multiplyList = fn (list) ->
  Enum.reduce(list, fn (x, y) -> x * y end)
end

#converts a list, newForecast, into a map
Enum.into(newForecast, %{})

#pipe operator example
"hello pipe operator" |> String.upcase() |> String.reverse()
#outputs "ROTAREPO EPIP OLLEH"

#pipe formatting example

%{
  "Monday" => 28,
  "Tuesday" => 29,
  "Wednesday" => 29
}
|> Enum.map(fn ({day, temp}) -> {day, temp * 1.8 + 32} end)
|> Enum.into(%{})
|> IO.inspect
