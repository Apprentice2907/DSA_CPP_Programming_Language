#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};


Node* rightMostValueLeft(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root;
        root=root->right;
    }
    return ans;
}


Node* leftMostValueRight(Node* root){
    Node* ans;
    
    while(root!=NULL){
        ans=root;
        root=root->left;
    }
    return ans;
}



vector<int> getPredSucc(Node* root,int key){
    Node* curr=root;
    Node* pred=NULL;
    Node* succ=NULL;

    while(curr!=NULL){
        if(key<curr->data){
            succ=curr;
            curr=curr->left;
        } else if(key>curr->data){
            pred=curr;
            curr=curr->right;
        } else{
            if(curr->left!=NULL){
                pred= rightMostValueLeft(curr->left);
            }
            if(curr->right!=NULL){
                succ= leftMostValueRight(curr->right);
            }
            break;
        }
    }
    return{pred->data,succ->data};
}






 

int main(){
    Node* root =new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    vector<int> ans = getPredSucc(root, key);
    cout << "predecessor: " << ans[0] << endl;
    cout << "successor: " << ans[1] << endl;

    return 0;
}