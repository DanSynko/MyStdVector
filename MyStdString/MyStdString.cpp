#include <iostream>
#include <stdexcept>
#include <cstring>

namespace my_std {
    class MyString {
    private:
        char* str;
        char* str_end;
        char* str_end_capacity;
        size_t str_size = 0;
        size_t str_capacity;
    public:
        MyString() {
            str_capacity = 32;
            str = new char[str_capacity];
            str_end = &str[str_size];
            str_end_capacity = &str[str_capacity];
            str[0] = '\0';
        }
        MyString(char* other_str) {
            for (char* str_temp = other_str; *str_temp != '\0'; str_temp++) {
                str_size++;
            }
            str_capacity = str_size * 1.5;
            str = new char[str_capacity];
            str_end = &str[str_size];
            str_end_capacity = &str[str_capacity];
            *str_end = '\0';
            show_string();
        }
        ~MyString() {
            delete[] str;
        }
        MyString& operator=(const char* other) {
            size_t other_size = 0;
            for (const char* ptr = other; ptr != '\0'; ptr++) {
                other_size++;
            }
            other_size++;
            if (str) {
                delete[] str;
                str_size = other_size;
                str_capacity = str_size * 1.5;
                str = new char[str_capacity];
                str_end = &str[str_size];
                str_end_capacity = &str[str_capacity];
                *str_end = '\0';
            }
            else {
                char* str_temp = str;
                for (; str_temp != '\0'; str_temp++) {
                    *str_temp = *other;
                }
                *str_end = '\0';
            }
            return *this;
        }
        void show_string() {
            std::cout << str << std::endl;
        }

    };
}

int main()
{
    my_std::MyString str;
    str = "Hello World!";
    str.show_string();

    return 0;
}