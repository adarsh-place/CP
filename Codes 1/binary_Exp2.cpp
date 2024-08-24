#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

// for large numbers (10^18 type) 

int binMultiply(long long a, long long b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

int binExpIter(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = binMultiply(a,ans);
        }
        a = binMultiply(a,a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a = 2, b = 13;
    cout << binExpIter(a, b);
}