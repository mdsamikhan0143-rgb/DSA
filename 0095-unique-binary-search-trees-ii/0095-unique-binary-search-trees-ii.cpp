class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> ans;

        // Base case: No nodes available
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        // Try every number as root
        for (int i = start; i <= end; i++) {

            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = solve(start, i - 1);

            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = solve(i + 1, end);

            // Combine left and right subtrees
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {

        return solve(1, n);
    }
};