/*Problem : Given a queue of integers, reverse the queue using a stack.*/
#include <stdio.h>

int main()
{
    int n,i;
    int q[1000],s[1000],top=-1;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&q[i]);

    for(i=0;i<n;i++)
        s[++top]=q[i];

    for(i=0;i<n;i++)
        q[i]=s[top--];

    for(i=0;i<n;i++)
        printf("%d ",q[i]);

    return 0;
}
