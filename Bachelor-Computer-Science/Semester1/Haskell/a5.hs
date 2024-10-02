data Op = Add | Sub | Mul | Div deriving (Eq)

instance Show Op where
  show Add = "+"
  show Sub = "-"
  show Mul = "*"
  show Div = "/"


data Expr = Val Int | App Op Expr Expr deriving (Eq)

instance Show Expr where
  show (Val n) = show n
  show (App o l r) = brak l ++ show o ++ brak r
    where brak (Val n) = show n
          brak e = "(" ++ show e ++ ")"


values :: Expr -> [Int]
values (Val n) = [n]
values (App _ l r) = values l ++ values r


valid :: Op -> Int -> Int -> Bool
valid op z1 z2
  | op == Add = True
  | op == Mul = True
  | (op == Sub && ((z1 - z2) >= 0)) = True
  | (op == Div && (z1 `mod` z2 == 0)) = True
  | otherwise = False

apply :: Op -> Int -> Int -> Int
apply op z1 z2
  | op == Add = z1 + z2
  | op == Mul = z1 * z2
  | op == Sub && valid op z1 z2 = z1 - z2
  | op == Div && valid op z1 z2 = z1 `div` z2
  | otherwise = 0

eval2 (Val x) = x
eval2 (App op x y)
  | valid op (eval2 x) (eval2 y) = apply op (eval2 x) (eval2 y)
  | otherwise = -10

eval e
  | eval2 e > -1 = Just (eval2 e)
  | otherwise = Nothing
