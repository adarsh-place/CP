#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int lcs(int i,int j,string &s1,string &s2){
    if(i<0 || j<0) return 0;

    // remove one char from s1
    int ans=lcs(i-1,j,s1,s2);

    // remove one char from s2
    ans=max(ans,lcs(i,j-1,s1,s2));

    // remove one char from both s1 and s2
    ans=max(ans,lcs(i-1,j-1,s1,s2));

    return ans;
}

int longestCommonSubsequence(string text1,string text2){
    return lcs(text1.size()-1,text2.size()-1,text1,text2);
}

int main(){
    
}