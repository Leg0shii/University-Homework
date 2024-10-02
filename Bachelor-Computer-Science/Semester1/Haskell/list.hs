lengthFloats :: [Float] -> Int
lengthFloats [] = 0
lengthFloats (e:es) = 1 + (lengthFloats es)

productFloats :: [Float] -> Float
productFloats [] = 1
productFloats (e:es) = e * productFloats es


minElem::[Int]->Int
minElem [] = 0
minElem [x] = x
minElem (x:y:xs)
 |x > y = minElem (y:xs)
 |x < y = minElem (x:xs)
 |x == y = minElem (x:xs)

maxElem::[Int]->Int
maxElem [] = 0
maxElem [x] = x
maxElem (x:y:xs)
 |x < y = maxElem (y:xs)
 |x > y = maxElem (x:xs)
 |x == y = maxElem (x:xs)
