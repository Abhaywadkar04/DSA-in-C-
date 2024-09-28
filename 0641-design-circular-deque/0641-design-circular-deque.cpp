class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class MyCircularDeque {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) : capacity(k), size(0), front(nullptr), rear(nullptr) {}

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            front->next = rear->next = newNode;
        } else {
            newNode->next = front;
            rear->next = newNode;
            front = newNode;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            newNode->next = front;
            rear = newNode;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (size == 1) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (size == 1) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            while (temp->next != rear) {
                temp = temp->next;
            }
            delete rear;
            rear = temp;
            rear->next = front;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return rear->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
