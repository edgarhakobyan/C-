#include <iostream>

template<typename T>
class Node {
    public:
        T value;
        Node* next;
        Node* previous;
        Node(T value) {
            this->value = value;
            this->next = NULL;
            this->previous = NULL;
        }
};

template<typename T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        Queue() {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
        void enqueue(T value) {
            if (this->head == NULL) {
                this->head = new Node<T>(value);
                this->tail = this->head;
            } else {
                this->tail->next = new Node<T>(value);
                this->tail->next->previous = this->tail;
                this->tail = this->tail->next;
            }
            ++this->size;
        }
        Node<T>* dequeue() {
            Node<T>* tmp = this->tail;
            this->tail = this->tail->previous;
            this->tail->next = NULL;
            --this->size;
            return tmp;
        }
        int getSize() {
            return this->size;
        }
};

int main() {
    Queue<int> mQueue;
    mQueue.enqueue(1);
    mQueue.enqueue(2);
    mQueue.enqueue(3);

    std::cout << "\n size " << mQueue.getSize() << std::endl;
    std::cout << "\n dequeue " << mQueue.dequeue()->value << std::endl;
    std::cout << "\n size " << mQueue.getSize() << std::endl;
}