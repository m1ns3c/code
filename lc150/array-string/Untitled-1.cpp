
// 类
// BST
// 数组

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} TNode;

class Solution {
public:
    bool verify(vector<int> &nums) {
        int n = nums.size();

        if (n < 1) {
            return false;
        }

        TNode *root = newNode(nums[0]);
        while (int i=1; i<n; i++) {
            root = insert(root, nums[i]);
        }
        
    }

    TNode *newNode(int val) {
        Node *n = new Node(val);
        n->left = nullptr;
        n->right = nullptr;

        return n;
    }

    TNode *insert(TNode* root, int val) {
        TNode *t = root, *p;

        while (t != nullptr) {
            p = t;
            if (t->value > val) {
                t = t->left;
            } else if (t->value < val) {
                t = t->right;
            }
        }

        if (p->value > val) {
            p->left = newNode(val);
        } else {
            p->right = newNode(val);
        }

        return root;
    }
}
