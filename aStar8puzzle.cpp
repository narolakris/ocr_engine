// Write a program to solve the 8-puzzle problem (and its natural generalizations) using the A* search algorithm.

#include <bits/stdc++.h>
using namespace std;

// A* search algorithm

struct Node {
    Node *parent;
    int mat[3][3];
    int x, y;
    int cost;
    int level;
};

int printMatrix(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

Node *newNode(int mat[3][3], int x, int y, int newX, int newY, int level, Node *parent) {
    Node *node = new Node;

    node->parent = parent;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[newX][newY]);
    
    node->cost = INT_MAX;
    node->level = level;
    
    node->x = newX;
    node->y = newY;

    return node;
}

int row[] = {1, 0, -1, 0};
int col[] = {0, -1, 0, 1};

int calculateCost(int initial[3][3], int final[3][3]) {
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
                count++;
    return count;
}

int isSafe(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

void printPath(Node *root) {
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);

    cout << endl;
}

struct comp {
    bool operator()(const Node *lhs, const Node *rhs) const {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

void solve(int initial[3][3], int x, int y, int final[3][3]) {
    priority_queue<Node *, std::vector<Node *>, comp> pq;

    Node *root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);

    pq.push(root);

    while (!pq.empty()) {
        Node *min = pq.top();
        pq.pop();

        if (min->cost == 0) {
            printPath(min);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (isSafe(min->x + row[i], min->y + col[i])) {
                Node *child = newNode(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->level + 1, min);
                child->cost = calculateCost(child->mat, final);
                pq.push(child);
            }
        }
    }
}

int main() {
    int initial[3][3] =
        {
            {1, 8, 2},
            {0, 4, 3},
            {7, 6, 5}
        };

    int final[3][3] =
        {
            {1, 2, 3},
            {4, 0, 8},
            {7, 6, 5}
        };

    int x = 1, y = 0;

    solve(initial, x, y, final);

    return 0;
}

/*

1 8 2
0 4 3
7 6 5

1 2 3
8 0 4
7 6 5

*/