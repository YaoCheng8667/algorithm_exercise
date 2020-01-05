#include <iostream>
#include <sstream>
/**
Date:2020/1/5
Author:YC
Sample input:
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255
Sample output:
1
3
255
*/
using namespace std;
const int maxn = 10000;
int mid[maxn];
int post[maxn];
int nodes;
int minsum,minleaf;

struct node{
    int val;
    node* l = NULL;
    node* r = NULL;
    node(int v):val(v){}
};

node* init_tree(int *m,int* p ,int sz){
    node* root = new node(p[sz-1]);
    int lsz = 0; //how many nodes on the left tree
    int* t;
    for(t = m; *t != p[sz-1]; t++) lsz++;
    if(lsz > 0)
        root->l = init_tree(m,p,lsz);
    if(sz - lsz - 1 > 0)
        root->r = init_tree(t+1,p+lsz,sz - lsz - 1);
    return root;
}

void cal(node* node,int sum){
    if(!node->l &&!node->r){
        sum+= node->val;
        if(sum < minsum){
            minsum = sum;
            minleaf = node->val;
        }else if(sum == minsum&&node->val < minleaf){
            minleaf = node->val;
        }
    }
    if(node->l)
        cal(node->l, sum + node->val);
    if(node->r)
        cal(node->r, sum + node->val);
}

void del_tree(node* node){
    if(!node) return;
    del_tree(node->l);
    del_tree(node->r);
    delete node;
}

inline void Do(){
    string s1,s2;int ind;node* r;
    while(getline(cin,s1)){
        getline(cin,s2);
        stringstream ss1(s1);
        stringstream ss2(s2);
        ind = 0;
        while(ss1>>mid[ind]) ss2>>post[ind++];
        r = init_tree(mid,post,ind);
        minsum = 1 << 30;
        cal(r,0);
        del_tree(r);
        cout<<minleaf<<endl;
    }

}
int main()
{
    Do();
    return 0;
}
