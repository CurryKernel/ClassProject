#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void permutation(int n,int *A,vector<int> &B,int cur);
void print(int n,int *A,vector<int> &B);
void find_max(int n,int *A);

int main()
{
    int n;
    int A[20];
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    sort(A,A+n);            //½µÐòÅÅÐò
    vector<int> B(A,A+n);  //³õÊ¼»¯Ò»¸öÓëÊý×éÏàÍ¬ÔªËØµÄB vector
    find_max(n,A);          //ÕÒ×î´óÊý
    permutation(n,A,B,0);   //´òÓ¡×Ó¼¯
    return 0;
}


void print(int n,int *A,vector<int> &B)
{
    int flag=1;
    for (int i=0; i<n-1; i++)
    {
        if (B[i])
        {
            if (A[i]==A[i+1] && B[i]!=B[i+1])
                flag=0;
        }
    }
    if (!flag) return;
    for (int i=0; i<n; i++)
    {
        if (B[i])
            cout<<A[i];
    }
    cout<<endl;
}

void permutation(int n,int *A,vector<int> &B,int cur)
{
    if (cur==n)
    {
        print(n,A,B);
        return;
    }
    B[cur]=0;
    permutation(n,A,B,cur+1);
    B[cur]=1;
    permutation(n,A,B,cur+1);
}

void find_max(int n,int *A)
{
    int a,b,c,flag=0;
    for (int i=n-1; i>=1; i--)
    {
        a=A[i];
        int ii=i;
        int j=0;
        while (j<ii)
        {
            if (flag)
                break;
            b=A[j];
            c=A[ii];
            if (a==b+c)
            {
                cout<<a<<endl;
                flag=1;
                break;
            }
            else if (a>b+c)
            {
                b=A[++j];
            }
            else if (a<b+c)
            {
                c=A[--ii];
            }
        }
    }
}


