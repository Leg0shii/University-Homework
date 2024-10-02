zustand(z0).
zustand(z1).
zustand(z2).
zustand(z3).

alphabet(a).
alphabet(b).
alphabet(blanc).

kopfBewegung(+).

delta(z0, a, z1, blanc, +).
delta(z0, b, z2, blanc, +).
delta(z0, blanc, z3, a, +).
delta(z1, a, z0, blanc, +).
delta(z2, b, z0, blanc, +).

konfiguration(z0, [X,blanc], [blanc]) :-
    alphabet(X).

konfiguration(Z, [X|Xrest], [blanc]) :-
    alphabet(X),
    zustand(Z),
    konfiguration(Z, Xrest, [blanc]).

konfiguration(Z, [blanc], [Y,blanc]) :-
    alphabet(Y),
    zustand(Z).

konfiguration(Z, [blanc], [Y|Yleft]) :-
    alphabet(Y),
    zustand(Z),
    konfiguration(Z, [blanc], Yleft).
    
konfiguration(Z, [X|Xrest], [Y|Yleft]) :-
    alphabet(X),
    alphabet(Y),
    zustand(Z),
    konfiguration(Z, Xrest, Yleft).

konfiguration(Z, [blanc], [blanc]) :-
    zustand(Z).

konfiguration(Z, [], [Y|Yleft]) :-
    zustand(Z),
    alphabet(Y),
    konfiguration(Z, [], Yleft).

konfiguration(Z, [X|Xrest], []) :-
    alphabet(X),
    zustand(Z),
    konfiguration(z0, Xrest, []).

konfiguration(Z, [], []) :-
    zustand(Z).

step((Z1, [X1|Xrest], [Y|Yleft]), (Z2, Xrest, [X3, Y|Yleft])) :-
    konfiguration(Z1, [X1|Xrest], [Y|Yleft]),
    konfiguration(Z2, Xrest, [X3, Y|Yleft]),
    delta(Z1, X1, Z2, X3, _).

compute(X, Y) :-
    step(X, Y).

compute(X, Z) :-
    step(X, Y),
    compute(Y, Z).

init(Start, (z0, Start, [blanc])).
result(End, (Z, [], End)) :-
    zustand(Z).

simulate(Eingabe, Ausgabe) :-
    init(Eingabe, X),
    compute(X, Y),
    result(Ausgabe, Y).