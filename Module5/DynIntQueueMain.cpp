#include <iostream>
#include "dynintqueue.h"
using namespace std;
int main()
{
    int size = 5;
    DynIntQueue iQueue;
    cout << "Enqueuing " << size << " items...\n";
    // Enqueue items.
    for (int x = 1; x <= size; x++)
    {
        cout << "Enqueueing " << x << endl;
        iQueue.enqueue(x);
    }
    // Deqeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty())
    {
        cout << iQueue.dequeue() << endl;
    }

    iQueue.clear();
}