


name2mat :: [[Char]] -> [Int] -> [([Char],Int)]
name2mat [] _ = []
name2mat _ [] = []
name2mat (a:as) (b:bs) = (a,b) : name2mat as bs

sortKVLk :: Ord a => Ord b => [(a,b)] -> [(a,b)]
sortKVLk [] = []
sortKVLk ((k,z):t) = sortKVLk [ a | a <- t, snd a < z || if snd a == z && a <= (k,z) then True else False ]
                ++ [(k,z)]
                ++ sortKVLk [ b | b <- t, snd b > z || if snd b == z && b > (k,z) then True else False ]
