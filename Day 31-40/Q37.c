/* Implement a Priority Queue using an array. An element with smaller value has higher priority. */
#include <stdio.h>
#include <string.h>

int main()
{
    int n,a[1000],size=0,i,j,x;
    char op[10];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            j=size-1;
            while(j>=0 && a[j]>x)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=x;
            size++;
        }
        else if(strcmp(op,"delete")==0)
        {
            if(size==0)
                printf("-1\n");
            else
            {
                printf("%d\n",a[0]);
                for(j=1;j<size;j++)
                    a[j-1]=a[j];
                size--;
            }
        }
        else if(strcmp(op,"peek")==0)
        {
            if(size==0)
                printf("-1\n");
            else
                printf("%d\n",a[0]);
        }
    }

    return 0;
}
