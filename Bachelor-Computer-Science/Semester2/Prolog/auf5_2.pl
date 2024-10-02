addDigit(0, 0, 0, 0, 0).
addDigit(0, 1, 0, 1, 0).
addDigit(1, 0, 0, 1, 0).
addDigit(1, 1, 0, 0, 1).
addDigit(0, 0, 1, 1, 0).
addDigit(0, 1, 1, 0, 1).
addDigit(1, 0, 1, 0, 1).
addDigit(1, 1, 1, 1, 1).


ripleCarry([], [], 0, []).
ripleCarry([], [], 1, [1]).

ripleCarry([-], [-], 0, [-]).
ripleCarry([-], [-], 1, [1,-]).
ripleCarry([-], [], 0, [-]).
ripleCarry([], [-], 0, [-]).
ripleCarry([-], [], 1, [1,-]).
ripleCarry([], [-], 1, [1,-]).

ripleCarry([], [Y|Yrest], Ci, [Z|Zrest]) :-
    addDigit(0, Y, Ci, Z, Co),
    ripleCarry([], Yrest, Co, Zrest).
ripleCarry([X|Xrest], [], Ci, [Z|Zrest]) :-
    addDigit(X, 0, Ci, Z, Co),
    ripleCarry(Xrest, [], Co, Zrest).
ripleCarry([X|Xrest], [Y|Yrest], Ci, [Z|Zrest]) :-
    addDigit(X, Y, Ci, Z, Co),
    ripleCarry(Xrest, Yrest, Co, Zrest).

add(X, Y, Z) :-
    reverse(X, Xs),
    reverse(Y, Ys),
    ripleCarry(Xs, Ys, 0, Zs),
    reverse(Zs, Z).

intadd([-|Xs], [-|Ys], [-|Zs]) :-
    add(Xs, Ys, Zs).

intadd(X, Y, Z) :-
    add(X, Y, Z).

intadd(X, Y, Z) :-
    length(X, Int1),
    length(Y, Int2),
    Int1 < Int2,
    add(Z, X, Y).

intadd(X, Y, Z) :-
    X < Y, 
    add(Z,Y,X).



