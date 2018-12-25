#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <iostream>
#include <vector>
#include "class_int.h"

using namespace std;
int MaxBit(vector<integers> data) //�����ݵ����λ��
{
    int p = 1;
    int k;
    for(size_t i = 0; i < data.size(); i++)
    {
        k=data[i].number.size();
        if(k >= p)
        {
            p = k;
        }
    }
    return p;
}

void BucketSort(vector<integers> &data,  int begin1, int end1,int radix,int threshold,int signal)
{
// radix ��ʾ���бȽϵĻ���
// threshold  ��ʾ���λ��
    int cunt[10];
    integers *tmp = new integers[end1-begin1+1];
    int i, k,j,p1,p2;
    for(i = 0; i < 10; i++)  //��ʼ��
        cunt[i] = 0;
    for(i = begin1; i <= end1; i++)
    {
        k=0;
        if (int(data[i].number.size()) >= radix)
        {
            k=data[i].number[radix-1];
        }
        cunt[k]++;//ͳ��ÿ��Ͱ������
    }
    for(i = 1; i < 10; i++)
    {
        cunt[i] = cunt[i - 1] + cunt[i]; //��������
    }
    for(i = end1 ; i >= begin1 ; i--) //������Ͱ�м�¼�����ռ���tmp��
    {
        k=0;
        if (int(data[i].number.size()) >= radix)
        {
            k=data[i].number[radix-1];
        }
        tmp[cunt[k] - 1] = data[i];
        cunt[k]--;
    }
    for(i = begin1,j=0; i <= end1; i++,j++) //����ʱ��������ݸ��Ƶ�data��
    {
        data[i] = tmp[j];
    }
    delete[] tmp;
    switch (signal)
    {
    case 0:
        if (radix<threshold)
        {
            cout<<"radix = "<<radix<<endl;
            BucketSort(data, begin1, end1,radix+1,threshold,signal);
        }
        break;
    case 1:
        for (i=0; i<10; i++)
        {
            if (i == 9)                //�������һλ
            {
                p1=begin1+cunt[i];
                p2=end1-begin1;
            }
            else
            {
                p1=begin1+cunt[i];
                p2=begin1+cunt[i+1]-1;
            }
            if (p1 < p2 && radix>1)
            {
                BucketSort(data, p1, p2,radix-1,threshold,signal);
            }
        }
        break;
    default:
        cout<<"wrong enter!"<<endl;
        return;
    }
    return;
}




#endif // SORT_H_INCLUDED
