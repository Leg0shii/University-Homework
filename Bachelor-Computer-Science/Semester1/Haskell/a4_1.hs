oder :: Bool -> Bool -> Bool
oder False False = False
oder _ _ = True

fst3 :: (a,a,a) -> a
fst3 (a,_,_) = a

oneOfFour :: Int -> (a,a,a,a) -> a
oneOfFour n (a, b, c, d)
    | n == 1 = a
    | n == 2 = b
    | n == 3 = c
    | n == 4 = d

countNumOccurrences :: Char -> [Char] -> Int
countNumOccurrences a xs = sum[1 | n <- xs, n == a]

ggt ::(Int, Int) -> Int
ggt (0,0) = error "Nicht definiert"
ggt (x,y) = if x == 0 then y else ggt(y `mod` x, x)

kuerzen :: (Int, Int) -> (Int, Int)
kuerzen (x,y) = (x `div` (ggt(x,y)), y `div` (ggt(x,y)))

kuerzen' :: (Int, Int) -> (Int, Int)
kuerzen' (x,y) = (x `div` g, y `div` g)
    where g = ggt(x,y)


kuerzen'' :: (Int, Int) -> (Int, Int)
kuerzen'' (x,y) = 
    let g = ggt(x,y) 
    in (x `div` g, y `div` g)

bin2Int :: [Int] -> Int
bin2Int [] = error "Leer"
bin2Int [0] = 0
bin2Int [1] = 1
bin2Int (x:xs) = x * 2^(length xs) + bin2Int xs

int2bin :: Int -> [Int]
int2bin 0 = [0]
int2bin 1 = [1]
int2bin n = if n `mod` 2 == 0 then (int2bin (n `div` 2)) ++ [0] else (int2bin (n `div` 2)) ++ [1]

sumBins :: ([Int], [Int]) -> [Int]
sumBins (xs,ys) = int2bin (bin2Int xs + bin2Int ys)