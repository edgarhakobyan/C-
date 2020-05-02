#include <iostream>

template <typename T>
class Node {
    public:
        T value;
        Node* next;
        Node* previous;
        Node(T v) {
            this->value = v;
            this->next = NULL;
            this->previous = NULL;
        }
};

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* iterator;
        int size;
    public:
        LinkedList() {
            this->head = NULL;
            this->tail = NULL;
            this->iterator = NULL;
            this->size = 0;
        }

        void pushBack(T val) {
            if (this->head == NULL) {
                this->head = new Node<T>(val);
                this->tail = this->head;
            } else {
                this->tail->next = new Node<T>(val);
                this->tail->next->previous = this->tail;
                this->tail = this->tail->next;
            }
            ++this->size;
        }

        void popBack() {
            if (this->tail != NULL) {
                this->tail = this->tail->previous;
                delete this->tail->next;
                this->tail->next = NULL;
                --this->size;
            }
        }

        void pushFront(T val) {
            if (this->head == NULL) {
                this->head = new Node<T>(val);
                this->tail = this->head;
            } else {
                this->head->previous = new Node<T>(val);
                this->head->previous->next = this->head;
                this->head = this->head->previous;
            }
            ++this->size;
        }

        void popFront() {
            if (this->head != NULL) {
                this->head = this->head->next;
                delete this->head->previous;
                this->head->previous = NULL;
                --this->size;
            }
            
        }

        void insert(T val, int index) {
            if (this->size == 0) {
                pushFront(val);
            } else {
                this->iterator = this->head;
                for (size_t i = 1; i < index; i++) {
                    this->iterator = this->iterator->next;
                }
                Node<T>* tmp = new Node<T>(val);
                tmp->next = this->iterator->next;
                tmp->next->previous = tmp;
                tmp->previous = this->iterator;
                this->iterator->next = tmp;
                ++this->size;
            }
        }

        void iterateOnList() {
            this->iterator = this->head;
            while (this->iterator != NULL) {
                std::cout << this->iterator->value << std::endl;
                this->iterator = this->iterator->next;
            }
        }

        int getSize() {
            return this->size;
        }
};

int main() {
    LinkedList<int> mList;
    mList.pushBack(32);
    mList.pushBack(24);
    mList.pushFront(54);
    mList.insert(100, 2);

    std::cout << "\n List size " <<  mList.getSize() << std::endl;
    mList.iterateOnList();

    mList.popBack();
    mList.popFront();

    std::cout << "\n List size "  << mList.getSize() << std::endl;
    mList.iterateOnList();

    return 0;
}