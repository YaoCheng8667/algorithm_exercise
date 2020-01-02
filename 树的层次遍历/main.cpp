#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
/**
Date: 2020/1/2
Author: YC
Test cases:
(11,LL) (7,LLL) (8,R) (5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()

Right answer:
5 4 8 11 13 4 7 2 1
not complete

*/
const int maxn = 1000;
bool err = 0;

struct node{
    bool hasval = false;
    int val = -1;
    node* l = NULL;
    node* r = NULL;
};

void output(node* root){
    if(err){
        printf("not complete\n");
        return;
    }
    queue<node*> q;
    vector<int> re;
    q.push(root);
    node* tnode;
    while(!q.empty()){
        tnode = q.front();
        if(!tnode->hasval) break;
        q.pop();
        re.push_back(tnode->val);
        if(tnode->l) q.push(tnode->l);
        if(tnode->r) q.push(tnode->r);
    }
    if(!q.empty()) printf("not complete\n");
    else{
        size_t i;
        for(i = 0;i < re.size() - 1;i++)
            printf("%d ",re[i]);
        printf("%d\n",re[i]);
    }
}

void delete_tree(node* root){
    if(root == NULL) return;
    delete_tree(root->l);
    delete_tree(root->r);
    delete root;
}

void Do(){
    char s[maxn];
    node *root = new node();
    node *recent;
    int t;char* c;
    while(~scanf("%s",s)){
        if(strcmp(s,"()") == 0){
            output(root);
            delete_tree(root);
            root = new node();
            err = 0;
            continue;
        }
        if(err) continue;
        sscanf(&s[1],"%d",&t);
        recent = root;
        for(c = strchr(s,',')+1;*c!=')';c++){
            if(*c == 'L'){
                if(!recent->l) recent->l = new node();
                recent = recent->l;
            }else{
                if(!recent->r) recent->r = new node();
                recent = recent->r;
            }
        }
        if(recent->hasval){
            err = 1; continue;
        }else{
            recent->hasval = 1;
            recent->val = t;
        }
    }

}

int main()
{
    Do();
    return 0;
}
