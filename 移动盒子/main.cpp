#include <iostream>
#include <cstdio>
/**
Date: 2019/12/31
Author: yc
Test cases:
6 4
1 1 4
2 3 5
3 1 6
4
6 3
1 1 4
2 3 5
3 1 6
100000 1
4
3 1
1 3 1
2 1
3 1 2
Right Answer:
Case 1: 12
Case 2: 9
Case 3: 2500050000
Case 4: 5
Case 5: 2
*/
using namespace std;

const int maxn = 100002;

int n,m;
int Left[maxn],Right[maxn];

inline void link_node(int l,int r){
    Left[r] = l;Right[l] = r;
}
inline void swap_node(int l,int r){
    link_node(Left[l],r);
    link_node(l,Right[r]);
    link_node(r,l);
}
inline void init_ll(int n){
    for(int i = 0;i < n; i++ ){
        Right[i] = i + 1;
        Left[i + 1] = i;
    }
    Left[0] = n;
    Right[n] = 0;
}

inline void op1(int x,int y){
    link_node(Left[x],Right[x]);
    link_node(Left[y],x);
    link_node(x,y);
}

inline void op2(int x,int y){
    link_node(Left[x],Right[x]);
    link_node(x,Right[y]);
    link_node(y,x);
}

inline void op3(int x,int y){
    if(Left[x]==y){
        swap_node(y,x);
    }
    else if(Left[y]==x){
        swap_node(x,y);
    }else{
        int yl = Left[y],yr = Right[y];
        link_node(Left[x],y);
        link_node(y,Right[x]);
        link_node(yl,x);
        link_node(x,yr);
    }
}

void Do(){
    int op,x,y,rvs,ind,cs = 0;
    long long sum;
    while(scanf("%d%d",&n,&m)==2){
        rvs = 0;cs++;sum = 0;
        init_ll(n);
        while( m-- > 0){
            scanf("%d",&op);
            if(op == 4){
                rvs = 1 - rvs;
            }else{
                scanf("%d%d",&x,&y);
                if(op != 3 && rvs) op = 3 - op;
                if(op == 1 && Left[y] != x) op1(x,y);
                if(op == 2 && Right[y] != x) op2(x,y);
                if(op == 3) op3(x,y);
            }
        }
        ind = 1;
        if(rvs){
            for(int i = Left[0];i != 0; i = Left[i])
                if(ind ++%2 == 1) sum += i;
        }else{
            for(int i = Right[0];i != 0; i = Right[i])
                if(ind ++%2 == 1) sum += i;
        }
        printf("Case %d: %lld\n",cs,sum);
    }
}
int main()
{
    Do();
    return 0;
}
