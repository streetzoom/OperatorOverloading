# OperatorOverloading
-----------------------

Overload the following operators in the provided Mystring class.

To gain experience overloading operators, you should do this challenge twice.
First, overload the operators using member functions and then in another project overload the same operators
again using non-member functions.

Please do it once using member methods and then again using non-member functions.

Here is a list of some of the operators that you can overload for this class:


-          - unary minus. Returns the lowercase version of the object's string

           (-s1)

==         - returns true if the two strings are equal

           (s1 == s2)

!=     - returns true if the two strings are not equal 

           (s1 != s2)

<      - returns true if the lhs string is lexically less than the rhs string

           (s1 < s2)

>      - returns true if the lhs string is lexically greater than the rhs string

          (s1 > s2)

+          - concatenation. Returns an object that concatenates the lhs and rhs

           s1 + s2

+=    - concatenate the rhs string to the lhs string and store the result in lhs object

          s1 += s2;      equivalent to s1 = s1 + s2;

* - repeat -  results in a string that is copied n times

          s2 * 3;          ex). s2 = "abc"; 
                                   s1 = s2 * 3;
                                   s1 will result in "abcabcabc"

*=   - repeat the string on the lhs n times and store the result back in the lhs object

            s1 = "abc";

            s1 *= 4;        s1 = s1 will result in "abcabcabcabc"
      
