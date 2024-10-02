double x = x + x

sieve (p:ns) = p : sieve [n | n <- ns, n `mod` p /= 0]
primes = sieve [2..]

half x = x / 2
half' x = x `div` 2

nthprime n = primes!!(n-1)

nhalf 0 = 0
nhalf 1 = 0
nhalf x = 1 + nhalf (x `div` 2)
