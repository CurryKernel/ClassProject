#include <iostream>
#include "OnePack.h"

using namespace std;

int main()
{
    int N,M;
    int weight[10],value[10];
    cin>>N;//��Ʒ����
    cin>>M;//��������
    for (int i=1;i<=N; i++)
    {
        cin>>weight[i]>>value[i];
    }
    OnePack(N,M,weight,value);
    return 0;
}
