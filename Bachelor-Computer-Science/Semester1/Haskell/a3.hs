name2mat :: [(String,Int)]
name2mat = [("PersonEins",1111),("PersonZwei",1111),("PersonDrei",7333),("PersonVier",1444)]

sortKVLk :: [(String, Int)] -> [(String, Int)]
sortKVLk [] = []
sortKVLk (x:xs) = sortKVLk xl ++ [x] ++ sortKVLk xr
  where xl = [a |a <- xs, snd a < snd x || (snd a == snd x && (fst a < fst x))]
        xr = [b | b <- xs, snd b > snd x || (snd b == snd x && (fst b > fst x))]

mapValues :: ((a, b1) -> b2) -> [(a, b1)] -> [(a, b2)]
mapValues f xs = [(fst x, f x) | x <- xs]

findKeys :: Eq b => [(a,b)] -> b -> [a]
findKeys xs n = [fst x | x <- xs, snd x == n]
