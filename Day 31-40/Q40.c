/*Problem: Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/
#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int l=2*i+1,r=2*i+2,largest=i,t;

    if(l<n && a[l]>a[largest])
        largest=l;

    if(r<n && a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        heapify(a,n,largest);
    }
}

void heapsort(int a[], int n)
{
    int i,t;

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    for(i=n-1;i>=0;i--)
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;

        heapify(a,i,0);
    }
}

int main()
{
    int n,i,a[1000];

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    heapsort(a,n);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
