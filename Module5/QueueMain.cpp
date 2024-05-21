// This program demonstrates the IntQeue class
#include <iostream>
#include "intqueue.h“
using namespace std;
int main()
{
    int size = 5;
    IntQueue iQueue(size);
    cout << "Enqueuing "<< size <<" items...\n";
    // Enqueue 5 items.
    for (int x = 0; x < size; x++)
    iQueue.enqueue(x);
    // Attempt to enqueue a 6th item.
    cout << "Now attempting to enqueue again...\n";
    iQueue.enqueue(100);
    Main Program
    // Deqeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty())
    {
        cout << iQueue.dequeue() << endl;
    }
    iQueue.clear();
    iQueue
}