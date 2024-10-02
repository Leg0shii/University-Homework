teile_liste([X], LLS, []) :-
append([X], [], LLS).

teile_liste([X,Y], LLS, RLS) :-
append([X], [], LLS),
append([Y], [], RLS).

teile_liste([X,Y|LIST], LLS, RLS) :-
append([X], LLS_, LLS),
append([Y], RLS_, RLS),
teile_liste(LIST, LLS_, RLS_).

p([],[]).
 
p([X|Xs],[X|Ys]) :- 
	p(Xs,Ys).
	
p(Xs,[_|Ys]) :-
	p(Xs,Ys).