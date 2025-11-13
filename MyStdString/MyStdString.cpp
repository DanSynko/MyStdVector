#include <iostream>
#include <stdexcept>
#include <cstring>

namespace my_std {
    class MyString {
    private:
        char* ptr;
        char* ptr_end;
        char* ptr_end_capacity;
    public:
        MyString() {

        }
        ~MyString() {

        }
    };
}

int main()
{
    std::cout << "Hello World!\n" << std::endl;

    return 0;
}