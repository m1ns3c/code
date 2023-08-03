// BFS traversal
#include "def.h"

// bfs
void bfs(TNode root) {
    if (root == NULL) {
        return;
    }

    queue<TNode> q;
    q.push(root);
    while (!q.empty()) {
        TNode t = q.front();
        q.pop();
        if (t == NULL) {
            printf("*\t");
            continue;
        }
        printf("%d\t", t->data);
        q.push(t->left);
        q.push(t->right);
    }
}

// bfs with level
void bfs_level(TNode root) {
    if (root == NULL) {
        return;
    }

    queue<TNode> q;
    q.push(root);
    while (!q.empty()) {
        int s = q.size();
        for (int i=0; i<s; i++) {
            TNode t = q.front();
            q.pop();
            if (t == NULL) {
                printf("*\t");
                continue;
            }
            printf("%d\t", t->data);
            q.push(t->left);
            q.push(t->right);
        }
        printf("\n");
    }
}