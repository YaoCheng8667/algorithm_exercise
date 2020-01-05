#include <iostream>
#include <cstring>
/**
Date: 2020/1/5
Author: YC
Sample input:
3
ppeeefpffeefe
pefepeefe
peeef
peefe
peeef
peepefefe
Sample output:
There are 640 black pixels.
There are 512 black pixels.
There are 384 black pixels.
*/

using namespace std;
const int maxn = 1+4+16+64+256+1024;
int t1[maxn+1];
int t2[maxn+1];
int cs;
char tc;
int re;

void read_t(int root,int* t){
    cin >> tc;
    //cout<<"r"<<root<<endl;
    switch(tc){
        case 'e': break;
        case 'f':
            t[root] = 2;break;
        case 'p':
            t[root] = 1;
            read_t(root*4-2,t);
            read_t(root*4-1,t);
            read_t(root*4,t);
            read_t(root*4+1,t);
            break;
    }
}

void cal(int root,int val){
    if(t1[root] == 2) re+= val;
    if(t1[root] == 1) {
        cal(root*4 - 2,val/4);
        cal(root*4 - 1,val/4);
        cal(root*4, val/4 );
        cal(root*4 + 1,val/4);
    }
}
inline void Do(){
    cin>>cs;
    int ind;
    while(cs--){
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        re = 0;
        ind = 1;
        read_t(1,t1);
        read_t(1,t2);
        for(ind = 0;ind < maxn;ind++)
            t1[ind] = (t1[ind] > t2[ind] ? t1[ind] : t2[ind]);
        cal(1,1024);
        cout<<"There are "<<re<<" black pixels."<<endl;
    }
}

int main()
{
    Do();
    return 0;
}
