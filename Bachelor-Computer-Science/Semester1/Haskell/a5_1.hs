gra = [\x y -> x + y, \x y -> x - y, \x y -> x * y, \x y -> x / y]
gra' = [(+), (-), (*), (/)]

gz = [n | n <- [1..20], n`mod`2 == 0]
gz' s e d = [n | n <- [s..e], n`mod`d == 0]

teiler x = [n | n <- [1..x], x`mod`n == 0]

skalarprodukt xs ys = sum[x*y | (x,y) <- zip xs ys]

pyth n = [(x,y,z) | x <- [1..n], y <- [1..n], z <- [1..n], check x y z]
    where check x y z = x*x + y*y == z*z && x <= y && y <= z

applyAll a b f = [k a b | k <- f]

merge :: Ord a => [a] -> [a] -> [a]
merge [] [] = []
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys) = if x <= y 
    then x : merge xs (y:ys) 
    else y : merge (x:xs) ys

half :: Ord a => [a] -> ([a],[a])
half [] = ([],[])
half [x] = ([x],[])
half (x:y:zs) = (x:xs, y:ys)
    where (xs, ys) = half zs

msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
msort xs = merge (msort (fst (half xs))) (msort (snd (half xs)))