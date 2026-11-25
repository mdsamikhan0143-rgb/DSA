class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {

        // Base case
        if (root == NULL) {
            return;
        }

        // 1. Visit Left Subtree
        inorder(root->left, ans);

        // 2. Visit Root
        ans.push_back(root->val);

        // 3. Visit Right Subtree
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;

        inorder(root, ans);

        return ans;
    }
};