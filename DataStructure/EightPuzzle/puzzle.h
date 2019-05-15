#ifndef PUZZLE_H_INCLUDED
#define PUZZLE_H_INCLUDED
#include <string>
#include <vector>
#include <set>
using namespace std;

typedef struct Node *node;
struct Node
{
    string status;
    int pre;     //��һ���ڵ��λ��
    int step;    //���Ѳ���
};



class matrix
{
private:
    vector<node> select1;
    vector<node> select2;
    set<string> SetString1;
    set<string> SetString2;
    int cur;
public:
    matrix();
    void printResult(int ans);
    int judge(string start);   //ÿһ�ν������������ż�Բ��䣨0�������ڣ����������Ե���ż�Բ���
    void printString(string now);
    int BFS(vector<node> &select,int N,set<string> &st);
    int ExistIn(int n,string now,vector<node> &select);
    int findZreo(string now);
    void process();
    string swep(string now,int i,int j);
};






#endif // PUZZLE_H_INCLUDED
