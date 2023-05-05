list_length([], 0).
list_length([_|L], L1):-list_length(L, L2), L1 is L2+1.

concat_list([], L, L).
concat_list([X|L], L1, [X|L2]):- concat_list(L, L1, L2).

reverse_list([], []).
reverse_list([X|L], L2):-reverse_list(L, L1), concat_list(L1,[X],L2).
