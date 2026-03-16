/*Problem : Perform inorder, preorder, and postorder traversals of a given binary tree. */
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
    t->l=NULL;
    t->r=NULL;
    return t;
}

void inorder(struct node* t)
{
    if(t==NULL) return;
    inorder(t->l);
    printf("%d ",t->d);
    inorder(t->r);
}

void preorder(struct node* t)
{
    if(t==NULL) return;
    printf("%d ",t->d);
    preorder(t->l);
    preorder(t->r);
}

void postorder(struct node* t)
{
    if(t==NULL) return;
    postorder(t->l);
    postorder(t->r);
    printf("%d ",t->d);
}

int main()
{
    int n,i;
    scanf("%d",&n);

    int a[1000];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    if(a[0]==-1) return 0;

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
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}
