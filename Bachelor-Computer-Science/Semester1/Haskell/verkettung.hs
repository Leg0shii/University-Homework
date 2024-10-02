a = do
  x <- getChar
  getChar
  y <- getChar
  return (x,y)

strlen = do
  xs <- getLine
  putStr(show(length xs))
  putStrLn " Zeichen."
