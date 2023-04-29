#include<bits/stdc++.h>
using namespace std;

#define M 100005

template <class T> class heap{
    T ar[M];
    int size=0;
    public:
        void heapyfy(int index){
            int largest=index;
            int left=2*index+1;
            int right=2*index+2;
            if(left<size && ar[largest]<ar[left])
                largest=left;
            if(right<size && ar[largest]<ar[right])
                largest=right;
            if(largest!=index){
                swap(ar[largest],ar[index]);
                heapyfy(largest);
            }
        }

        void insert(T data){
            if(size==M){
                cout<<"Overflow\n";
            }
            ar[size]=data;
            size++;
            for(int i=(size/2)-1;i>=0;i--){
                heapyfy(i);
            }
            
        }

        T top(){
            return ar[0];
        }

        void pop(){
            ar[0]=ar[size-1];
            size--;
            heapyfy(0);
        }

        void print(){
            for(int i=0;i<size;i++){
                cout<<ar[i]<<endl;
            }
        }
        bool empty(){
            if(size==0)return true;
            return false;
        }

};

int main(){
    heap<int> hp;
    vector<int>b;
    priority_queue<int>pq;
    for(int i=0;i<7;i++){
        int l=rand()%1000;
        cout<<l<<" ";
        b.push_back(l);
        pq.push(l);
        hp.insert(l);
    }
    cout<<endl;
    hp.print();
    hp.pop();
    cout<<hp.top()<<endl;
    cout<<"STL USED\n";
    make_heap(b.begin(),b.end());
    for(int i:b){
        cout<<i<<endl;
    }
    cout<<"Heap Check\n";
    while(!hp.empty()){
        cout<<hp.top()<<endl;
        hp.pop();
    }
    cout<<"Priority Queue Check\n";
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}