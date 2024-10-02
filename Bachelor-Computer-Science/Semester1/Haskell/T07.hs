type Spielfeld = [Int]

perms :: Eq a => [a] -> [[a]]
perms [a] = [[a]]
perms xs = [x:l | x <- xs, l <- perms (filter (/= x) xs)]

permsN n = perms [1..n]

projectPos :: Int -> Int -> [Int]
projectPos n offs = [n+offs,n+2*offs..]

noDiagonalHit :: Int -> Int -> Spielfeld -> Bool
noDiagonalHit x o ys = null $ filter (\(x,y) -> x==y) $ zip ys (projectPos x o)

allQueens :: Int -> [Spielfeld]
allQueens n = [k | k <- permsN n, valid k]

allQueensSum n = sum[1 | k <- permsN n, valid k]

valid :: Spielfeld -> Bool
valid [] = True
valid (x:xs) = valid xs && noDiagonalHit x 1 xs && noDiagonalHit x (-1) xs

queensN :: Int -> Spielfeld
queensN n = head (allQueens n)

queens :: Spielfeld
queens = queensN 8

showSolution' :: Spielfeld -> Int -> String
showSolution' [] _ = ""
showSolution' (x:xs) n = show x ++ " | " ++ take (2*x) (repeat ' ')  ++ "X" ++ take (2*n-(2*x)) (repeat ' ') ++ " | \n" ++ showSolution' xs n

showSolution [] = ""
showSolution xs = showSolution' xs (length(xs))

printSolution xs = putStr (showSolution xs)

solve n = do
  putStr ("Fuer das " ++ show n ++ "-Damen-Problem gibt es " ++ show (allQueensSum n) ++ " Loesungen.\n")
  putStr ("Geben Sie eine Zahl x mit 0 ≤ x < " ++ show (allQueensSum n) ++ " ein: ")
  z <- getLine
  putStr ("\n")
  printSolution ((allQueens n)!!read z)

