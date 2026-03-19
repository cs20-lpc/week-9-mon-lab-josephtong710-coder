#include "LinkedQueue.hpp"
#include <iostream>
using namespace std;

int main() {
    LinkedQueue<int> queueA;
    const int MAX_SIZE = 10;

    // Test front/back on empty queue
    try { cout << queueA.front() << " "; } catch (string& e) { cout << e << " "; }
    try { cout << queueA.back()  << " "; } catch (string& e) { cout << e << " "; }

    // Single element
    queueA.enqueue(-5);
    cout << "A length: " << queueA.getLength() << " ";
    cout << "A front: "  << queueA.front()     << " ";
    cout << "A back: "   << queueA.back()      << " ";

    queueA.dequeue();
    cout << "A length: " << queueA.getLength() << " ";
    try { cout << queueA.front() << " "; } catch (string& e) { cout << e << " "; }
    try { cout << queueA.back()  << " "; } catch (string& e) { cout << e << " "; }

    // Enqueue 0-9
    for (int i = 0; i < MAX_SIZE; i++) queueA.enqueue(i);

    cout << "A length: " << queueA.getLength() << " ";
    cout << "A front: "  << queueA.front()     << " ";
    cout << "A back: "   << queueA.back()      << " ";

    // Copy A into B (copy constructor)
    LinkedQueue<int> queueB = queueA;

    // Drain A
    cout << "A contains: ";
    for (int i = 0; i < MAX_SIZE; i++) { cout << queueA.front() << ' '; queueA.dequeue(); }
    cout << " ";

    if (queueA.isEmpty()) cout << "A is now empty ";
    else                  cout << "A is not empty [ERROR] ";

    // Inspect B
    cout << "B length: " << queueB.getLength() << " ";
    cout << "B front: "  << queueB.front()     << " ";
    cout << "B back: "   << queueB.back()      << " ";

    // Copy B into C (assignment operator), then clear B
    LinkedQueue<int> queueC;
    queueC = queueB;
    queueB.clear();

    if (queueB.isEmpty()) cout << "B is now empty ";
    else                  cout << "B is not empty [ERROR] ";

    // Inspect C
    cout << "C length: " << queueC.getLength() << " ";
    cout << "C front: "  << queueC.front()     << " ";
    cout << "C back: "   << queueC.back()      << " ";

    return 0;
}