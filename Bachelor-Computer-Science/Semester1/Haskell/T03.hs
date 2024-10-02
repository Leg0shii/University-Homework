max2Floats :: (Float, Float) -> Float
max2Floats (a, b) = if a < b then b else a

min2Floats :: (Float, Float) -> Float
min2Floats (a, b) = if a < b then a else b

add2Floats :: (Float, Float) -> Float
add2Floats (a, b) = a + b

add3Floats :: (Float, Float, Float) -> Float
add3Floats (a, b, c) = a + b + c

mult2Floats :: (Float, Float) -> Float
mult2Floats (a, b) = a * b

mult3Floats :: (Float, Float, Float) -> Float
mult3Floats (a, b, c) = a * b * c

add2FloatsC :: Float -> (Float -> Float)
add2FloatsC a b = a + b

add3FloatsC :: Float -> (Float -> (Float -> Float))
add3FloatsC a b c = a + b + c

lengthFloats :: [Float] -> Int
lengthFloats [] = 0
lengthFloats (a:as) = 1 + lengthFloats as

sumFloat :: [Float] -> Float
sumFloat [] = 0
sumFloat(a:as) = a + sumFloat as

productFloat :: [Float] -> Float
productFloat [] = 1
productFloat(a:as) = a * sumFloat as

minimumFloats :: [Float] -> Float
minimumFloats [] = 100
minimumFloats (a:as) = if a > minimumFloats as
  then minimumFloats as
  else a

maximumFloats :: [Float] -> Float
maximumFloats [] = 0
maximumFloats (a:as) = if a > maximumFloats as
  then a
  else maximumFloats as

bin2int :: [Int] -> Int
bin2int [] = 0
bin2int [0] = 0
bin2int [1] = 1
bin2int (a:as) = a*2^length(as) + bin2int as

int2bin :: Int -> [Int]
int2bin 0 = [0]
int2bin 1 = [1]
int2bin x = if x `mod` 2 /= 0
  then 1 : int2bin (x `div`2)
  else 0 : int2bin (x `div`2)

sumBins :: ([Int], [Int]) -> [Int]
sumBins (as,bs) = int2bin((bin2int as) + (bin2int bs))
