#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED
#include "allheader.h"
using namespace std;

struct Event {
    double next_occur_time;
    // ʹ�� -1 ��ʾ�����¼�, >=0 ��ʾ�뿪�¼�, ͬʱ��ֵ��ʾ���뿪�ķ��񴰿�
    int event_type=-1;
    double during_time;
};





#endif // EVENT_H_INCLUDED
