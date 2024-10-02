append([], RL) :-
	append([], [], RL).
	
append([X], RL) :-
	append(X, [], RL).
	
append([X|LS], RL) :-
	append(X, RLL, RL),
	append(LS, RLL).
	
filter([], Ys) :-
	append([], [], Ys).
	
filter([_], Ys) :-
	append([], [], Ys).
	
filter([_,Y|Xs], Ys) :-
	append([Y], Ys1, Ys),
	filter(Xs, Ys1).
	
fak(0, 1) :- !.
fak(N, F) :-
	N > 0,
	N1 is N - 1,
	fak(N1, F1),
	F is N * F1.