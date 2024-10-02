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

ripleCarry([], [Y|Yrest], Ci, [Z|Zrest]) :-
    addDigit(0, Y, Ci, Z, Co),
    ripleCarry([], Yrest, Co, Zrest).
ripleCarry([X|Xrest], [], Ci, [Z|Zrest]) :-
    addDigit(X, 0, Ci, Z, Co),
    ripleCarry(Xrest, [], Co, Zrest).
ripleCarry([X|Xrest], [Y|Yrest], Ci, [Z|Zrest]) :-
    addDigit(X, Y, Ci, Z, Co),
    ripleCarry(Xrest, Yrest, Co, Zrest).

add(X, Y, Zs) :-
    reverse(X, Xs),
    reverse(Y, Ys),
    ripleCarry(Xs, Ys, 0, Z),
    reverse(Z, Zs).
