#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;

int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(v==parent[v]) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

int Union(int a,int b){
    a=find(a);
    b=find(b);

    if(a!=b){
        // Union by size
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}

// Amorterised Time complexity
// O(a(n))
// a(n)  Reverse Ackerman function

int main(){
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        make(i);
    }

    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    int connected_ct=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) connected_ct++;
    }

    cout<<connected_ct<<endl;
}