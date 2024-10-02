gra = [\x y -> x + y, \x y -> x - y, \x y -> y * x, \x y -> x / y]
gra' = [(+), (-), (/), (*)]

gz = [n | n <- [1..20], n `mod` 2 == 0]
gz' s e d = [n | n <- [s..e], n `mod` d == 0]

teiler n = [a | a <- [1..n], n `mod` a == 0]

sk1 a b = sum [a*b | (a,b) <- zip a b]

py n = [(x,y,z) | x <- [1..n], y <- [1..n], x < y, z <- [1..n], y < n, z * z == x * x + y * y]


applyAll :: a -> b -> [a -> b -> c] -> [c]
applyAll a b c = [n a b | n <- c]


merge :: Ord a => [a] -> [a] -> [a]
merge [] s = s
merge s [] = s
merge (a:as) (b:bs)
  | a <= b = a : merge as (b:bs)
  | otherwise = b : merge (a:as) bs

half :: [a] -> ([a], [a])
half [] = ([],[])
half [x] = ([x],[])
half (x:xys)
  | ((length xys) >= length xs) = (x:xs, ys)
  | otherwise = (xs, x:ys)
  where (xs, ys) = half xys

msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
msort (a:as) = merge ( half (a:as) )
