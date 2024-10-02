nor :: Bool -> Bool -> Bool
nor False False = True
nor _ _ = False

factorSum :: Int -> Int
factorSum k = sum[n |n <- [1..k-1], k `mod` n == 0]

perfekt :: Int -> [Int]
perfekt k = [n |n <- [1..k], factorSum n == n]
