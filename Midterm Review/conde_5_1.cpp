#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Queue {
  private:
    int front, rear, size;
    int arr[MAX_SIZE];

  public:
    Queue() {
      front = rear = -1;
      size = 0;
    }

    bool isEmpty() {
 		return (size == 0);
    }

    bool isFull() {
        return (size == MAX_SIZE);
    }

    void enqueue(int x) {
      if (isFull()) {
        cout << "Error: Queue is full!" << endl;
        return;
      }

      if (isEmpty()) {
        front = rear = 0;
      } else {
        rear++;
      }

      arr[rear] = x;
      size++;
    }

    int dequeue() {
      if (isEmpty()) {
        cout << "Error: Queue is empty!" << endl;
        return -1;
      }

      int x = arr[front];
      if (front == rear) {
        front = rear = -1;
      } else {
        front++;
      }

      size--;
      return x;
    }

    int getSize() {
      return size;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int i;
        cout << "Queue: ";
        for (i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front]; // Add a return statement to return the front element
    }
};

int main() {
  Queue q;
  q.enqueue(5);
  q.enqueue(10);
  q.enqueue(15);
  q.enqueue(20);

  q.displayQueue();
  cout << "Front element: " << q.getFront() << endl;

  q.dequeue();
  q.dequeue();

  q.displayQueue();
  cout << "Front element: " << q.getFront() << endl;

  return 0;
}
