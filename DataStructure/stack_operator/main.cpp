#include <iostream>
#include <cctype>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include "fun.h"
//cannot express negative;

using namespace std;
void EvaluateExpression();
int main()
{
    EvaluateExpression();
    return 0;
}


void EvaluateExpression()
{
    char c;
    string temp="";
    stack<double> number;
    stack<char> op;
    op.push('#');
    cin>>c;
    do
    {
        if (isdigit(c) || c=='.')
        {
            temp+=c;
            cin>>c;
        }
        else
        {
            if (temp!="")   //��������ַ�����Ϊ�գ����¸�char��Ϊ���֣���push
            {
                number.push(ToDouble(temp));
                temp="";   //�����ÿգ��Ա�洢��һ������
            }
            switch (precede(op.top(),c))
            {
            case '<':
                op.push(c);
                cin>>c;
                break;
            case '=':
                op.pop();
                cin>>c;
                break;
            case '>':
                double a,b;
                char theta;
                theta=op.top();    //�����������������
                op.pop();
                b=number.top();    //������������
                number.pop();
                a=number.top();
                number.pop();
                number.push(operate(a,theta,b));   //���������ֵpush
                break;
            }
        }
    }
    while (c!='#' || op.top()!='#');
    cout<<number.top()<<endl;
}


