#include <iostream>
using namespace std;
#define maxQueue 100
typedef int queueEntry;

typedef struct Queue
{
    int front;
    int rear;
    int size;
    queueEntry entry[maxQueue];
} queue;

void createQueue(queue* qptr)
{
    qptr->front= 0;
    qptr->rear = -1;
    qptr->size = 0;
}
bool full(queue* qptr)
{
    return (qptr->size == maxQueue);
}

void enqueue(queueEntry value,  queue* qptr)
{
    if(!full(qptr))
    {
        qptr->entry[(++qptr->rear)%maxQueue] = value;
        qptr->size++;
    }
}

bool empty(queue* qptr)
{
    return !qptr->size;
}

queueEntry dequeue(queue* qptr)
{
    if(!empty(qptr))
    {
        qptr->size--;
        return qptr->entry[(qptr->front++)%maxQueue];
    }
}

void displayQueue(queue* qptr)
{
    int p1 = qptr->front;
    int p2 = qptr->rear+1;
    while(p1 != p2)
    {
        cout << qptr->entry[(p1++)%maxQueue] << " ";
    }
    cout << '\n';
}

int queueSize(queue* qptr)
{
    return qptr->size;
}

void clearQueue(queue* qptr)
{
    qptr->front = 0;
    qptr->rear = -1;
    qptr->size = 0;
}

int main()
{
    return 0;
}
