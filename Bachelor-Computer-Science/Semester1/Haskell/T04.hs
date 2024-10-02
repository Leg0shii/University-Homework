oder :: Bool -> Bool -> Bool
oder False False = False
oder _ _ = True

fst3 :: (a,b,c) -> a
fst3 (x,_,_) = x

oneOfFour :: Int -> (a,a,a,a) -> a
oneOfFour n (a1,a2,a3,a4)
  | n == 1 = a1
  | n == 2 = a2
  | n == 3 = a3
  | n == 4 = a4

cno :: Eq a => a -> [a] -> Int
cno _ [] = 0
cno a (e:es)
  | a == e = 1 + n
  | otherwise = n
  where
  n = cno a es


ggt :: (Int, Int) -> Int
ggt (x,y)
  | x == 0 && y == 0 = error "Nicht definiert"
  | x == 0 = y
  | otherwise = ggt(y `mod` x, x)


kuerzen :: (Int, Int) -> (Int, Int)
kuerzen (x,y) = (x`div`g,y`div`g)
  where g = ggt (x,y)

lengthInts :: [Int] -> Int
lengthInts [] = 0
lengthInts (e:es) = 1 + (lengthInts es)

bin2int :: [Int] -> Int
bin2int [] = 0
bin2int (e:es) = (2^(lengthInts es)*e)+(bin2int es)
