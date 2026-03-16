/*Problem : Implement a Min Heap using an array where the smallest element is always at the root.*/
#include <stdio.h>
#include <string.h>

int a[1000],n=0;

void up(int i)
{
    int p,t;
    while(i>0)
    {
        p=(i-1)/2;
        if(a[p]>a[i])
        {
            t=a[p];
            a[p]=a[i];
            a[i]=t;
            i=p;
        }
        else
            break;
    }
}

void down(int i)
{
    int l,r,s,t;
    while(1)
    {
        l=2*i+1;
        r=2*i+2;
        s=i;

        if(l<n && a[l]<a[s]) s=l;
        if(r<n && a[r]<a[s]) s=r;

        if(s!=i)
        {
            t=a[i];
            a[i]=a[s];
            a[s]=t;
            i=s;
        }
        else
            break;
    }
}

int main()
{
    int m,x,i;
    char op[20];

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            a[n]=x;
            up(n);
            n++;
        }
        else if(strcmp(op,"extractMin")==0)
        {
            if(n==0)
                printf("-1\n");
            else
            {
                printf("%d\n",a[0]);
                a[0]=a[n-1];
                n--;
                down(0);
            }
        }
        else if(strcmp(op,"peek")==0)
        {
            if(n==0)
                printf("-1\n");
            else
                printf("%d\n",a[0]);
        }
    }

    return 0;
}
