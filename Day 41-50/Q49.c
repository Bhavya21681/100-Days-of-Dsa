/*Problem: BST Insert*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int v;
    struct node*l,*r;
}node;

node* nn(int x){
    node*t=(node*)malloc(sizeof(node));
    t->v=x;
    t->l=t->r=NULL;
    return t;
}

node* i(node*t,int x){
    if(!t)return nn(x);
    if(x<t->v)t->l=i(t->l,x);
    else t->r=i(t->r,x);
    return t;
}

void p(node*t){
    if(!t)return;
    p(t->l);
    printf("%d ",t->v);
    p(t->r);
}

int main(){
    int t,n,x,i;
    scanf("%d",&t);
    while(t--){
        node*r=NULL;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&x);
            r=i(r,x);
        }
        p(r);
        printf("\n");
    }
    return 0;
}
