fact(0, 1).
fact(1, 1).
fact(N, L):-M is N-1, fact(M, P), L is P*N.
