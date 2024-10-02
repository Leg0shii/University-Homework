module U6 where
import Data.Char

let2int a = (fromEnum a) - (fromEnum 'a')
int2let a = (chr (a + (fromEnum 'a')))

shift a b = if (let2int(a) > -1 && let2int(a) < 26) then int2let((let2int a + b)`mod`26) else a

encode :: Int -> String -> String
encode a s = [shift n a | n <- s]

rotate :: Int -> [a] -> [a]
rotate a s = drop a s ++ take a s
  where a' = a `mod`(length s)

count :: Eq a => a -> [a] -> Int
count c s = sum[1 | n <- s, n == c]

positions :: Eq a => a -> [a] -> [Int]
positions c s = [i | (c',i) <- zip s[0..], c == c']

lowers :: String -> Int
lowers s = sum[1 | n <- s, isLower n]

freqs1 xs = [positions i "abcdefghijklmnopqrstuvwxyz" | i <- xs]
freqs xs = [i | (i,x) <- zip (freqs1 xs) [0..25]]
