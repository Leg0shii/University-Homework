type Person = String
type Book = String
type Database = [(Person, Book)]

meineDB :: Database
meineDB = [("Pers1", "Eins"), ("", "Zwei"), ("Pers3", ""), ("", "Vier"), ("Pers5", "Fuenf"), ("Pers6", "Sechs")]

amountB :: Book -> Database -> Int
amountB b xs = sum[1| n <- xs, snd n == b]
amountP :: Person -> Database -> Int
amountP p xs = sum[1| n <- xs, fst n == p]

checkB :: Book -> Database -> Bool
checkB b xs = sum[1 | n <- xs, snd n == b && fst n /= ""] > 0
checkP :: Person -> Database -> Bool
checkP p xs = sum[1 | n <- xs, fst n == p && snd n /= ""] > 0

borrowed :: Book -> Database -> (Bool, Int)
borrowed b xs = if (checkB b xs) then (True, amountB b xs) else (False, 0)

numBorrowed :: Person -> Database -> (Bool, Int)
numBorrowed p xs = if (checkP p xs) then (True, amountP p xs) else (False, 0)

returnLoad :: Database -> Person -> Book -> Database
returnLoad xs p b = filter (/=(p,b)) xs


calcT f = (\x -> f) f True
calcF f = (\x -> f) f False
showBool f = "f(True) = " ++ show(calcT f) ++ ", f(False) = " ++ show(calcF f)

concatL xs = putStr((foldr (++) "" xs) ++ "\n")
concatL' xs = putStr((foldl (++) "" xs) ++ "\n")

cProd xs ys = concat $ map (\y -> map (\x -> (x, y)) xs) ys
