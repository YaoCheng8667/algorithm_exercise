#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
/**
2 3
fff
000
*/
using namespace std;
const int maxn = 205;

int m,n;

int g[maxn][maxn];
char holes[6] = {'W','A','K','J','S','D'};
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,1,0,-1};
int cnt;

//gray : 2
void print_gray(int x,int y){
    //cout<<"print gray"<<x<<y<<endl;
    if(g[x][y] != 0 || x < 0 || y < 0 || x > m+1 || y > 4*n + 1) return;
    g[x][y] = 2;
    for(int i = 0;i < 4;i++)
        print_gray(x+dirx[i],y+diry[i]);
}

void dfs(int x,int y){
    if(g[x][y] == 2 || x < 1 || y < 1 || x > m || y > 4*n) return;
    if(g[x][y] == 1){
        g[x][y] = 2;
        for(int i = 0;i < 4;i++)
            dfs(x+dirx[i],y+diry[i]);
    }else{
        cnt++;
        print_gray(x,y);
    }
}

void printg(){
    for(int i = 0;i <= m+1; i++){
        for(int j = 0;j <= 4*n + 1; j++)
            cout<<g[i][j];
        cout<<endl;
    }
}

inline void Do(){
    char c,tc;int ti,cs = 1;
    while(cin>>m>>n){
        if(m == 0) break;
        vector<char> re;
        memset(g,0,sizeof(g));
        for(int i = 0;i < m; i++){
            for(int j = 0;j < n; j++){
                cin>>c;
                if(isalpha(c)) tc = 'a' - 10;
                else tc = '0';
                ti = c - tc;
                for(int k = 3;k >= 0; k--){
                    g[i+1][4*j+k+1] = ti%2;
                    ti /= 2;
                }
            }
        }
        print_gray(0,0);
        for(int i = 1; i < m+1 ; i++){
            for(int j = 1; j < 4*n + 1; j++){
                if(g[i][j] == 1){
                    cnt = 0;
                    dfs(i,j);
                    re.push_back(holes[cnt]);
                }
            }
        }
        sort(re.begin(),re.end());
        cout<<"Case "<<cs++<<": ";
        for(char c : re)
            cout<<c;
        cout<<endl;
    }
}

int main()
{
    Do();
    return 0;
}
