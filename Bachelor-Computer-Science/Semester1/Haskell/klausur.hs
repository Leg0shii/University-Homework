type Patient = String
type Medikament = String
type Dosis = Float
type Zimmer = Int
type ZimmerBelegung = [(Patient, Zimmer)]
type Medikation = [(Patient, Medikament, Dosis)]


med xs p = filter (\(_,a,_) -> a == p) xs
medikation xs p = map (\(a,b,c) -> (a,c)) (med xs p)

zimmerMed1 zb m z = filter (\(_,a) -> a == z) zb
zim zb m z = map (\(a,b) -> a) (zimmerMed1 zb m z)
zimmerMed zb m z = medikation m (head (zim zb m z))


maximum1 [x] = x
maximum1 (x:xs)
  | (maximum1 xs) > x = maximum1 xs
  | otherwise = x

minimum1 [x] = x
minimum1 (x:xs)
  | (minimum1 xs) < x = minimum1 xs
  | otherwise = x
