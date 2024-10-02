data Tree = TNode Int [Tree] | TLeaf Int

sumLeaves :: Tree -> Int
sumLeaves (TLeaf n) = n
sumLeaves (TNode n t) = n + sumLeaves (t!!0) + sumLeaves (t!!1)

mapLeaves (TLeaf n) f = (TLeaf (f n))
mapLeaves (TNode n t) f = (TNode (f n)) ((mapLeaves (t!!0) f):(mapLeaves (t!!1) f))

invertLeafs t = mapLeaves t (*(-1))
