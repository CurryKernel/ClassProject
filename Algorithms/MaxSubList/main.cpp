#include <iostream>

using namespace std;
//ɨ�跨
int maxSum(int* a, int n)
{
    int sum=0;
    //��ʵҪ����ȫ�Ǹ�����������ܼ򵥣����Ժ������3��������ֱ�Ӱ����ĳɣ�"int sum=a[0]"����
    //Ҳ���Բ��ģ���ȫ�Ǹ����������ֱ�ӷ���0��Ҳ�����ò��С�
    int b=0;

    for(int i=0; i<n; i++)
    {
        if(b<0)           //...
            b=a[i];
        else
            b+=a[i];
        if(sum<b)
            sum=b;
    }
    return sum;
}

int main()
{
    int a[10]= {7,9,-8,3,-7,6,-13,9};
    //int a[]={-1,-2,-3,-4};  //����ȫ�Ǹ���������
    cout<<maxSum(a,8)<<endl;
    return 0;
}
