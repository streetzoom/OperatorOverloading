//
// Created by STZ on 6/14/22.
//
#ifndef CHALLENGE_MYSTRING_H
#define CHALLENGE_MYSTRING_H
#include <iostream>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor

    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment

    // Overloaded operator
    Mystring operator-() const; // make lowercase

    bool operator==(const Mystring &rhs) const; // equal
    bool operator!=(const Mystring &rhs) const; // not equal
    bool operator<(const Mystring &rhs) const; // less than
    bool operator>(const Mystring &rhs) const; // greater than

    Mystring operator+(const Mystring &rhs) const; // concatenate
    Mystring &operator+=(const Mystring &rhs); // concatenate and assign

    Mystring operator*(int n) const; // repeat s2 n times
    Mystring &operator*=(int n); // repeat and assign

    Mystring &operator++(); // pre-increment
    Mystring operator++(int); // post-increment

};

#endif //CHALLENGE_MYSTRING_H
