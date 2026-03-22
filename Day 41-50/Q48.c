/*Problem: Count Leaf Nodes*/

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

int c(node*t){
    if(!t)return 0;
    if(!t->l&&!t->r)return 1;
    return c(t->l)+c(t->r);
}

node* b(int a[],int i,int n){
    if(i>=n||a[i]==-1)return NULL;
    node*t=nn(a[i]);
    t->l=b(a,2*i+1,n);
    t->r=b(a,2*i+2,n);
    return t;
}

int main(){
    int t,n,i;
    scanf("%d",&t);
    while(t--){
        n=0;
        int a[1000];
        while(scanf("%d",&a[n]),a[n]!=-2)n++;
        node*r=b(a,0,n);
        printf("%d\n",c(r));
    }
    return 0;
}
