#include <iostream>
#include "skiing.h"
using namespace std;


skining::skining()
{
    cout<<"please enter the R/C"<<endl;
    cin>>Row>>Column;
    for (int i=1; i<=Row; i++)
    {
        for (int j=1; j<=Column; j++)
        {
            cin>>field[i][j];
            dis_sk[i][j]=0;
        }
    }
    cout<<"finish init!"<<endl;
    len=0;  //��ʼ���߶�
}

int skining::test_bound(int R,int C)
{
    int flag=0;
    int new_R,new_C;
    for (int i=0; i<4; i++)
    {
        //�ó���һ���ĵ�
        new_R=R+dir[0][i];
        new_C=C+dir[1][i];
        if (new_C>=1 && new_C<=Column &&new_R>=1 && new_R<=Row)
        {
            //�����һ���ĵ㲻�Ǳ߽�
            if (field[new_R][new_C]!=10001 && field[new_R][new_C]<=field[R][C])
            {
                //�����һ���ĵ�û���߹����Ҹ߶ȸ���
                flag=1;
                break;
            }
        }
    }
    return !flag;
}

void skining::calculate(int R,int C,int milage)
{
    int temp_high;
    int new_R,new_C;
    if (test_bound(R,C))
    {
        len=milage>len?milage:len;
        return;
    }
    else
    {
        for (int i=0; i<4; i++)
        {
            //�ó���һ���ĵ�
            new_R=R+dir[0][i];
            new_C=C+dir[1][i];
            if (new_C>=1 && new_C<=Column &&new_R>=1 && new_R<=Row)
            {
                //�����һ���ĵ㲻�Ǳ߽�
                if (field[new_R][new_C]!=10001 && field[new_R][new_C]<field[R][C])
                {
                    milage+=1;
                    temp_high=field[R][C];
                    field[R][C]=10001;
                    //               cout<<"next step "<<new_R<<" * "<<new_C<<endl;
                    //               cout<<"step =="<<milage<<endl;
                    calculate(new_R,new_C,milage);
                    field[R][C]=temp_high;
                    milage-=1;
                }
            }
        }
    }
}

int skining::dis(int C,int R)
{
    int temp;
    int new_R,new_C;
    if (dis_sk[C][R]) return dis_sk[C][R];//����Ѿ����ڣ���ֱ�ӷ���
    for (int i=0; i<4; i++)
    {
        new_C=C+dir[0][i];
        new_R=R+dir[1][i];
        if (in_bound(new_C,new_R))//����ڽ���
        {
            if (field[C][R]>field[new_C][new_R])//�������˳�Ż�����
            {
                temp=dis(new_C,new_R);
                dis_sk[C][R]=dis_sk[C][R]>temp?dis_sk[C][R]:temp+1;
            }
        }
    }
    return dis_sk[C][R];
}

int skining::in_bound(int R,int C)
{
    return R>=1 && R<=Row && C>=1 && C<=Column;
}



