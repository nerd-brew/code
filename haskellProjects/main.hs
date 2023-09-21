module Gold where

-- factorial example

factorial :: Int -> Int
factorial 1 = 1
factorial n = n * factorial (n-1)

main = do
  print(factorial 4)
