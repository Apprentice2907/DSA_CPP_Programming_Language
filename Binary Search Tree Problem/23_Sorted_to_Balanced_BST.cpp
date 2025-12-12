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

Node* insert(Node* root,int val){
    if(root==NULL) return new Node(val);
    if(val<root->data){
        root->left=insert(root->left,val);
    } else{
        root->right=insert(root->right,val);
    }
    return root;
}

Node* buildBST(vector<int> arr){
    Node* root=NULL;
    for(int val: arr){
        root=insert(root,val);
    }
    return root;
}

void inorder(Node* root){
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* helper(vector<int>& arr,int st,int end){
    if(st>end) return NULL;
    int mid=st+(end-st)/2;
    Node* root=new Node(arr[mid]);
    root->left=helper(arr,st,mid-1);
    root->right=helper(arr,mid+1,end);
    return root;
}

Node* sortedToBST(vector<int>& arr){
    return helper(arr,0,arr.size()-1);
}



int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* root=buildBST(arr);

    root=sortedToBST(arr);
    inorder(root);
    cout<<endl;

    return 0;
}