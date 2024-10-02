forEqual :: (Int -> Int -> Int -> Int) -> Bool
forEqual a b c d
  | a == b && b == c && c == d = True
  | otherwise = False

orderTriple :: (Int, Int, Int) -> (Int, Int, Int)
orderTriple (a,b,c)
  | a <= b && b <= c = (a,b,c)
  | a >= b && b >= c = (c,b,a)
  | a <= b && b >= c = (a,c,b)
  | a >= b && b <= c = (b,a,c)
  | a >= c && c >= b = (c,b,a)
  | a >= c && c <= b = (b,a,c)

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib(n-1)+fib(n-2)

isElem :: Int -> [Int] -> Bool
isElem e [] = False
isElem e (x:xs) = if e == x then True else isElem e xs

luhnDouble :: Int -> Int
luhnDouble x
  | (2*x) > 9 = (2*x)-9
  | otherwise = 2*x

luhn a b c d
  | ((luhnDouble a) + (luhnDouble c) + d + b) `mod` 10 == 0 = True
  | otherwise = False
