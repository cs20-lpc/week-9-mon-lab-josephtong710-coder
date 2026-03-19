template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    this->head = nullptr;
    this->last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    return this->last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
        Node* current = copyObj.head;
    while (current != nullptr) {
        enqueue(current->value);
        current = current->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
        if (isEmpty()) {
            throw string("error, queue is empty, cannot dequeue");
        }
    Node* temp = head;
    head = head->next;
    delete temp;
    this->length--;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);
    if (isEmpty()) {
        head = this->last = newNode;
    } else {
        this->last->next = newNode;
        this->last= newNode;
    }
   this->length++;

}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
       throw string("error, queue is empty, cannot access the front");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
