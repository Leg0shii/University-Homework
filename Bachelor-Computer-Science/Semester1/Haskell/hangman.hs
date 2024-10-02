import System.IO

hangman :: IO ()
hangman = do
  putStr "Ratewort? "
  word <- sgetLine
  putStrLn "Geben Sie Ihre Vorschläge ein:"
  guess word

sgetLine1 = do
  x <- getChar
  if x == '\n'
    then do
      putChar x
      return []
    else do
      putChar '*'
      xs <- sgetLine1
      return (x:xs)

sgetLine :: IO String
sgetLine = do
  hSetEcho stdin False
  xs <- sgetLine1
  hSetEcho stdin True
  return xs

guess :: String -> IO()
guess w = do
  w' <- getLine
  if w == w'
    then putStrLn "Richtig geraten!"
    else do
      putStrLn (hits w w')
      guess w

filterS a s = sum[1 | n <- s, a == n] >= 1

hits :: String -> String -> String
hits w w' = [if (filterS c w') then c else '-' | c <- w]
