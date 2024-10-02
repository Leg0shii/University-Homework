teile_liste([], [], []).
teile_liste([A], [A], []).
teile_liste([A,B], [A], [B]).
teile_liste([A,B|L], [A|A1], [B|B1]) :-
    teile_liste(L, A1, B1).

p([],[]).
p([X|Xs], [X|Ys]) :-
    p(Xs, Ys).
p([Xs], [_|Ys]) :-
    p(Xs, Ys).   

filter_list([], []).
filter_list([A], [A]).
filter_list([A,_], [A]).
filter_list([A,_|L], [A|A1]) :-
    filter_list(L, A1).


fSort([], []).
fSort([A], [freq(A, 1)]).

fSort(Liste, [freq(X, N)|Erest]) :-
    msort(Liste, [X|SortList]),
    fSort(SortList, [freq(X, N1)|Erest]),
    N is N1 + 1.

fSort(Liste, [freq(X,0)|Erest]) :-
    msort(Liste, [Y|SortList]),
    !, X \= Y,
    fSort([Y|SortList], Erest).

fSort(Liste, [freq(X,0), freq(Y, N)|Erest]) :-
    msort(Liste, [Y|SortList]),
    X \= Y,
    fSort(SortList, [freq(Y,N1)|Erest]),
    N is N1 + 1.


