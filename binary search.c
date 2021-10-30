//this program contain two type of binary search i.e recursive and iterative 
#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array a)
{
    int i;
    printf("Elements  are : ");
    for (i = 0; i < a.length; i++)
        printf("%d ", a.A[i]);
}

//iterative function of binary BinSearch
int BinSearch(struct Array a , int key)
{

    int l,mid,h;
    l=0;
    h=a.length-1;

    while(l<=h) {
        mid=(l+h)/2;
        if(key==a.A[mid])
        return mid;
        else if(key<a.A[mid])
            h=mid-1;
        else
            l=mid+1;

    }
    return -1;
}
// recursive function for BinSearch
int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key == a[mid])return mid;
        else if (key<a[mid])
        return RBinSearch(a,l,mid-1,key);
        else return RBinSearch(a,mid+1,h,key);
    }
}
int main()
{

    struct Array a = {{2, 3, 4, 5, 6}, 10, 5};

    printf("%i \n", RBinSearch(a.A,0,a.length, 6));
    Display(a);
    return 0;
}
