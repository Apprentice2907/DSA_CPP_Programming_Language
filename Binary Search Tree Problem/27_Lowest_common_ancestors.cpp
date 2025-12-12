#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution 1: BST using BT logic
class SolutionBTLogic {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA && rightLCA) return root;
        else if(leftLCA != NULL) return leftLCA;
        else return rightLCA;
    }
};

// Solution 2: Optimized BST logic
class SolutionBST {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else return root; 
    }
};

// Helper function to print LCA value
void printLCA(TreeNode* lca) {
    if(lca)
        cout << "LCA: " << lca->val << endl;
    else
        cout << "LCA not found" << endl;
}

int main() {
    // Sample BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;      // Node 2
    TreeNode* q = root->left->right; // Node 4

    // Test BST using BT logic
    SolutionBTLogic solBTLogic;
    TreeNode* lcaBTLogic = solBTLogic.lowestCommonAncestor(root, p, q);
    cout << "BST (BT logic) LCA:" << endl;
    printLCA(lcaBTLogic);

    // Test optimized BST logic
    SolutionBST solBST;
    TreeNode* lcaBST = solBST.lowestCommonAncestor(root, p, q);
    cout << "BST (optimized logic) LCA:" << endl;
    printLCA(lcaBST);

    return 0;
}
