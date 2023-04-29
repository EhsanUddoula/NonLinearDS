#include<bits/stdc++.h>
#include "LInkList.hpp"
using namespace std;

linkList<int> gr[1000];
int vis[1000];

void dfs(int ver){
    vis[ver]=1;
    Node<int>* temp=gr[ver].set();
    while(temp!=NULL){
        if(vis[temp->data]){
            temp=temp->next;
            continue;
        }
        dfs(temp->data);
        temp=temp->next;
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
    int ct=0;
    for(int i=1;i<=m;i++){
        if(vis[i])continue;
        dfs(i);
        ct++;
    }
    cout<<ct<<endl;
}