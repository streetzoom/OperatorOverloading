//
// Created by STZ on 6/14/22.
//
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
Mystring::Mystring( Mystring &&source)
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
Mystring &Mystring::operator=( Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
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


// Make lowercase
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) +1];
    std::strcpy(buff, str);
    for (size_t i {0}; i < std::strlen(buff); ++i) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

// equal
bool Mystring::operator==(const Mystring &rhs) const {
    return std::strcmp(str, rhs.str) == 0;
}

// not equal
bool Mystring::operator!=(const Mystring &rhs) const {
    return std::strcmp(str, rhs.str) != 0;
}

// less than
bool Mystring::operator<(const Mystring &rhs) const {
    return str < rhs.str;
}

// greater than
bool Mystring::operator>(const Mystring &rhs) const {
    return str > rhs.str;
}

// concatenate
Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) +1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

// concatenate and assign
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// repeat s2 n times
Mystring Mystring::operator*(int n) const {
    Mystring temp;
    for (size_t i{1}; i <= n; ++i) {
        temp = temp + *this;
    }
    return temp;
}

// repeat and assign
Mystring &Mystring::operator*=(int n) {
    *this = *this * n;
    return *this;
}

// pre-increment toUpper
Mystring &Mystring::operator++() {
    for (size_t i{0}; i < std::strlen(str); ++i) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// post-increment toUpper
Mystring Mystring::operator++(int) {
    Mystring temp(*this);
    operator++();
    return temp;
}




