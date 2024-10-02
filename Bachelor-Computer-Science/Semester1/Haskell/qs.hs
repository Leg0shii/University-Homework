qs [] = []
qs (h : hs) = qs hl ++ [h] ++ qs hg
  where hl = [a | a <- hs, a < h]
        hg = [b | b <- hs, b > h]

mappp f = foldr ((:) .f) []

anyyy f [] = False
anyyy f xs = or(map f xs)

summe xs = foldr (+) 0 xs
