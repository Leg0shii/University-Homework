farbe(rot).
farbe(blau).
farbe(gelb).
farbe(gruen).

nachbar(X, Y) :- 
    farbe(X), 
    farbe(Y), 
    X \= Y.

karte(A, B, C, D, E, F) :-
    nachbar(A, B), 
    nachbar(A, D), 
    nachbar(B, D), 
    nachbar(B, C),
    nachbar(B, E),
    nachbar(C, F),
    nachbar(C, E),
    nachbar(D, E),
    nachbar(E, F).
