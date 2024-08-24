#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

unordered_map<char,int> symbols = {{'[',1},{'{',2},{'(',3},{']',-1},{'}',-2},{')',-3}};
 
int main()
{
    string s;
    s="(){(}";
    stack<char> st;

    for(char bracket:s){
        if(symbols[bracket]>0){
            st.push(bracket);
        }
        else{
            if(symbols[bracket]+symbols[st.top()] == 0){
                st.pop();
            }
            else{
                cout<<"1NO"<<endl;
                return 0;
            }
        }
    }
    if(!st.empty())
        cout<<"2NO";
    else{
        cout<<"YES";
    }
    
    return 0;
}