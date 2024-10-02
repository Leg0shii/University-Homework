produkt("apfel", kat(essen, obst), 2.0).
produkt("birne", kat(essen, obst), 3.0).

alleProd(K, Ps) :-
    findall(X, produkt(X, kat(K, _), _), Ps).

renameUK(K, UKold, UKnew) :-
    retract( produkt(A, kat(K, UKold), B) ),
    assert( produkt(A, kat(K, UKnew), B) ).


prodP([(A,B)], Ys) :-
    C is A * B,
    append([C], [], Ys).
prodP([(A,B)|Xs], Ys) :-
    C is A * B,
    append([C], Ys1, Ys),
    prodP(Xs, Ys1).

s1 --> a,s1,d.
s1 --> [].
s --> b,b,s,c,c.
s --> [].
s --> s1.
a --> [a].
b --> [b].
c --> [c].
d --> [d].

muendet_in(warnow , ostsee).
muendet_in(nebel, warnow).
muendet_in(loessnitz , nebel).
einzug(X, Y) :- muendet_in(X, Y).
einzug(X, Y) :- muendet_in(X, Z), einzug(Z, Y).

rechnung --> posten(X), [Y], [total],{!,Y==X}.
posten(X) --> [buch], [X], [';'], {integer(X)}.
posten(X1) --> [return], [X], [';'], {X1 is X*(-1),integer(X)}.
posten(X) --> [pflanze], [X], [';'], {integer(X)}.
posten(X)--> posten(X1), posten(X2), {X is X2 + X1}.

start --> term(X), {integer(X)}.
term(X) --> factor(X1), [*], term(X2), {X is X1 * X2}.
term(X) --> factor(X1), [/], term(X2), {X is X1 / X2}. 
term(X) --> factor(X).
factor(X) --> [X], { integer(X) }.
