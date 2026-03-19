#include <iostream>
#include "LinkedQueue.hpp"

using namespace std;

int main(){
    LinkedQueue<int> queue;

    // Test exceptions on empty queue
    try {
        queue.front();
    } catch (string& e) {
        cout << "front: " << e << endl;
    }

    try {
        queue.back();
    } catch (string& e) {
        cout << "back: " << e << endl;
    }

    try {
        queue.dequeue();
    } catch (string& e) {
        cout << "dequeue: " << e << endl;
    }

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.front() << endl;      // Should print 10
    cout << "Back element: " << queue.back() << endl;        // Should print 30
    cout << "Queue length: " << queue.getLength() << endl;   // Should print 3

    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl;     // Should print 20
    cout << "Queue length after dequeue: " << queue.getLength() << endl;  // Should print 2

    queue.clear();
    cout << "Is queue empty after clear? " << (queue.isEmpty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}