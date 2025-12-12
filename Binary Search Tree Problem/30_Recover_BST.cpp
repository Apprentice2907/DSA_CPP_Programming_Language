/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev =NULL;
    TreeNode* first =NULL;
    TreeNode* sec =NULL;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);

        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){ 
            first= prev;
            }
            sec=root;
        }
        prev=root;
    inorder(root->right);          
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=first->val;
        first->val=sec->val;
        sec->val=temp;
    }
};









// Morris inorder traversal

TreeNode* first = NULL;
TreeNode* second = NULL;
TreeNode* prev = NULL;

while(root != NULL) {
    if(root->left == NULL) {
        if(prev != NULL && prev->val > root->val) {
            if(first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        root = root->right;
    } else {
        // find prev (IP)
        TreeNode* IP = root->left;
        while(IP->right != NULL && IP->right != root) {
            IP = IP->right;
        }

        if(IP->right == NULL) {
            IP->right = root;
            root = root->left;
        } else {
            if(prev != NULL && prev->val > root->val) {
                if(first == NULL) {
                    first = prev;
                }
                second = root;
            }
            prev = root;
            IP->right = NULL;
            root = root->right;
        }
    }
}

if(first != NULL && second != NULL) {
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
}
