#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include "queue.h"
#include <stack>
using namespace std;


struct Pos
{
    int line;
    int row;
    int step;
    int mark=0;
};

template<class T>
class Maze
{
private:
    stack<Pos> sk;
    Pos exit,entry;
    T row,line;
    Pos l[100];  //���߹��ĵ�������飬���ҵ����·��
public:
    T matrix[100][100];
    Maze()
    {
        string name;
        cout<<"DFS or BFS?"<<endl;
        cin>>name;
        if (name=="DFS")
        {
            Initialize();
            GoMaze_DFS();
        }
        else
        {
            Initialize();
            GoMaze_BFS();
        }

    };
    void Initialize();
    void print();
    void GoMaze_DFS();
    void GoMaze_BFS();
};

template<class T>
void Maze<T>::Initialize()
{
    int i,j;
    cout<<"please enter the lines & rows of maze"<<endl;
    cin>>line>>row;
    cout<<"please enter the maze(0 is wall,1 is path)"<<endl;
    for (i=0; i<=line+1; i++)
    {
        for(j=0; j<=row+1; j++)
        {
            matrix[i][j]=0;
        }
    }
    for (i=1; i<=line; i++)
    {
        for(j=1; j<=row; j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<"finish initialize!"<<endl;
    cout<<"enter the entry point: line>>row>>"<<endl;
    cin>>entry.line>>entry.row;
    cout<<"enter the exit point: line>>row>>"<<endl;
    cin>>exit.line>>exit.row;
    sk.push(entry);
    exit.mark=1;
    matrix[entry.line][entry.row]=2;
}

template<class T>
void Maze<T>::print()
{
    int i,j;
    for (i=1; i<=row; i++)
    {
        for (j=1; j<=line; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}



template<class T>
void Maze<T>::GoMaze_DFS()
{
    int flag,k=0;
    int dir[4][2]= {1,0,-1,0,0,1,0,-1}; //���� down left up right
    Pos top,temp,l[100];
    top=sk.top();
    while (top.line!=exit.line || top.row!=exit.row)
    {
        flag=0;
        top=sk.top();
        for(int i=0; i<4; i++)
        {
            temp.line=top.line+dir[i][0];
            temp.row=top.row+dir[i][1];
            if(matrix[temp.line][temp.row]==1) //�����ͨ��
            {
                matrix[temp.line][temp.row]=2; // ����Ѿ��߹�
                sk.push(temp);
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            sk.pop();
        }
        if (sk.empty())
        {
            cout<<"cannot reach!"<<endl;
            break;
        }
        else
        {
            top=sk.top();
        }

    }
    while (!sk.empty())
    {
        l[k++]=sk.top();
        sk.pop();
    }
    cout<<"the road is :"<<endl;
    for (int i=k-1; i>=0; i--)
    {
        cout<<l[i].line<<" "<<l[i].row<<endl;
    }
}



template<class T>
void Maze<T>::GoMaze_BFS()
{
    int step=0,k=0,flag=0;
    int dir[4][2]= {1,0,-1,0,0,1,0,-1}; //����
    Queue<Pos> q;  //���е�ʵ����
    q.init();
    Pos now,temp;
    now=entry;
    now.step=0;
    q.inQueue(now);
    while (1)
    {
        if (q.isempty()) //����ǿն���
        {
            cout<<"cannot reach!"<<endl;
            break;
        }
        now=q.outQueue();  //����ǰ���׵���
        l[k++]=now;
        if (now.line==exit.line && now.row==exit.row)
        {
            cout<<"the step is:" <<now.step<<endl;
            step=now.step;
            flag=1;
            break;
        }
        for(int i=0; i<4; i++)
        {
            temp.line=now.line+dir[i][0];
            temp.row=now.row+dir[i][1];
            if(matrix[temp.line][temp.row]==1) //�����ͨ��
            {
                temp.step=now.step+1;  // ������һ
                matrix[temp.line][temp.row]=2; // ����Ѿ��߹�
                q.inQueue(temp);  //���
            }
        }
    }
    //ѡ�����·��
    if (!flag) return;
    cout<<"the road is :"<<endl;
    now.line=exit.line;
    now.row=exit.row;
    l[k-1].mark=1;
    for (int i=k-2; i>=0; i--)
    {
        temp=l[i];
        if (temp.step==step) continue;  // ��ͬһ�����ĵ���ѡ�����һ������ͨ�ĵ���Ϊ·��
        for(int j=0; j<4; j++)
        {
            if(temp.line+dir[j][0]==now.line && temp.row+dir[j][1]==now.row) //���������ͨ
            {
                l[i].mark=1;  //���ѡ�еĵ�
                step=temp.step;
                now=temp;
                break;
            }
        }
    }
    //��ӡ���·��
    for (int i=0; i<k; i++)
    {
        if (l[i].mark==1)
            cout<<l[i].line<<" "<<l[i].row<<endl;
    }
}
#endif // MAZE_H_INCLUDED
