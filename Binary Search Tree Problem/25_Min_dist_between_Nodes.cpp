#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    TreeNode* prev = NULL;

    int minDiffInBST(TreeNode* root) {
        if (root == NULL) return INT_MAX;

        int ans = INT_MAX;

        if (root->left) {
            int leftmin = minDiffInBST(root->left);
            ans = min(ans, leftmin);
        }
        if (prev != NULL) {
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        if (root->right) {
            int rightmin = minDiffInBST(root->right);
            ans = min(ans, rightmin);
        }
        return ans;
    }
};

// Helper function to build a sample BST
TreeNode* buildTestTree() {
    /*
        Example BST:
              4
             / \
            2   6
           / \
          1   3
        Minimum difference is 1 (between 1&2, 2&3, or 3&4)
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTestTree();

    int minDiff = sol.minDiffInBST(root);
    cout << "Minimum difference in BST is: " << minDiff << endl;

    return 0;
}
