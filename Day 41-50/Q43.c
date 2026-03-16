/*Problem : Construct a Binary Tree from the given level-order traversal. */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int d;
    struct node *l,*r;
};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->d=x;
    t->l=t->r=NULL;
    return t;
}

void inorder(struct node* t)
{
    if(t==NULL) return;
    inorder(t->l);
    printf("%d ",t->d);
    inorder(t->r);
}

int main()
{
    int n,i;
    scanf("%d",&n);

    int a[1000];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    if(a[0]==-1)
        return 0;

    struct node* q[1000];
    int f=0,r=0;

    struct node* root=newnode(a[0]);
    q[r++]=root;

    i=1;

    while(i<n && f<r)
    {
        struct node* t=q[f++];

        if(i<n && a[i]!=-1)
        {
            t->l=newnode(a[i]);
            q[r++]=t->l;
        }
        i++;

        if(i<n && a[i]!=-1)
        {
            t->r=newnode(a[i]);
            q[r++]=t->r;
        }
        i++;
    }

    inorder(root);

    return 0;
}
