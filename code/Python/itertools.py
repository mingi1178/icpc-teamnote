import itertools
A = [1,2,3]
itertools.permutations(A) # 순열
# [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]
itertools.permutations(A,2)
# [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]
itertools.combinations(A, 2) # 조합
# [(1, 2), (1, 3), (2, 3)]
itertools.combinations_with_replacement(A, 2) # 중복조합
# [(1, 1), (1, 2), (1, 3), (2, 2), (2, 3), (3, 3)]
B=['a','b']
itertools.product(A,B) # 데카르트 곱(cartesian product)
# [(1, 'a'), (1, 'b'), (2, 'a'), (2, 'b'), (3, 'a'), (3, 'b')]