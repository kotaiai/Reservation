#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class type>
class iqueue
{
    public:
        iqueue(int Size);
        //virtual ~queue();
        void enqueue(type value);
        type dequeue(type &value);
        bool isfull();
        bool isempty();

    private:
        type *quearr;
        int rear;
        int Front;
        int quesize;
        int numsize;

};
template <class type>
iqueue<type>::iqueue(int Size)
{
    quearr = new type[Size];
    quesize = Size;
    Front = 0;
    rear = 0;
    numsize = 0;
}


template <class type>
void iqueue<type>::enqueue(type value)
{
    rear++;
    rear = rear % quesize;
    quearr[rear] = value;
    numsize++;
}

template <class type>
type iqueue<type>::dequeue(type &value)
{
    Front++;
    Front = Front % quesize;
    value = quearr[Front];
    return value;
    numsize--;
}

template<class type>
bool iqueue<type>::isfull()
{
    bool status;
    if(numsize == quesize)
        status = true;
    else
        status = false;

    return status;
}

template<class type>
bool iqueue<type>::isempty()
{
    bool status;
    if(!numsize)
        status = true;
    else
        status = false;
    return status;
}


#endif // QUEUE_H
