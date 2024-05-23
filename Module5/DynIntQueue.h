#include <iostream>
using namespace std;

class DynIntQueue
{
private:
    struct QueueNode
    {
        int value;
        QueueNode *next;
    };
    QueueNode *front, *rear;

public:
    DynIntQueue();
    ~DynIntQueue();
    void enqueue(int num);
    int dequeue();
    bool isEmpty();
    void clear();
};
//************************
// Constructor *
//************************
DynIntQueue::DynIntQueue()
{
    front = NULL;
    rear = NULL;
}
//************************
// Destructor *
//************************
DynIntQueue::~DynIntQueue()
{
    clear();
}
//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue. *
//********************************************
void DynIntQueue::enqueue(int num)
{
    QueueNode *newNode;
    newNode = new QueueNode;
    newNode->value = num;
    newNode->next = NULL;
    // INSERT the new node to the queue
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        // Point the current rear node to the newly created node
        rear->next = newNode;
        // Set the rear pointed to the newly created node
        rear = newNode;
    }
}
//**********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//**********************************************
int DynIntQueue::dequeue()
{
    int num;
    QueueNode *temp;
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        num = front->value;
        temp = front->next;
        delete front;
        front = temp;
        if(front == NULL){
            rear = NULL;
        }
        return num;
    }
}
//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************
bool DynIntQueue::isEmpty()
{
    if (front != NULL)
        return false;
    else
        return true;
}
//********************************************
// Function clear dequeues all the elements *
// in the queue. *
//********************************************
void DynIntQueue::clear()
{
    QueueNode *temp;
    while (front != NULL)
    {
        temp = front->next;
        delete front;
        front = temp;
    }
    
    front = NULL;
    rear = NULL;
}
