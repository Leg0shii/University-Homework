hello(world).
hello(hello(X)) :- hello(X).

on(a,1).
on(1,2).
on(b,3).
on(c,4).
on(4,5).
on(5,6).
on(6,7).

above(X,Y) :- on(X,Y).
avove(X,Y) :- on(Z,Y), above(X,Z).