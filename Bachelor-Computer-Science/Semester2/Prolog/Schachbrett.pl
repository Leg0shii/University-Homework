spalte(a).
spalte(b).
spalte(c).
spalte(d).
spalte(e).
spalte(f).
spalte(g).
spalte(h).

zeile(1).
zeile(2).
zeile(3).
zeile(4).
zeile(5).
zeile(6).
zeile(7).
zeile(8).

nebeneinander(a, b).
nebeneinander(b, c).
nebeneinander(c, d).
nebeneinander(d, e).
nebeneinander(e, f).
nebeneinander(f, g).
nebeneinander(g, h).

linksVon(X, Y) :-
    nebeneinander(X, Y).

linksVon(X, Z) :-
    nebeneinander(Y, Z),
    linksVon(X, Y).

rechtsVon(Y, X) :-
    nebeneinander(X, Y).

rechtsVon(Z, X) :-
    nebeneinander(Y, Z),
    rechtsVon(Y, X).

uebereinander(8, 7).
uebereinander(7, 6).
uebereinander(6, 5).
uebereinander(5, 4).
uebereinander(4, 3).
uebereinander(3, 2).
uebereinander(2,1).

oberhalb(X, Y) :-
    uebereinander(X, Y).

oberhalb(X, Z) :-
    uebereinander(Y, Z),
    oberhalb(X, Y).

unterhalb(Y, X) :-
    uebereinander(X, Y).

unterhalb(Z, X) :-
    uebereinander(X, Y),
    unterhalb(Z, Y).

feld((X, Y)) :-
    spalte(X),
    zeile(Y).

nord((X1, X2), (X1, Y2)) :-
    uebereinander(Y2, X2).

nordost((X1, X2), (Y1, Y2)) :-
    uebereinander(Y2, X2),
    nebeneinander(X1, Y1).

ost((X1, X2), (Y1, X2)) :-
    nebeneinander(X1, Y1).

suedost((X1, X2), (Y1, Y2)) :-
    uebereinander(X2, Y2),
    nebeneinander(X1, Y1).

sued((X1, X2), (X1, Y2)) :-
    uebereinander(X2, Y2).

suedwest((X1, X2), (Y1, Y2)) :-
    nebeneinander(Y1, X1),
    uebereinander(X2, Y2).

west((X1, X2), (Y1, X2)) :-
    nebeneinander(Y1, X1).

nordwest((X1, X2), (Y1, Y2)) :-
    uebereinander(Y2, X2),
    nebeneinander(Y1, X1).

schwarz((a, 1)).
schwarz((c, 1)).
schwarz((e, 1)).
schwarz((g, 1)).

schwarz((X1, X2)) :-
    suedwest((X1, X2), (Y1, Y2)),
    schwarz((Y1, Y2)).

schwarz((X1, X2)) :-
    suedost((X1, X2), (Y1, Y2)),
    schwarz((Y1, Y2)).

weiss((a, 2)).
weiss((c, 2)).
weiss((e, 2)).
weiss((g, 2)).

weiss((X1, X2)) :-
    suedwest((X1, X2), (Y1, Y2)),
    weiss((Y1, Y2)).

weiss((X1, X2)) :-
    suedost((X1, X2), (Y1, Y2)),
    weiss((Y1, Y2)).

diagonal1((X1, X2), (Y1, Y2)) :-
    nordost((X1, X2), (Y1, Y2)).

diagonal1((X1, X2), (Z1, Z2)) :-
    nordost((X1, X2), (Y1, Y2)),
    diagonal1((Y1, Y2), (Z1, Z2)).

diagonal2((X1, X2), (Y1, Y2)) :-
    suedwest((X1, X2), (Y1, Y2)).

diagonal2((X1, X2), (Z1, Z2)) :-
    suedwest((X1, X2), (Y1, Y2)),
    diagonal2((Y1, Y2), (Z1, Z2)).

diagonal3((X1, X2), (Y1, Y2)) :-
    suedost((X1, X2), (Y1, Y2)).

diagonal3((X1, X2), (Z1, Z2)) :-
    suedost((X1, X2), (Y1, Y2)),
    diagonal3((Y1, Y2), (Z1, Z2)).

diagonal4((X1, X2), (Y1, Y2)) :-
    nordwest((X1, X2), (Y1, Y2)).

diagonal4((X1, X2), (Z1, Z2)) :-
    nordwest((X1, X2), (Y1, Y2)),
    diagonal4((Y1, Y2), (Z1, Z2)).

erreichbar(turm, (X1, X2), (X1, Y2)) :-
    oberhalb(X2, Y2); 
    oberhalb(Y2, X2). 

erreichbar(turm, (X1, X2), (Y1, X2)) :-
    linksVon(X1, Y1); 
    linksVon(Y1, X1).

erreichbar(laeufer, (X1, X2), (Y1, Y2)) :-
    diagonal1((X1, X2), (Y1, Y2)).

erreichbar(laeufer, (X1, X2), (Y1, Y2)) :-
    diagonal2((X1, X2), (Y1, Y2)).

erreichbar(laeufer, (X1, X2), (Y1, Y2)) :-
    diagonal3((X1, X2), (Y1, Y2)).

erreichbar(laeufer, (X1, X2), (Y1, Y2)) :-
    diagonal4((X1, X2), (Y1, Y2)).

erreichbar(dame, (X1, X2), (Y1, Y2)) :-
    erreichbar(turm, (X1, X2), (Y1, X2)),
    erreichbar(laeufer, (X1, X2), (Y1, Y2)).

erreichbar(koenig, (X1, X2), (Y1, Y2)) :-
    nord((X1, X2), (Y1, Y2));
    sued((X1, X2), (Y1, Y2));
    ost((X1, X2), (Y1, Y2));
    west((X1, X2), (Y1, Y2));
    nordost((X1, X2), (Y1, Y2));
    nordwest((X1, X2), (Y1, Y2));
    suedost((X1, X2), (Y1, Y2));
    suedwest((X1, X2), (Y1, Y2)).

erreichbar(springer, (X1, X2), (Y1, Y2)) :-
    weiss((X1, X2)),
    erreichbar(koenig, (X1, X2), (Z1, Z2)),
    erreichbar(koenig, (Z1, Z2), (Y1, Y2)),
    schwarz((Y1, Y2)).

erreichbar(springer, (X1, X2), (Y1, Y2)) :-
    schwarz((X1, X2)),
    erreichbar(koenig, (X1, X2), (Z1, Z2)),
    erreichbar(koenig, (Z1, Z2), (Y1, Y2)),
    weiss((Y1, Y2)).





