#include <iostream>
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
    int preorder = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return -1;

        if (root->left != NULL) {
            int leftAns = kthSmallest(root->left, k);
            if (leftAns != -1) return leftAns;
        }

        preorder++;  // increment count when visiting node
        if (preorder == k) return root->val;

        if (root->right != NULL) {
            int rightAns = kthSmallest(root->right, k);
            if (rightAns != -1) return rightAns;
        }

        return -1;
    }
};

// Helper function to build a sample BST
TreeNode* buildTestTree() {
    /*
        Example Tree:
              3
             / \
            1   4
             \
              2
        Inorder: 1,2,3,4
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTestTree();
    int k;

    cout << "Enter k: ";
    cin >> k;

    int result = sol.kthSmallest(root, k);
    if (result != -1)
        cout << "The " << k << "-th smallest element is: " << result << endl;
    else
        cout << "k is out of bounds." << endl;

    return 0;
}
