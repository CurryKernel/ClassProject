#include <iostream>
#include "MyIntStack_template.h"
#include "temp.cpp"
//ʹ��stack�Զ����������ͣ�����ʵ��ͨ��ջ
using namespace std;

int main()
{
    int n;
    double item;
    MyStack<double> numbers;
    cout<<"please enter a number:"<<endl;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>item;
        numbers.push(item);
    }
    cout<<endl<<endl;
    while (!numbers.Empty())
    {
        numbers.top(item);
        cout<<item<<" ";
        numbers.pop();
    }
    numbers.fun2();
    cout<<endl;
    return 0;
}

