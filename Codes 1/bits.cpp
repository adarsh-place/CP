#include<bits/stdc++.h>
using namespace std;

void printBinary(int n){
    for(int i=10;i>=0;--i){
        cout<<( (n >> i) & 1 );
    }
    cout<<endl;
}

// void printBinary(int n){
//     int x=0;
//     for(int i=10;i>=0;--i){
//         x = x*10 + ( (n >> i) & 1 );
//     }
//     cout<<x<<endl;
// }
 
int main()
{
    printBinary(9);
    int a=9;
    int i=3;

    // to check the ith bit is set or not
    if((a & (1<<i)) != 0){
        cout<<"set bit"<<endl;
    }
    else{
        cout<<"not set bit"<<endl;
    }

    // to set the ith bit
    i=1;
    printBinary(a | (1<<i));

    // to invert a binary
    printBinary(~a);

    // to unset the ith bit
    i=3;
    printBinary(a & (~(1<<i)) );

    // toggle the ith bit
    i=2;
    printBinary(a ^ (1<<i));

    // bit count
    int ct=0;
    for(int i=31;i>=0;--i){
        if((a & (1<<i)) != 0){
            ct++;
        }
    }
    cout<<ct<<endl;
    cout<<__builtin_popcount(a)<<endl;
    cout<<__builtin_popcountll((1LL<<35)-1)<<endl;

    return 0;
}