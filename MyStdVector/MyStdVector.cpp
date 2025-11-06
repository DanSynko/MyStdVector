#include <iostream>
#include <string>
#include <utility>

namespace my_std {
    template<typename T>
    class MyVector {
    private:
        T* arr;
        T* begin_it;
        T* end_it;
        T* end_capacity;
        int arr_size;
        int arr_capacity;
    public:
        MyVector() : arr_size(5), arr_capacity(20) {
            arr = new T[arr_capacity];
            begin_it = arr;
            end_it = &arr[arr_size];
            end_capacity = &arr[arr_capacity];
        }
        MyVector(const MyVector& other) {
            std::cout << "Constructor of deep copy called: " << std::endl;
            this->arr = new T[other.arr_capacity];
            this->arr_size = other.arr_size;
            this->end_it = &this->arr[this->arr_size];
            this->arr_capacity = other.arr_capacity;
            this->begin_it = this->arr;
            T* i = this->begin_it;
            for (T* ptr = other.begin_it; ptr != other.end_it; ptr++) {
                *i = *ptr;
                i++;
            }
            T* new_end_capacity = &this->arr[this->arr_capacity];
            this->end_capacity = new_end_capacity;
            this->show_vector();
        }
        /*MyVector(MyVector&& other) noexcept {
            
        }*/
        ~MyVector() {
            delete[] arr;
            begin_it = nullptr;
            end_it = nullptr;
            end_capacity = nullptr;
        }
        MyVector& operator=(const MyVector& other) {
            delete this->arr;
            this->arr = new T[other.arr_size];
            for (int i = 0; i < other.arr_size; i++) {
                this->arr[i] = other.arr[i];
            }
            //T* old_arr = other.arr;
            this->arr_size = other.arr_size;
            this->arr_capacity = other.arr_capacity;
            this->begin_it = this->arr;
            this->end_it = &this->arr[arr_size];
            this->end_capacity = &this->arr[arr_capacity];
            return *this;
        }
        /*MyVector& operator=(MyVector&& other) noexcept {

            return *this;
        }*/
        void show_vector() {
            for (T* ptr = begin_it; ptr != end_it; ptr++) {
                std::cout << *ptr << ". ";
            }
            std::cout << "" << std::endl;
        }
        void create_some_arr() {
            for (int i = 0; i < arr_size; i++) {
                arr[i] = i;
            }
            show_vector();
        }
        // The method's complexity should be O(n)(linear time)
        void resize(int new_size) {
            if (arr_capacity > new_size) {
                std::cout << "old size: ";
                size();
                int old_size = arr_size;
                arr_size = new_size;
                if (arr_size > old_size) {
                    for (int i = old_size; i < arr_size; i++) {
                        arr[i] = 0;
                    }
                }
                else if (arr_size < old_size) {
                    for (int i = arr_size; i < old_size; i++) {
                        end_it--;
                    }
                }
                begin_it = arr;
                end_it = &arr[arr_size];
                end_capacity = &arr[arr_capacity];
                std::cout << "new size: ";
                size();
            }
            show_vector(); 
        }
        // O(1)(constant time)
        void push_back(T a) {
            if (arr_size < arr_capacity) {
                *end_it = a;
                end_it++;
                arr_size++;
                show_vector();
            }
            /*else if (arr_size >= arr_capacity) {
                
            }
            std::cout << "Element was added." << std::endl;*/
        }
        // The method's complexity should be O(1)
        void pop_back() {
            arr_size--;
            end_it--;
        }
        void insert(T* iterator_position, const int val) {
            if (arr_size >= arr_capacity) {
                // copy
                
            }
            // O(n)
            if (iterator_position != end()) {
                // shift

            }
            // O(1)
            else {
                // no shift
                *push_back(val);
            }
            show_vector();
        }
        /*void insert(const T* iterator_position, int n) {
            
        }
        void insert(const T* iterator_begin, int n, const T* iterator_end,) {
            
        }*/
        // O(n)
        void erase() {
            show_vector();
        }
        T& front() {
            T& front_ref = *begin_it;
            return front_ref;
        }
        T& back() {
            T& back_ref = *end_it;
            return back_ref;
        }
        T* data() {
            return arr;
        }
        T* begin() {
            return begin_it;
        }
        T* end() {
            return end_it;
        }
        void size() {
            int i;
            for (i = 0; i < arr_size;) {
                i++;
            }
            std::cout << "vector size: " << i << "." << std::endl;
        }
        void reserve(const int reserved_ram) {
            arr_capacity = reserved_ram;
            capacity();
        }
        void capacity() {
            std::cout << "vector capacity size: " << arr_capacity << "." << std::endl;
        }
    };
}

int main()
{
    my_std::MyVector<int> my_vector;
    std::cout << "Welcome to MyStdVector! There is a vector<int>: ";
    my_vector.create_some_arr();
    std::cout << "" << std::endl;
    std::cout << "my_std::size()" << std::endl;
    my_vector.size();
    std::cout << "" << std::endl;
    std::cout << "my_std::capacity()" << std::endl;
    my_vector.capacity();
    std::cout << "" << std::endl;
    std::cout << "my_std::resize()" << std::endl;
    my_vector.resize(3);
    std::cout << "" << std::endl;
    std::cout << "my_std::push_back()" << std::endl;
    my_vector.push_back(10);
    std::cout << "" << std::endl;
    std::cout << "my_std::pop_back()" << std::endl;
    my_vector.pop_back();
    my_vector.show_vector();
    std::cout << "" << std::endl;
    std::cout << "my_std::reserve()" << std::endl;
    my_vector.reserve(50);
    std::cout << "" << std::endl;
    std::cout << "my_std::front()" << std::endl;
    int& front_element = my_vector.front();
    std::cout << front_element << std::endl;
    std::cout << "" << std::endl;
    std::cout << "my_std::back()" << std::endl;
    int& back_element = my_vector.back();
    std::cout << back_element << std::endl;
    std::cout << "" << std::endl;
    std::cout << "my_std::data()" << std::endl;
    int* data_element = my_vector.data();
    std::cout << data_element << std::endl;
    std::cout << "" << std::endl;
    /*std::cout << "my_std::insert() - some value in some position" << std::endl;
    my_vector.insert(my_vector.begin(), 15);*/
    /*std::cout << "my_std::insert() - some values in some position" << std::endl;
    my_vector.insert(my_vector.begin(), 15, 20, 25);
    std::cout << "my_std::insert() - some values in range" << std::endl;
    my_vector.insert(my_vector2, my_vector3.begin(), my_vector3.end());*/

    // rule of five
    /*my_std::MyVector<int> my_vector2;
    my_vector = my_vector;
    my_vector = my_vector2;
    my_std::MyVector<int> my_vector3(my_vector);*/

    return 0;
}


//                                   draft 
// ----------------------------------------------------------------------------------

