#include <bits/stdc++.h>
using namespace std;
#define N 3

// Structure to represent a node in the puzzle
struct Node
{
    Node *p;       // Parent node
    int mat[N][N]; // Puzzle matrix
    int x, y;      // Blank tile coordinates
    int h;         // Heuristic value (Manhattan distance)
    int g;         // Cost to reach this node from the initial state
    int f;         // Evaluation function value (g + h)
};

// Print the puzzle matrix
void pr(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
}

// Create a new node with updated puzzle matrix and coordinates
Node *newNode(int mat[N][N], int x, int y, int nx, int ny, int g, Node *p)
{
    Node *node = new Node;
    node->p = p;

    // Copy the puzzle matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            node->mat[i][j] = mat[i][j];
        }
    }

    // Swap the blank tile with the new coordinates
    swap(node->mat[x][y], node->mat[nx][ny]);

    node->h = INT_MAX;
    node->g = g;

    node->x = nx;
    node->y = ny;

    return node;
}

// Calculate the number of misplaced tiles between two matrices
int diff(int imat[N][N], int res[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (imat[i][j] != res[i][j])
            {
                count++;
            }
        }
    }
    return count;
}

// Arrays to represent possible movements in the puzzle
int r[] = {1, 0, -1, 0};
int c[] = {0, -1, 0, 1};

// Check if a movement is valid within the puzzle boundaries
int move(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Traverse and print the solution path
void trv(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    trv(root->p);
    pr(root->mat);
    cout << endl;
}

// Comparator struct for the priority queue in the A* algorithm
struct comp
{
    bool operator()(Node *a, Node *b)
    {
        return (a->f) > (b->f);
    }
};

// A* algorithm to solve the 8 puzzle problem
void solve(int imat[N][N], int x, int y, int res[N][N])
{
    // Priority queue to store the open list of nodes to be expanded
    priority_queue<Node *, vector<Node *>, comp> pq;

    // Create the root node
    Node *root = newNode(imat, x, y, x, y, 0, NULL);
    root->h = diff(imat, res);
    root->f = root->g + root->h;

    pq.push(root);

    while (!pq.empty())
    {
        Node *temp = pq.top();

        pq.pop();

        // If the current node is the goal state, print the solution
        if (temp->h == 0)
        {
            trv(temp);
            cout << endl;
            return;
        }

        // Generate the successors of the current node
        for (int i = 0; i < 4; i++)
        {
            if (move(temp->x + r[i], temp->y + c[i]))
            {
                // Create a new child node
                Node *child = newNode(temp->mat, temp->x, temp->y, (temp->x + r[i]), (temp->y + c[i]), (temp->g + 1), temp);
                child->h = diff(child->mat, res);
                child->f = child->g + child->h;

                pq.push(child);
            }
        }
    }
}

int main()
{
    // Initial and goal states of the puzzle
    int imat[N][N] =
        {
            {2, 8, 3},
            {1, 6, 4},
            {7, 0, 5}};

    int res[N][N] =
        {
            {1, 2, 3},
            {8, 0, 4},
            {7, 6, 5}};

    // initial position of blank tile in Initial state
    int x = 2, y = 1;

    // Solve the puzzle using A* algorithm
    solve(imat, x, y, res);

    return 0;
}

/*

2  8  3  
1  6  4  
7  0  5  

2  8  3  
1  0  4  
7  6  5  

2  0  3  
1  8  4  
7  6  5  

0  2  3  
1  8  4  
7  6  5  

1  2  3  
0  8  4  
7  6  5  

1  2  3  
8  0  4  
7  6  5  

*/