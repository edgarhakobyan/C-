#include <iostream>

template <typename T>
class Node {
    public:
        T value;
        Node* next;
        Node(T v) {
            this->value = v;
            this->next = NULL;
        }
};

template <typename T>
class Stack {
    private:
        Node<T>* head;
        int size;
    public:
        Stack() {
            this->head = NULL;
            this->iterator = NULL;
            this->size = 0;
        }

        void push(T value) {
            if (this->head == NULL) {
                this->head = new Node<T>(value);
            } else {
                Node<T>* tmp = new Node<T>(value);
                tmp->next = this->head;
                this->head = tmp;
            }
            ++this->size;
        }

        void pop() {
            if (this->head != NULL) {
                this->head = this->head->next;
                --this->size;   
            }
        }

        Node<T>* top() {
            return this->head;
        }

        int getSize() {
            return this->size;
        }

        void print() {
            Node<T>* iterator = this->head;
            while (iterator != NULL) {
                std::cout << iterator->value << std::endl;
                iterator = iterator->next;
            }
        }
};

int main() {
    Stack<char>* myStack;
    myStack->push('a');
    myStack->push('b');
    myStack->push('c');

    myStack->print();

    std::cout << "\n top " << myStack->top()->value << std::endl;

    myStack->pop();
    myStack->print();

    return 0;
}