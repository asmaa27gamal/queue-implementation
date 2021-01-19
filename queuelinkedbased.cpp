#include <iostream>
using namespace std;
typedef int queueEntry;

struct queueNode
{
    queueEntry data;
    queueNode* next;
};
struct queue
{
    queueNode* front;
    queueNode* rear;
    int size;
};

void createQueue(queue* qptr)
{
    qptr->front = NULL;
    qptr->rear = NULL;
    qptr->size = 0;
}

bool empty(queue* qptr)
{
    return !(qptr->front);
}

bool full(queue* qptr)
{
    return false;
}

void enqueue(queueEntry value, queue* qptr)
{
    queueNode* newnode = new(nothrow)queueNode;
        newnode->data = value;
        newnode->next = NULL;
        if(!qptr->rear)
            qptr->front = newnode;
        else
            qptr->rear->next = newnode;
        qptr->rear = newnode;
        qptr->size++;
}

queueEntry dequeue(queue* qptr)
{
    if(!empty(qptr))
    {
        queueNode* nptr = qptr->front;
        qptr->front = qptr->front->next;
        if(!qptr->front)
            qptr->rear = NULL;
        qptr->size--;
        queueEntry element = nptr->data;
        delete nptr;
        return element;
    }
}

void displayQueue(queue* qptr)
{
    if(!empty(qptr))
    {
        queueNode* nptr = qptr->front;
        while(nptr)
        {
            cout << nptr->data << " ";
            nptr = nptr->next;
        }
        cout << '\n';
    }
}

void clearQueue(queue* qptr)
{
    while(qptr->front)
    {
        qptr->rear = qptr->front->next;
        delete qptr->front;
        qptr->front = qptr->rear;
    }
    qptr->size = 0;
}

int queueSize(queue* qptr)
{
    return qptr->size;
}

int main()
{
    return 0;
}
