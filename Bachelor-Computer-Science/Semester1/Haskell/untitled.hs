lengthFloats :: [Float] -> Int
lengthFloats [] = 0
lengthFloats (e:es) = 1 + (lengthFloats es)