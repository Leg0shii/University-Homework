liebt(siegfried, krimhild).
liebt(krimhild, siegfried).
liebt(gunther, brunhild).

mag(siegfried, gunther).
mag(gunther, krimhild).
mag(gunther, hagen).
mag(brunhild, hagen).
mag(brunhild, alberich).

hasst(krimhild, gunther).
hasst(brunhild, siegfried).
hasst(brunhild, gunther).
hasst(brunhild, krimhild).
hasst(hagen, siegfried).
hasst(hagen, krimhild).
hasst(alberich, krimhild).
hasst(alberich, siegfried).
hasst(alberich, brunhild).
hasst(alberich, hagen).
hasst(alberich, gunther).

idealesPaar(X,Y) :-
    liebt(X,Y),
    liebt(Y,X).