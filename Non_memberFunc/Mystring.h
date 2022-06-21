#ifndef CHALLENGE_2_MYSTRING_H
#define CHALLENGE_2_MYSTRING_H
#include <iostream>

class Mystring
{
    // Overloaded operator
    friend Mystring operator-(const Mystring &obj); // make lowercase

    friend bool operator==(const Mystring &lhs, const Mystring &rhs); // equal
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs); // not equal
    friend bool operator<(const Mystring &lhs, const Mystring &rhs); // less than
    friend bool operator>(const Mystring &lhs, const Mystring &rhs); // greater than

    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs); // concatenate
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs); // concatenate and assign

    friend Mystring operator*(const Mystring &lhs, int n); // repeat s2 n times
    friend Mystring &operator*=(Mystring &lhs, int n); // repeat and assign

    friend Mystring &operator++(Mystring &obj); // pre-increment
    friend Mystring operator++(Mystring &obj, int); // post-increment

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
};



#endif //CHALLENGE_2_MYSTRING_H
