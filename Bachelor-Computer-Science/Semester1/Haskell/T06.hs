module U6 where
import Data.Char

let2int a = (fromEnum a) - (fromEnum 'a')
int2let a = (chr (a + (fromEnum 'a')))

shift a b = if (let2int(a) > -1 && let2int(a) < 26) then int2let((let2int a + b)`mod`26) else a

encode :: Int -> String -> String
encode a s = [shift n a | n <- s]

encode' :: Int -> String -> String
encode' a s = [int2let k | k <- (map (+a) [let2int n | n <- s])]

rotate a s = drop a s ++ take a s
  where a' = a `mod`(length s)

count :: Eq a => a -> [a] -> Float
count c s = sum[1 | n <- s, n == c]
count' c xs = length (filter (==c) xs)

positions :: Eq a => a -> [a] -> [Int]
positions c s = [i | (c',i) <- zip s[0..], c == c']

lowers :: String -> Int
lowers s = sum[1 | n <- s, isLower n]

length' :: [a] -> Float
length' [] = 0
length' (x:xs) = 1 + length' xs

freqs xs = [100*(count a xs)/length' xs | a <- "abcdefghijklmnopqrstuvwxyz"]

chisqr :: [Float] -> [Float] -> Float
chisqr xs ys = sum[((x-y)*(x-y))/y | (x,y) <- zip xs ys]

table :: [Float]
table = [8.2,1.5,2.8,4.3,12.7,2.2,2.0,6.1,7.0,0.2,0.8,4.0,2.4,6.7,7.5,1.9,0.1,6.0,6.3,9.1,2.8,1.0,2.4,0.2,2.0,0.1]

table1 = [1,2,3]

minNum [] = 10000
minNum (x:xs) = if x > minNum xs then minNum xs else x

bestOffset xs = sum(positions (minNum off) off)
  where off = [chisqr (rotate n (freqs xs)) table | n <- [0..25]]

decode xs = encode (bestOffset xs) xs
