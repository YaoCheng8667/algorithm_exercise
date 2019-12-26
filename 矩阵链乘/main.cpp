#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <stack>
/**
Date: 2019/12/26
Author: yc

Test case:
3
A 50 10
B 10 20
C 20 5
(A(BC))
(A)
((AB)C)

Right answer:
3500
0
15000

*/
using namespace std;

map<char,int> row;
map<char,int> col;
int n;

struct matrix{
    int r,c;
    matrix(int R = 0,int C = 0):r(R),c(C){}
};

inline void Do(){
    cin >> n;
    int t1,t2;char tc;
    for(int i = 0 ; i < n; i++ ){
        cin>>tc>>t1>>t2;
        row[tc] = t1; col[tc] = t2;
    }
    string str;int re,err;matrix tm1,tm2;
    while(cin >> str){
        stack<matrix> s;re = 0,err = 0;
        for(char c : str){
            switch(c){
                case '(':
                    break;
                case ')':
                    tm1 = s.top();s.pop();
                    if(s.empty()){
                        break;
                    }else{
                        tm2 = s.top();s.pop();
                        //matrix tm2.tm1
                        if(tm2.c != tm1.r){
                            err = 1;
                            cout<<"illegal multiplication"<<endl;
                        }else{
                            re += tm2.r*tm2.c*tm1.c;
                            s.push(matrix(tm2.r,tm1.c));
                        }
                    }
                    break;
                default:
                    if(!isalpha(c)){
                        err = 1;
                        cout<<"error the char must be alpha"<<endl;
                    }
                    s.push(matrix(row[c],col[c]));
                    break;
            }
            if(err) break;
        }
        cout<<re<<endl;
    }
}

int main()
{
    Do();
    return 0;
}
