lengthInts :: [Int] → Int
lengthInts [] = 0
lengthInts (e:es) = 1 + (lengthInts es)

bin2int :: [Int] -> Int
bin2int = [] = 0
bin2int (e:es) = if e == 1 then e*2 else e*2
