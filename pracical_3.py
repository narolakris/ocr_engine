from queue import Queue
import sys
def bfs(start, goal):
    q, visited = Queue(), set()
    q.put((start, []))
    while not q.empty():
        state, path = q.get()
        if state == goal:
            return path + [state]
        for i in range(len(state)):
            if state[i] == 0:
                for j in (i-3, i+3, i-1, i+1):
                    if 0 <= j < len(state):
                        new_state = state[:]
                        new_state[i], new_state[j] = new_state[j], new_state[i]
                        if tuple(new_state) not in visited:
                            visited.add(tuple(new_state))
                            q.put((new_state,path + [state]))
    return None

def bfs(start,goal):
    q,visited=Queue(),set()
    q.put((start , []))
    while not q.empty():
        state,path=q.get()
        if state==goal:
            return path + [state]
        for i in range(len(state)):
            if state[i]==0:
                for j in (i-3,i+3,i-1,i+1):
                    if 0<= j< len(state):
                        new_state=state[:]
                        new_state[i],new_state[j]=new_state[j],new_state[i]
                        if tuple(new_state) not in visited:
                            visited.add(tuple(new_state))
                            q.put((new_state,path + [state]))
                            
start = [2, 8, 3, 1, 6, 4, 7, 0, 5]
goal = [1, 2, 3, 8, 0, 4, 7, 6, 5]
path = bfs(start, goal)
if path is None:
    print("No solution found.")
else:
    print("Solution found!")
    for i, state in enumerate(path):
        print("Step", i, ":", state)

print('----------for dfs------------')

def dfs(state, goal, visited, path):
    if state == goal:
        return path + [state]
    for i in range(len(state)):
        if state[i] == 0:
            for j in (i-3, i+3, i-1, i+1):
                if 0 <= j < len(state):
                    new_state = state[:]
                    new_state[i], new_state[j] = new_state[j], new_state[i]
                    if tuple(new_state) not in visited:
                        visited.add(tuple(new_state))
                        found = dfs(new_state, goal, visited, path + [state])
                        if found is not None:
                            return found
    return None
def solve(start, goal):
    visited = set([tuple(start)])
    return dfs(start, goal, visited, [])

sys.setrecursionlimit(100000)

start = [2, 8, 3, 1, 6, 4, 7, 0, 5]
goal = [2, 8, 3, 1, 6, 4, 7, 5, 0]
path = solve(start, goal)

if path is None:
    print("No solution found.")
else:
    print("Solution found!")
    for i, state in enumerate(path):
        print("Step", i, ":", state)