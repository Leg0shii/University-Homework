//Andre Doll - Mnr: 219202813
//Benjamin Mueller - Mnr: 219203075
//Daniel Passauer - Mnr: 219202806
//Magomed Arsaev - Mnr: 219203666
//Mats Krobitzsch - Mnr: 219202911

factor :: Int -> [Int]
factor n = [x | x <- [1..(n-1)], n`mod`x == 0]

perfekt :: Int -> [Int]
perfekt n = [x | x <- [1..n], sum (factor x) == x]
