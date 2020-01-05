#include <iostream>
/**
Date: 2020/1/5
Author: YC
Sample input:
1
0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2
Sample output:
YES
*/
using namespace std;

int judge(bool &ok){
    int w1,d1,w2,d2;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) w1 = judge(ok);
    if(!w2) w2 = judge(ok);
    if(w1*d1 != w2*d2) ok = 0;
    return w1 + w2;
}

inline void Do(){
    int k;bool ok;
    cin>>k;
    while(k--){
        ok = 1;
        judge(ok);
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(k) cout<<endl;
    }
}
int main()
{
    Do();
    return 0;
}
