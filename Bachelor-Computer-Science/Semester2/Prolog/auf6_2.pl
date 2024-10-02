wahr(V, B) :-
    member(V, B).

wahr(and(V1, V2), B) :-
    wahr(V1, B), !,
    wahr(V2, B).

wahr(or(V1, V2), B) :-
    wahr(V1, B);
    wahr(V2, B).

wahr(imp(V1, V2), B) :-
    wahr(and(V1, V2), B);
    not(wahr(V1, B)).

wahr(eq(V1, V2), B) :-
    wahr(and(V1, V2), B);
    not(wahr(V1, B)),
    not(wahr(V2, B)).

variablen(_, []) :- fail.

variablen(F, V) :-
    member(F, V).

variablen(and(F1, F2), V) :-
    variablen(F1, V), !,
    variablen(F2, V).

variablen(or(F1, F2), V) :-
    variablen(F1, V), !,
    variablen(F2, V).

wert(F, B, wahr) :-
    wahr(F, B).
wert(F, B, falsch) :-
    not(wahr(F, B)).

model(F, B) :-
    wert(F, B, wahr).

