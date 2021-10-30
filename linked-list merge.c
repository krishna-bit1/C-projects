

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
//display of array
void Display(struct Array* a)
{
    int i;
    printf("Elements  are : ");
    for (i = 0; i < a->length; i++)
        printf("%d ", a->A[i]);
}
//Inserstion sort
void InsertSort(struct Array *a, int x)
{
    int i = a->length - 1;
    if (a->length == a->size)
        return;
    while (i >= 0 && a->A[i] > x)
    {
        a->A[i + 1] = a->A[i];
        i--;
    }
    a->A[i + 1] = x;
    a->length++;
}

//checking elements are sorted or not
int isSorted(struct Array a)
{
    int i;
    for (i = 0; i < a.length - 1; i++)
    {
        if (a.A[i] > a.A[i + 1])
            return 0;
    }
    return 1;
}

//swaping between element 
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//rearranging the array
void Rearrange(struct Array *a)
{
    int i, j;
    i = 0;
    j = a->length - 1;
    while (i < j)
    {
        while (a->A[i] < 0)
            i++;
        while (a->A[i] >= 0)
            j--;
        if (i < j)
            swap(&a->A[i], &a->A[j]);
    }
}
// merging of two array
struct Array* merge(struct Array *a1, struct Array *a2)
{
    int i,j,k;
    i=j=k=0; 
    struct Array *a3=(struct Array *)malloc(sizeof(struct Array));

    while (i<a1->length && j<a2->length)
    {
        if(a1->A[i]<a2->A[j])
            a3->A[k++]=a1->A[i++];
        else
            a3->A[k++]=a2->A[j++];

    }
    for(;i<a1->length;i++)
        a3->A[k++]=a1->A[i++];

    for (; j  < a2->length; j++)
        a3->A[k++] = a2->A[j++];

    a3->length=a1->length+a2->length;
    a3->size=10;

    return a3;
}
//main
int main()
{
    struct Array a1={{2,6,10,15,25},10,5};
    struct Array a2={{3,4,7,18,20},10,5};
    struct Array *a3;

    a3=merge(&a1,&a2);
    Display(a3);
    return 0;
}
