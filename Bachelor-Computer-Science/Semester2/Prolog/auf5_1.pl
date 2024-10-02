add(0, Y, Y).
add(s(X), Y, s(Z)) :- add(X, Y, Z).

mul(0, _, 0).
mul(s(X), Y, Z) :- mul(X, Y, P), add(P, Y, Z).

sub(X, Y, Z) :- add(Z, Y, X).

%i)
%add(s(s(0)), s(s(0)), S).
%->add(s(0), s(s(0)), s(S))
%->add(0, s(s(0)), s(s(S)))
%->L -> s(s(s(s(0)))).

%ii)

%iii)
%sub(X, s(s(s(0))), s(0))
%->add(s(0), s(s(s(0))), X)
    %-> add(0, s(s(s(0))), s(X))
    %-> X -> (s(s(s(s(0)))))