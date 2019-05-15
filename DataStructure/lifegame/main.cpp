#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lifegame.h"

using namespace std;

int main()
{
    char ans;   //��������
    life lifeTest;    //����һ����lifeTest
    lifeTest.initialize();   //��ʼ������
    do
    {
        lifeTest.print();    //��ӡ����
        lifeTest.update();   //���¾���
        cout<<"please enter a char to decide whether continue(y/n):"<<endl; //���û������Ƿ����
        cin>>ans; //����ans��
    }
    while (ans != 'n');
    return 0;
}



void life::initialize()
{
    int i,j;
    srand(time(NULL)); //ʹ��ʱ�������������
    for(i=0; i<=maxrow+1; i++)
    {
        for (j=0; j<=maxcol+1; j++)
        {
            life::grif[i][j]=0;  //�������ʼ��Ϊ0
        }
    }
    for(i=1; i<=maxrow; i++)
    {
        for (j=1; j<=maxcol; j++)
        {
            life::grif[i][j]=rand()%2;   //ʹ��rand�����������������������
        }
    }
    cout<<"finish initialize!"<<endl;
}

int life::neighbor_count(int row,int col)
{
    int cunt=0,i,j;
    int MoveRow[3]= {-1,0,1};   //�������ƶ�����
    int MoveCol[3]= {-1,0,1};   //�������ƶ�����
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            if (life::grif[row+MoveRow[i]][col+MoveCol[j]]==1) cunt++;
        }
    }
    if (life::grif[row][col]==1) return cunt-1;  //���Լ��ǻ�ģ�����Ҫ��ȥ�Լ�
    else return cunt;
}

void life::update()
{
    int number,i,j,tempMatrix[maxrow+2][maxcol+2];
    memcpy(tempMatrix,grif,sizeof(grif));  //ʹ��tempMatrix��ʱ�洢����
    for(i=1; i<=maxrow; i++)
    {
        for (j=1; j<=maxcol; j++)
        {
            number=life::neighbor_count(i,j);  //����ÿ��λ�õ���Χ���˵ĸ���
            if (life::grif[i][j]==1)
            {
                if (number<=1 || number>=4) tempMatrix[i][j]=0;  //����tempMatrix
            }
            else
            {
                if (number==3) tempMatrix[i][j]=1;
            }
        }
    }
    memcpy(grif,tempMatrix,sizeof(tempMatrix));  //�����ºõľ����Ƹ�grif
}

void life::print()   //��ӡ����
{
    int i,j;
    for(i=1; i<=maxrow; i++)
    {
        for (j=1; j<=maxcol; j++)
        {
            cout<<life::grif[i][j]<<" ";
        }
        cout<<endl;
    }
}
