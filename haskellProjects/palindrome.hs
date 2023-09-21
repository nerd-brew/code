-- program that checks if a word is a palindrome

import Pal (isPalindrome)

-- interactive program --

main :: IO ()
main = 
    do
        word <- getLine
        print (verbose word)

verbose :: String -> String
verbose word =
    case (isPalindrome word) of
        Nothing -> "Please enter a word"
        Just False -> "Sorry, this is not a palindrome"
        Just True -> "Yay, this is a palindrome!"




