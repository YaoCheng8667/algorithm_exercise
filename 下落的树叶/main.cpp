#include <iostream>
#include <cstring>
/**
Date: 2020/1/5
Author: YC
Sample input:
5 7 -1 6 -1 -1 3 -1 -1
8 2 9 -1 -1 6 5 -1 -1 12 -1 -1 3 7 -1 -1 -1
-1
Sample output:
Case 1:
7 11 3

Case 2:
9 7 21 15
*/
const int maxn = 10000;
using namespace std;
int tree[maxn];
int l_bd,r_bd,l,r;

void update_tree(int pos,int val){
    tree[pos] += val;
    cin>>l;
    if(l!=-1) {
        update_tree(pos - 1,l);
        if(pos - 1 < l_bd) l_bd = pos - 1;
    }
    cin>>r;
    if(r!=-1){
        update_tree(pos + 1,r);
        if(pos + 1 > r_bd) r_bd = pos + 1;
    }
}

inline void Do(){
    int root,cs = 1,i;
    while(cin>>root){
        if(root == -1) break;
        memset(tree,0,sizeof(tree));
        l_bd = r_bd = maxn/2;
        update_tree(maxn/2,root);
        cout<<"Case "<<cs++<<":\n";
        for(i = l_bd;i < r_bd;i++) cout<<tree[i]<<" ";
        cout<<tree[r_bd]<<"\n\n";
    }
}
int main()
{
    Do();
    return 0;
}
