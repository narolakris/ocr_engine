import math
def water_jug_problem(x, y, z):
    if z > max(x, y) or z % math.gcd(x, y) != 0:
        return None
    steps, a, b = [], 0, 0
    while True:
        if a == 0:
            steps.append((a := x, b))
        elif b == y:
            steps.append((a, b := 0))
        elif a > 0 and b < y:
            t = min(a, y - b)
            steps.append((a := a - t, b := b + t))
        elif a > 0 and b == 0:
            steps.append((a := 0, b))
        elif b == 0:
            steps.append((a, b := y))
        elif a < x and b > 0:
            t = min(x - a, b)
            steps.append((a := a + t, b := b - t))
        if a == z or b == z:
            break
    return steps

print(water_jug_problem(5,4,3))



# import heapq

# # The goal state
# goal_state = [[1,2,3],[4,5,6],[7,8,0]]

# # Define the heuristic function (Manhattan distance)
# def heuristic(state):
#     distance = 0
#     for i in range(3):
#         for j in range(3):
#             if state[i][j] != 0:
#                 distance += abs(i - (state[i][j]-1)//3) + abs(j - (state[i][j]-1)%3)
#     return distance

# # Define the Best First Search algorithm
# def best_first_search(initial_state):
#     queue = []
#     visited = set()
#     heapq.heappush(queue, (heuristic(initial_state), initial_state))
#     while queue:
#         current_state = heapq.heappop(queue)[1]
#         if current_state == goal_state:
#             return current_state
#         visited.add(str(current_state))
#         for move in get_moves(current_state):
#             new_state = make_move(current_state, move)
#             if str(new_state) not in visited:
#                 heapq.heappush(queue, (heuristic(new_state), new_state))

# # Define the helper functions
# def get_moves(state):
#     moves = []
#     row, col = get_blank_pos(state)
#     if row > 0:
#         moves.append((row-1, col))
#     if row < 2:
#         moves.append((row+1, col))
#     if col > 0:
#         moves.append((row, col-1))
#     if col < 2:
#         moves.append((row, col+1))
#     return moves

# def get_blank_pos(state):
#     for i in range(3):
#         for j in range(3):
#             if state[i][j] == 0:
#                 return i, j

# def make_move(state, move):
#     row, col = get_blank_pos(state)
#     new_row, new_col = move
#     new_state = [row[:] for row in state]
#     new_state[row][col] = new_state[new_row][new_col]
#     new_state[new_row][new_col] = 0
#     return new_state

# # Test the algorithm
# initial_state = [[2,8,3],[1,6,4],[7,0,5]]
# solution = best_first_search(initial_state)
# print(solution)


