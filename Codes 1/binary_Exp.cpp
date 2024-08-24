#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

// Euclid Algorithm
int binExpRecur(int a, int b)
{
    if (b == 0)
        return 1;
    long long res = binExpRecur(a, b / 2);
    if (b & 1)
    {
        return (a * ((res * res) % M)) % M;
    }
    else
    {
        return (res * res) % M;
    }
}

int binExpIter(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a = 2, b = 13;
    cout << binExpRecur(a, b) << endl;
    cout << binExpIter(a, b);
}