type Spielfeld = [Int]

perms :: Eq a => [a] -> [[a]]
perms [a] = [[a]]
perms xs = [x:l | x <- xs, let xs' = filter (/= x) xs, l <- perms xs']

projectPos :: Int -> Int -> [Int]
projectPos n offs = [n+offs,n+2*offs..]

noDiagonalHit :: Int -> Int -> Spielfeld -> Bool
noDiagonalHit x o ys = null $ filter (\(x,y) -> x==y) $ zip ys (projectPos x o)

queens :: Spielfeld
queens = queensN 8

queensN :: Int -> Spielfeld
queensN n = head (allQueens n)

allQueens :: Int -> [Spielfeld]
allQueens n = [sol | sol <- perms [1..n], valid sol]

valid :: Spielfeld -> Bool
valid [] = True
valid (x:xs) = valid xs && noDiagonalHit x 1 xs && noDiagonalHit x (-1) xs
