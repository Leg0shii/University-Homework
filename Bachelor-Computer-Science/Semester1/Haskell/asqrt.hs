asqrt a x = a : asqrt ((a + (x/a))/2) x
stop eps (a : a': as) = if ((a - a') < eps) then a' else stop eps as 
