#ifndef IO_H_INCLUDED
#define IO_H_INCLUDED
#include <iostream>
#include <stdlib.h>
using namespace std;
// �����ȶ�ȡ�ַ����ٲ���

//ǰ�����������ڵ�����#��ʾ
bool ReadStream_DFS(int &number)
{
    char buffer[32];
    if (cin>>buffer)
    {
        if (buffer[0] != '#')
        {
            number = atoi(buffer);
            return true;
        }
        return false;
    }
    cout<<"end!"<<endl;
    return false;
}

//������,�����ڵ���NULL��ʾ
int ReadStream_BFS(int &number)
{
    char buffer[32];
    if (cin>>buffer)
    {
        if (buffer[0] != 'n')
        {
            number = atoi(buffer);
            return 1;
        }
        return -1;
    }
    cout<<"end"<<endl;
    return 0;
}



#endif // IO_H_INCLUDED
