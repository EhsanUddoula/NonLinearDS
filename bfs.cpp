#include<bits/stdc++.h>
#include "LInkList.hpp"
using namespace std;

linkList<int> gr[1000];
bool vis[1000];

void bfs(int src){
    queue<int>q;
    Node<int>* temp;
    int lev;
    q.push(src);
    vis[src]=1;
    //cout<<src<<" ";
    while(!q.empty()){
        lev=q.front();
        q.pop();
        temp=gr[lev].set();
        cout<<lev<<" ";
        while(temp!=NULL){
            if(vis[temp->data]){
                temp=temp->next;
                continue;
            }
            q.push(temp->data);
            vis[temp->data]=true;
            temp=temp->next;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gr[a].push(b);
        gr[b].push(a);
    }

    bfs(1);
    cout<<endl;


    return 0;
}