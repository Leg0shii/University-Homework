factors ::Integer->[Integer]
factors n = [t | t <- [1..n], n `mod`t == 0]

prime :: Integer -> Bool
prime n = factors n == [1,n]

primes :: Integer -> [Integer]
primes n = [x | x <- [2..n], prime x]
