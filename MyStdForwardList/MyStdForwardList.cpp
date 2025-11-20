#include <iostream>
#include <initializer_list>

namespace my_std {
    template<typename T>
    class MyForwardList {
    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* head;
        size_t size;

    public:
        MyForwardList() : head(nullptr), size(0) {}

        MyForwardList(std::initializer_list<T> list) : head(nullptr), size(0) {
            Node<T>* current = nullptr;
            for (const T& i : list) {
                Node<T>* newNode = new Node<T>{ i, nullptr };
                if (!head) {
                    head = newNode;
                    current = newNode;
                }
                else {
                    current->next = newNode;
                    current = newNode;
                }
                size++;
            }
        }
        ~MyForwardList() {
            
        }
        // O(N)
        T& operator[](const size_t i) {
            size_t count = 0;
            Node* current = head;
            if (head == nullptr) {
                throw std::out_of_range("Error: out_of_range");
            }
            else {
                while (count != i) {
                    if (current->next == nullptr) {
                        return current->data;
                    }
                    current = current->next;
                    count++;
                }
            }
            return current->data;
        }
        // O(1)
        void insertAtBeginning() {

        }
        void insertAfter() {

        }
        // O(1)
        void deleteAtBeginning() {

        }
        void deleteAtEnd() {

        }
        void display() {
            for (Node<T>* current = head; current != nullptr; current = current->next) {
                std::cout << current->data << std::endl;
            }
        }
        bool isEmpty() {
            return !head;
        }
        Node* getHead() {
            return head;
        }
    };
}

int main()
{
    my_std::MyForwardList<int> forward_list;
    my_std::MyForwardList<int> init_forward_list = {11, 22, 45, 32};

    return 0;
}