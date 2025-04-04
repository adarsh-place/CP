#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int vis[8][8];
int level[8][8];

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1';
}

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

vector<pair<int, int>> movements
{
    {-1, 2}, {1, 2}, 
    {-1, -2}, {1, -2}, 
    {2, -1}, {2, 1}, 
    {-2, -1}, {-2, 1}
};

int bfs(string source, string dest)
{
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int,int> > q;

    q.push({sourceX, sourceY}); 
    vis[sourceX][sourceY] = 1;

    while(!q.empty()){
        pair<int,int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();

        for(auto movement : movements) {
            int childX = movement.first + x;
            int childY = movement.second + y; 

            if(!isValid(childX, childY)) continue;

            if(!vis[childX][childY]) {
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                vis[childX][childY]=1;
            }
        }    
    }

    return level[destX][destY];
}


int main()
{

    return 0;
}