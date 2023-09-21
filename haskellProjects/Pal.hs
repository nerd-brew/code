module Pal where

import Data.Char

-- Input formatting for palindrome test --

isPalindrome :: String -> Maybe Bool
isPalindrome string =
    isOwnReverseMaybe (rejectEmpty (normalize string))

rejectEmpty :: String -> Maybe String
rejectEmpty word =
    case word of
        [] -> Nothing
        _ -> Just word

normalize :: String -> String
normalize string =
    filter notPunctuation (filter notSpace (allLowerCase string))

isOwnReverseMaybe :: Maybe String -> Maybe Bool
isOwnReverseMaybe maybeString =
    case maybeString of
        Nothing -> Nothing
        Just string -> Just (isOwnReverse string)

isOwnReverse :: String -> Bool
isOwnReverse word = 
    word == reverse word

allLowerCase :: String -> String
allLowerCase word =
    map toLower word

notPunctuation :: Char -> Bool
notPunctuation x = not (isPunctuation x)

notSpace :: Char -> Bool
notSpace x = not (x == ' ')