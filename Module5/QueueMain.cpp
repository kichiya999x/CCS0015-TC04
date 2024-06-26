// This program demonstrates the IntQeue class
#include <iostream>
#include "intqueue.h"
using namespace std;
int main()
{
    int size = 10;
    IntQueue iQueue(size);
    cout << "Enqueuing " << size << " items...\n";
    // Enqueue items.
    for (int x = 1; x <= size; x++)
    {
        cout << "Enqueueing " << x << endl;
        iQueue.enqueue(x);
    }
        
    // Attempt to enqueue another item.
    cout << "Now attempting to enqueue again...\n";
    iQueue.enqueue(100);
    // Deqeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty())
    {
        cout << iQueue.dequeue() << endl;
    }
    iQueue.clear();
    iQueue.dequeue();
}