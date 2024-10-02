menge :: Int -> [Int]
menge x = [n^2 | n <- [1..x], n`mod`2 == 0]
