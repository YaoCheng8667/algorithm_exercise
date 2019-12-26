#include <iostream>
#include <stack>
#include <cstdio>
/**
Date: 2019/12/26
Author: yc
Test case:
5
5 4 1 2 3
5
5 4 3 2 1

Right answer:
illegal
ok
*/
using namespace std;

const int maxn = 1080;

int n;
int seq[maxn];

inline void Do(){
    int ok,j;
    while(~scanf("%d",&n)){
        stack<int> s;
        for(int i = 0; i < n; i++){
            scanf("%d",&seq[i]);
        }
        j = 1;ok = 1;
        for(int i = 0 ;i < n ;){
            if(seq[i] == j){
                i++;j++;
            }else if(!s.empty() && seq[i]==s.top()){
                s.pop();i++;
            }else{
                if(j < n){
                    s.push(j);j++;
                }else{
                    ok = 0;break;
                }
            }
        }
        printf("%s.\n",ok ? "ok":"illegal");
    }
}


int main()
{
    Do();
    return 0;
}
