#include<bits/stdc++.h>
using namespace std;


void heapyfy(int ar[],int size,int index){
    int largest=index;
    int left=2*index+1;
    int right=2*index+2;
    if(left<size && ar[largest]<ar[left])
        largest=left;
    if(right<size && ar[largest]<ar[right])
        largest=right;
    if(largest!=index){
        swap(ar[largest],ar[index]);
        heapyfy(ar,size,largest);
    }
}

void heapSort(int ar[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapyfy(ar,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(ar[0],ar[i]);
        heapyfy(ar,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        ar[i]=rand()%1000;
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    heapSort(ar,n);
    for(int i=0;i<n;i++){
        cout<<ar[i]<<endl;
    }

    


    return 0;
}