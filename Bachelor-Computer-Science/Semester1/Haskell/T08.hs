showEntries xs = showEntries' (paarString xs)

paarString xs = zip [1,2..] (xs)

showEntries' [] = return ()
showEntries' ((x,y):xs) = do
  putStr (show x)
  putStrLn (". " ++ y)
  showEntries' xs

readString :: IO String
readString = do
  c <- getLine
  return c

readInt :: IO Int
readInt = do
  i <- getLine
  return (read i)

menu :: [String] -> IO String
menu xs = do
  showEntries xs
  z <- getLine
  return (xs!!((read z)-1))
