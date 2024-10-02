kleiner_als :: Ord a => a -> [a] -> [a]
kleiner_als [] = []
kleiner_als a (b:bs) = [n | n <- b, b < 5]
