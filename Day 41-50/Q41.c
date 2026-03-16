/*Problem Statement: Implement a Queue using a linked list supporting enqueue and dequeue operations.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int d;
    struct node* next;
};

struct node *f=NULL,*r=NULL;

void enqueue(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->d=x;
    t->next=NULL;

    if(r==NULL)
    {
        f=r=t;
    }
    else
    {
        r->next=t;
        r=t;
    }
}

void dequeue()
{
    if(f==NULL)
    {
        printf("-1\n");
        return;
    }

    struct node* t=f;
    printf("%d\n",f->d);
    f=f->next;

    if(f==NULL)
        r=NULL;

    free(t);
}

int main()
{
    int n,x,i;
    char op[20];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0)
        {
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0)
        {
            dequeue();
        }
    }

    return 0;
}
