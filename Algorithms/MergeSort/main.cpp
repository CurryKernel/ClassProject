#include<iostream>
#include<math.h>
#include<stdlib.h>

void mergearray(int a[], int first, int mid, int last, int temp[]);
void mergesort(int a[], int first, int last, int temp[]);
bool MergeSort(int a[], int n);

using namespace std;
int main()
{
    int i=0;
    int a[10]= {0};
    for(i=0; i<10; i++)
    {

        a[i]=rand()%10;
        cout<<a[i]<<" ";

    }
    cout<<endl;
    MergeSort(a,10);
    for(i=0; i<10; i++)
    {

        cout<<a[i]<<" ";

    }
    return 0;
}
//first code the outline
void mergesort(int a[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);    //�������
        mergesort(a, mid + 1, last, temp); //�ұ�����
        mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
    }
}




//���ж�����������a[first...mid]��a[mid...last]�ϲ���
void mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;

    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}


bool MergeSort(int a[], int n)
{
    int *p = new int[n];
    if (p == NULL)
        return false;
    mergesort(a, 0, n - 1, p);
    delete[] p;
    return true;
}
