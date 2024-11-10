#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        ++size;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Очередь пуста");
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        --size;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Очередь пуста");
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int getSize() const {
        return size;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
