#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
        : str {nullptr} {
    if (s==nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
        : str{nullptr} {
    str = new char[strlen(source.str)+ 1];
    strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    :str(source.str) {
        source.str = nullptr;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Make lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[std::strlen(obj.str) +1];
    std::strcpy(buff, obj.str);
    for (size_t i {0}; i < std::strlen(buff); ++i) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

// equal
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return std::strcmp(lhs.str, rhs.str) == 0;
}

// not equal
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return std::strcmp(lhs.str, rhs.str) != 0;
}

// less than
bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return lhs.str < rhs.str;
}

// greater than
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return lhs.str > rhs.str;
}

// concatenate
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) +1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

// concatenate and assign
Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

// repeat s2 n times
Mystring operator*(const Mystring &lhs, int n) {
    Mystring temp;
    for (size_t i{1}; i <= n; ++i) {
        temp = temp + lhs;
    }
    return temp;
}

// repeat and assign
Mystring &operator*=(Mystring &lhs, int n) {
    lhs = lhs * n;
    return lhs;
}

// pre-increment toUpper
Mystring &operator++(Mystring &obj) {
    for (size_t i{0}; i < std::strlen(obj.str); ++i) {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    return obj;
}

// post-increment toUpper
Mystring operator++(Mystring &obj, int) {
    Mystring temp {obj};
    ++obj;
    return temp;
}

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}
