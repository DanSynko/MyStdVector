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

        void update_pointers() {
            str_end = &str[str_size];
            str_end_capacity = &str[str_capacity];
        }
        void reallocation() {
            str_capacity *= 1.5;
            char* new_str = new char[str_capacity];
            std::move(str, str_end, new_str);
            delete[] str;
            str = new_str;
            update_pointers();
        }
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
            update_pointers();
            show_string();
        }
        ~MyString() {
            delete[] str;
        }
        MyString& operator=(const char* other) {
            size_t other_size = 0;
            for (const char* ptr = other; *ptr != '\0'; ptr++) {
                other_size++;
            }
            other_size++;
            if (other_size >= str_capacity) {
                reallocation();
                str_size = other_size;
            }
            std::move(other, &other[other_size], str);
            update_pointers();
            return *this;
        }
        MyString& operator+=(const MyString& other) {
            return *this;
        }
        MyString& operator+=(const char* other) {
            return *this;
        }
        MyString& operator+(const MyString& other) {
            return *this;
        }
        MyString& operator+(const char* other) {
            if (str_size >= str_capacity) {
                reallocation();
            }
            /*MyString new_str;
            std::move(str, str_end, new_str);
            delete[] this->str;*/
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const MyString& other) {
            os << other.str;
            return os;
        }
        friend std::istream& operator>>(std::istream& is, MyString& other) {
            return is;
        }
        friend bool operator<(const MyString& first, const MyString& second) {
            return ;
        }
        friend bool operator>(const MyString& first, const MyString& second) {
            return ;
        }
        friend bool operator<=(const MyString& first, const MyString& second) {
            return ;
        }
        friend bool operator>=(const MyString& first, const MyString& second) {
            return ;
        }
        friend bool operator==(const MyString& first, const MyString& second) {
            return ;
        }
        friend bool operator!=(const MyString& first, const MyString& second) {
            return ;
        }
        void show_string() const {
            std::cout << str << std::endl;
        }
        
        char* c_str() const {
            return str;
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