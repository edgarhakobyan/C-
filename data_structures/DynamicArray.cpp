#include <iostream>

template <typename T>
class DynamicArray {
    private:
        int size;
        int maxSize;
        T* arrayHolder;

    public:
        DynamicArray() {
            this->size = 0;
            this->maxSize = 5;
            this->arrayHolder = new T[this->maxSize];
        }

        T& operator[](T i) {
            assert(i < this->size);
            return this->arrayHolder[i];
        }

        void add(T num) {
            if (this->size >= this->maxSize) {
                this->maxSize *= 2;
                T* tmp = new T[this->maxSize];
                for (size_t i = 0; i < this->size; ++i) {
                    tmp[i] = this->arrayHolder[i];
                }
                delete[] this->arrayHolder;
                this->arrayHolder = tmp;
            }
            this->arrayHolder[this->size] = num;
            ++this->size;
        }

        void addAtIndex(T num, int index) {
            if (index > this->size) {
                this->add(num);
            } else if (index == this->size) {
                this->arrayHolder[this->size] = num;
                ++this->size;
            } else {
                int diff = this->size - index;
                T* tmp = new T[diff];
                for (size_t i = 0; i < diff; ++i) {
                    tmp[i] = this->arrayHolder[index + i];
                }
                this->arrayHolder[index] = num;
                ++this->size;
                for (size_t i = 0; i < diff; ++i) {
                    this->arrayHolder[index + i + 1] = tmp[i];
                }
                delete[] tmp; 
            }
        }

        int getSize() {
            return this->size;
        }

        ~DynamicArray() {
            delete[] this->arrayHolder;
        }
};

int main() {
    DynamicArray<int> arrInt;
    arrInt.add(4);
    arrInt.add(7);
    arrInt.add(2);
    arrInt.add(9);
    arrInt.add(34);
    arrInt.addAtIndex(87, 3);
    for (size_t i = 0; i < arrInt.getSize(); ++i) {
        std::cout << arrInt[i] << std::endl;
    }

    std::cout << std::endl;

    DynamicArray<char> arrChar;
    arrChar.add('a');
    arrChar.add('b');
    arrChar.add('c');
    arrChar.add('d');
    arrChar.addAtIndex('N', 2);
    for (size_t i = 0; i < arrChar.getSize(); ++i) {
        std::cout << arrChar[i] << std::endl;
    }
    
    return 0;
}