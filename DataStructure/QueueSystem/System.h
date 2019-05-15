#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include "allheader.h"

class QueueSystem
{
public:
    // ��ʼ������ϵͳ
    QueueSystem(double total_service_time, int window_num);
    // ����ģ��
    void simulate(int simulate_num);

    double getAvgStayTime()
    {
        avg_stay_time=customer_stay_time/total_customer_num;
        return avg_stay_time;
    }
    double getAvgCustomers()
    {
        avg_customers=total_service_time/total_customer_num;
        return avg_customers;
    }

private:
    // �ö���ϵͳ����һ��
    double run();

    // ��ʼ�����ֲ���
    void init();

    // ��ÿ��д�������
    int getIdleServiceWindow();

    // ����˿͵����¼�
    void customerArrived();

    // ����˿��뿪�¼�
    void customerDeparture();

    // ���񴰿ڵ�����
    int window_num;

    // �ܵ�Ӫҵʱ��
    double total_service_time;

    // �˿͵Ķ�����ʱ��
    double customer_stay_time;

    // �ܹ˿���
    int total_customer_num;

    // ���ĳ�Ա
    queue<Customer> customer_queue;
    queue<Event>  event_list;
    queue<ServiceWindow> windows[5];

    // ���ⲿ���õĽ��
    double avg_customers;
    double avg_stay_time;

};

void QueueSystem::init()
{
    total_service_time=0;
    avg_customers=0;
    avg_stay_time=0;
    customer_stay_time=0;
    total_customer_num=0;
}

void QueueSystem::QueueSystem(double total_service_time, int window_num)
{
    init();
    run();


}
#endif // SYSTEM_H_INCLUDED
