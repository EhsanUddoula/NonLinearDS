#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class binTree{
    Node *newnode,*rt;
    
    public:
    int depth[10000]={0};
    int height[10000]={0};
    Node* insert(Node* root){
        int x;
        cin>>x;
        root=new Node(x);
        if(x==-1)return NULL;
        cout<<"Enter the value of left node of node "<<root->data<<endl;
        root->left=insert(root->left);
        cout<<"Enter the value of right node of node "<<root->data<<endl;
        root->right=insert(root->right);

        return root;
    }
    void levelTrav(Node* root){
        queue<Node*>q;
        if(root!=NULL){
            q.push(root);
            q.push(NULL);
        }
        while(!q.empty()){
            rt=q.front();
            q.pop();
            if(rt==NULL){
                cout<<endl;
                if(!q.empty())
                q.push(NULL);
            }
            else{
                cout<<rt->data<<" ";
                if(rt->left)q.push(rt->left);
                if(rt->right)q.push(rt->right);
            }
        }
    }

    void inorder(Node* root){
        if(root==NULL)return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node* root){
        if(root==NULL)return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL)return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    void trav(Node* root,int m){
        if(root==NULL)return;
        depth[root->data]=depth[m]+1;
        trav(root->left,root->data);
        //height[temp->data]=max(height[temp->data],height[root->data]+1);
        trav(root->right,root->data);
        height[m]=max(height[m],height[root->data]+1);
    }
};


int main(){
    Node* root=NULL;
    binTree b;
    cout<<"Enter root data\n";
    root=b.insert(root);
    b.levelTrav(root);
    b.inorder(root);
    cout<<endl;
    b.preorder(root);
    cout<<endl;
    b.postorder(root);
    cout<<endl;
    b.trav(root,0);
    for(int i=1;i<=7;i++){
        cout<<b.depth[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=7;i++){
        cout<<b.height[i]<<" ";
    }
    cout<<endl;


    return 0;
}
/*1
2 3
4 5 6 7
1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1*/