lengthInts :: [Int] -> Int
lengthInts [] = 0
lengthInts (e:es) = 1 + (lengthInts es)

bin2int :: [Int] -> Int
bin2int [] = 0
bin2int (e:es) = (2^(lengthInts es)*e)+(bin2int es)

int2bin :: Int -> [Int]
int2bin a
  | (a == 0) = []
  | (a `mod` 2) == 1 = [1]++(int2bin (((a-1)`div`2)))
  | (a `mod` 2) == 0 = [0]++(int2bin (a`div`2))

sumBins :: ([Int], [Int]) -> [Int]
sumBins ((e:es),(a:as))  = int2bin(bin2int (e:es) + bin2int (a:as))
