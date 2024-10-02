gra = [\x y -> x + y, \x y -> x - y, \x y -> x * y, \x y -> x / y]
gra' = [(+), (-), (/), (*)]

gz = [n | n <- [1..20], n `mod` 2 == 0]
gz' s e d = [n | n <- [s..e], n `mod` d == 0]

teiler x = [n | n <- [1..x], x `mod` n == 0]

skalarprodukt as bs = sum[a*b | (a,b) <- zip as bs]

pyths x = [(a,b,c) | a <- [1..x], b <- [1..x], c <- [1..x], (a*a + b*b) == c*c]
pyths' x = [(a,b,c) | a <- [1..x], b <- [1..x], c <- [1..x], (a*a + b*b) == c*c && a < b]

applyAll a b f = [f a b | f <- gra]

merge [] as = as
merge bs [] = bs
merge (a:as) (b:bs)
  | a <= b = a : merge as (b:bs)
  | otherwise = b : merge (a:as) bs

half [] = ([],[])
half [x] = ([x],[])
half (x:y:xys)
  | x <= y = (x:xs, y:ys)
  | otherwise = (y:xs, x:ys)
  where (xs, ys) = half xys

msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
msort xs = merge (msort (fst (half xs))) (msort (snd (half xs)))
