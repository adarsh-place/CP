#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

vector<bool> isPrime(N, 1);
vector<int> lowest_p(N, 0), highest_p(N, 0);

int main()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; ++i)
    {
        if (isPrime[i] == true)
        {
            highest_p[i]=lowest_p[i]=i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                highest_p[j] = i;
                if (lowest_p[j] == 0)
                {
                    lowest_p[j] = i;
                }
            }
        }
    }

    for(int i=1;i<=100;i++){
        cout<<i<<" "<<lowest_p[i]<<" "<<highest_p[i]<<endl;
    }
    
    return 0;
}