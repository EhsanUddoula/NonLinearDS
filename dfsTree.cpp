#include<bits/stdc++.h>
#include "LInkList.hpp"
using namespace std;

linkList<int> gr[1000];
int height[1000];
int depth[1000];

//calculating height and depth of the tree 
void dfs(int ver,int par){
    Node<int>* temp=gr[ver].set();
    while(temp!=NULL){
        if(temp->data==par){
            temp=temp->next;
            continue;
        }
        depth[temp->data]=depth[ver]+1;
        dfs(temp->data,ver);
        height[ver]=max(height[ver],height[temp->data]+1);
        temp=temp->next;
    }
}

int main(){
    int n,m;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gr[a].push(b);
        gr[b].push(a);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout<<depth[i]<<"   "<<height[i]<<endl;
    }

    return 0;
}