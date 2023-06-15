void dfs(TreeNode *root) {
     if (root == NULL) {
          return;
     }

     dfs(root->left);
     dfs(root->right);
}
