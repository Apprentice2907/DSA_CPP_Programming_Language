#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) return true;
        if (min != NULL && root->val <= min->val) return false;
        if (max != NULL && root->val >= max->val) return false;
        return helper(root->left, min, root) &&
               helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};

// Helper function to build a small test tree
TreeNode* buildTestTree() {
    /*
        Example Tree:
              2
             / \
            1   3
        This is a valid BST
    */
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTestTree();

    if (sol.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
