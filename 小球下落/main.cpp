#include <iostream>
#include <cstdio>
/**
Date: 2019/12/30
Author: YC
Test Cases:
4 2
3 4
10 1
2 2
8 128
16 12345

Right Answer:
12
7
512
3
255
36358
*/
using namespace std;

int D,I;

int cal(int d,int i){
    int l = 1 << (d-1);
    int w = d - 2;
    while(i != 1){
        if(i%2 == 0)//right
            l += (1 << w);
        w--;
        i = (i + 1) >> 1;
    }
    return l;
}

int main()
{
    int r;
    /*
    //The following code is for test in UVA 679
    int t;
    scanf("%d",&t);
    while(1){
        scanf("%d",&D);
        if(D==-1) break;
        scanf("%d",&I);
        r = cal(D,I);
        printf("%d\n",r);
    }
    */
    while(scanf("%d%d",&D,&I) == 2){
        r=cal(D,I);
        printf("%d\n",r);
    }
    return 0;
}
