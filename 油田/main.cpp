#include <iostream>
#include <cstring>
/**
Date: 2020/1/8
Author: YC
Sample input:
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
Sample output:
0
1
2
2
*/
using namespace std;

const int maxm = 150;
const int maxn = 150;

char g[maxm][maxn];
int m,n;
bool vst[maxm][maxn];
int re;

void dfs(int x,int y){
    if(vst[x][y] || g[x][y] != '@') return;
    vst[x][y] = 1;
    for(int i = -1;i <= 1; i++)
        for(int j = -1;j <= 1;j++)
            if(!(i == j&& i == 0))
                if(x+i >= 0 && y+j >=0 &&x+i < m && y+j < n)
                    dfs(x+i,y+j);
}

inline void Do(){
    while(cin>>m>>n){
        if(!m) break;
        memset(vst,0,sizeof(vst));
        for(int i = 0;i < m; i++)
            for(int j = 0;j < n;j++)
                cin>>g[i][j];
        re = 0;
        for(int i = 0;i < m; i++)
            for(int j = 0;j < n;j++)
                if(g[i][j] == '@' && !vst[i][j]){
                    dfs(i,j);
                    re++;
                }
        cout<<re<<endl;
    }
}

int main()
{
    Do();
    return 0;
}
