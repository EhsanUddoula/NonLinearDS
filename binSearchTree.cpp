#include<bits/stdc++.h>
using namespace std;

template<class T>class Node{
public:
    T data;
    Node* left;
    Node* right;
    Node(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

template<class T>class BST{
    T ar[100005];
    Node<T>* rt=NULL;
    int t=0;
public:
     Node<T>* insert(Node<T>* root,T x){
        if(root==NULL){
            root=new Node<T>(x);
            return root;
        }
        if(root->data<x)
            root->right=insert(root->right,x);
        else root->left=insert(root->left,x);
        return root;
    }

    void levelTrav(Node<T>* root){
        queue<Node<T>*>q;
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

    void inorder(Node<T>* root){
        if(root==NULL)return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node<T>* root){
        if(root==NULL)return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node<T>* root){
        if(root==NULL)return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    bool search(Node<T>* root,T x){
        while(root!=NULL){
            if(root->data==x)return true;
            else if(root->data>x)root=root->left;
            else root=root->right;
        }
        return false;
    }
    Node<T>* minvalue(Node<T>* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    Node<T>* maxvalue(Node<T>* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }

    Node<T>* deleteNode(Node<T>* root,T value){
       if(root==NULL){
            return root;
       }
       if(root->data==value){
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){
                rt=root->right;
                delete(root);
                return rt;
            }
            else if(root->left!=NULL && root->right==NULL){
                rt=root->left;
                delete(root);
                return rt;
            }
            else{
                int mini=minvalue(root->right)->data;
                root->data=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }
        else if(root->data<value){
            root->right=deleteNode(root->right,value);
            return root;
        }
        else{
            root->left=deleteNode(root->left,value);
            return root;
        }
    }
    void checkBST(Node<T>* root){
        if(root==NULL)return;
        checkBST(root->left);
        ar[t++]=root->data;
        checkBST(root->right);
    }

    bool isBST(Node<T>* root){
        checkBST(root);
        int flag=1;
        for(int i=0;i<t-1;i++){
            if(ar[i]>ar[i+1]){
                flag=0;
                break;
            }
        }
        t=0;
        return flag==1;
    }

    bool checkPerfect(Node<T>* root,int d,int level){
        if(root==NULL)return true;
        if(root->left==NULL && root->right==NULL)
            return d==level+1;
        if(root->left==NULL || root->right==NULL)
            return false;
        return checkPerfect(root->left,d,level+1) && checkPerfect(root->right,d,level+1);
    }

    bool isPerfect(Node<T>* root){
        int d=0;
        rt=root;
        while(rt!=NULL){
            rt=rt->left;
            d++;
        }
        return checkPerfect(root,d,0);
    }

    bool isFull(Node<T>* root){
        if(root==NULL)return true;
        if(root->left==NULL && root->right!=NULL)return false;
        if(root->left!=NULL && root->right==NULL)return false;
        return isFull(root->left) && isFull(root->right);
    }

    int countNodes(Node<T>* root){
        if(root==NULL)return 0;
        return (1+countNodes(root->left)+countNodes(root->right));
    }

    bool isComplete(Node<T>* root,int ind,int ct){
        if (root == NULL)
            return true;

        if (ind >= ct)
            return false;
        return isComplete(root->left,2*ind+1,ct) && isComplete(root->right,2*ind+2,ct);
    }

    bool isLeftSkewed(Node<T>* root){
        if(root==NULL)return true;
        if(root->right)return false;
        return isLeftSkewed(root->left);
    }

    bool isRightSkewed(Node<T>* root){
        if(root==NULL)return true;
        if(root->left)return false;
        return isRightSkewed(root->right);
    }

    int isBalanced(Node<T>* root){
        if (root == NULL) {
            return 0;
        }
        int left = isBalanced(root->left);
        int right = isBalanced(root->right);
        if (left < 0 || right < 0 || abs(left - right) > 1) {
            return -1;
        }

        return max(left, right) + 1;
    }
};

int main(){
    BST<int> b;
    int x;
    Node<int>* root=NULL;
    Node<int>* temp=NULL;
    for(int i=0;i<8;i++){
        x=rand()%100;
        cout<<x<<" ";
        root=b.insert(root,x);
    }
    cout<<endl;
    b.levelTrav(root);
    cout<<b.search(root,15)<<endl;
    temp=b.minvalue(root);
    cout<<temp->data<<endl;
    temp=b.maxvalue(root);
    cout<<temp->data<<endl;
    root=b.deleteNode(root,86);
    b.levelTrav(root);
    //checking BST or not
    if(b.isBST(root)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    //checking Perfect or not
    if(b.isPerfect(root)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    //checking Full or not
    if(b.isFull(root)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    //checking Complete or Not
    int ct=b.countNodes(root);
    if(b.isComplete(root,0,ct)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    //checking balanced or not

    if(b.isBalanced(root)!=-1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }


    return 0;
}