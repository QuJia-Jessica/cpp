## Excercise 6.1

Parameters: Local variable declared inside the function parameter list. they are initialized by the arguments provided in the each function call.

Arguments: Values supplied in a function call that are used to initialize the function's parameters.

## Exercise 6.2
```cpp
a) int f() {
      string s;
      // ...
      return s;
} // Error: return type must be the same as the function declaration type, as in int.

b) f2(int i) { /* ... */ }  // okay

c) int calc(int v1, int v1) { /* ... */ } // Error: the v1 has been seclared so cannot be declared again.

d) double squre(double x) return x * x; // okay.
```

## Exercise 6.3
Write and test my version of fact
```cpp
int fact(int val){
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}
int main(){
    std::cout << (120 == fact(5)) << std::endl;
    return 0;
}
```

## Exercise 6.4
A user interative function ask for a number and generate the factorial of that number.
```cpp
int fact(int val){
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}
int main(){
    int val;
    std::cout << "PLease enter a number: " << std::endl;
    while (std::cin >> val)
        std::cout << "The factorial of that number is: " << fact(val) << std::endl;
    
    return 0;
}
```
Here is the code from others:
```cpp
#include <iostream>
#include <string>

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    std::string const prompt = "Enter a number within [1, 13) :\n";
    std::string const out_of_range = "Out of range, please try again.\n";
    for (int i; std::cout << prompt, std::cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            std::cout << out_of_range; 
            continue;
        }
        std::cout << fact(i) << std::endl;
    }
}

int main()
{
    interactive_fact();
    return 0;
}
```

## Exercise 6.5
Write a function to return the absolute value of its argument.
```cpp
#include<iostream>

int ab_val(int val){ return abs(val);} // or we can expand the default abs function as: return i > 0 ? i : -i;

int main(){
    std::cout << ab_val(-5) << std::endl;
    return 0;
}
```

## Exercise 6.6
A local variable: Variables defined inside a block; when we need the refreshed value everytime the function is been called.
Parameter: Local variables declared inside the function parameter list
A local static variable: Is initialized before the first time execution passes through the object's definition. when we need the value for the variable to be carried on until the program terminates.

## Exercise 6.7
```cpp
#include<iostream>

size_t count_calls(){
    static size_t ctr = 0; // value will persist across calls
    return ++ctr;
}

int main(){
    for (size_t i = 0; i != 10; ++i)
        std::cout << count_calls() << std::endl;
    return 0;
}```
// What's the difference between ++ctr and ctr++ in this program??
```cpp
size_t generate()
{
    static size_t ctr = 0;
    return ctr++;
}
```
## [Exercise 6.8](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.8_Chapter6.h)

## Exercise 6.9 
Wrtie fact.cc & factMain.cc file together with the use of Chapter6.h;
Still need to work on this task.

## [Exercise 6.10](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.10.cpp)
Swap the values of two ints using pointers.

## Exercuse 6.11
```cpp
void reset(int &i)
{
    i = 0;
}

int main()
{
    int i = 42;
    reset(i);
    std::cout << i  << std::endl;
    return 0;
}
```
## [Exercise 6.12](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.12.cpp)

## Exercise 6.13
Difference between function using void f(T) and void f(T&): where T is a name of a type
void f(T) pass the argument by value. nothing the function does to the parameter can affect the argument. 
void f(T&) pass a reference, will be bound to whatever T object we pass.

## Exercise 6.14
a parameter should be a reference type:
```cpp
void reset(int &i)
{
        i = 0;
}
```

a parameter should not be a reference:
```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

## Exercise 6.15
 Explain the rationale for the type of each of find_char’s
parameters In particular, why is s a reference to const but occurs is a
plain reference? Why are these parameters references, but the char
parameter c is not? What would happen if we made s a plain reference?
What if we made occurs a reference to const?
```cpp
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
      auto ret = s.size(); // position of the first occurrence, if any
      occurs = 0; // set the occurrence count parameter
      for (decltype(ret) i = 0; i != s.size(); ++i) {
            if (s[i] == c) {
                  if (ret == s.size())
                        ret = i; // remember the first occurrence of c
                  ++occurs; // increment the occurrence count
            }
      }
      return ret; // count is returned implicitly in occurs
}
```
```why is s a reference to const but occurs is a plain reference?```

Because s should not be changed by this function, but occurs result must be calculated by the function.

```Why are these parameters references, but the char parameter c is not?```

Because c may be a temp varable, such as find_char(s, 'a', occurs)

```What would happen if we made s a plain reference? What if we made occurs a reference to const?```

s could be changed in the function, and occurs would not be changed. so occurs = 0; is an error.

```cpp
int i = 0;
const int ci = i;
string::size_type ctr = 0;
reset(&i); // calls the version of reset that has an int* parameter
reset(&ci); // error: can't initialize an int* from a pointer to a const int object
reset(i); // calls the version of reset that has an int& parameter
reset(ci); // error: can't bind a plain reference to the const object ci
reset(42); // error: can't bind a plain reference to a literal
reset(ctr); // error: types don't match; ctr has an unsigned type
// ok: find_char's first parameter is a reference to const
find_char("Hello World!", 'o', ctr);
```
## Exercise 6.16
original function:
```cpp
bool is_empty(string& s){ return s.empty(); }
```
modified function:
```cpp
bool is_empty(const string& s){ return s.empty(); } //Since this function doesn't change the argument, "const" shoud be added before string&s, otherwise this function is misleading and can't be used with const string or in a const function.
```
## [Exercise 6.17](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.17.cpp)
The parameters used in the two functions are not the same type. First one is const string&, second one is string&. Since we wish to change the value of the element in the second function so we expect the & is enable to change the value. For the first one, we only need to track the string but no need to change the values of the elements. Hence a const string& is used.


## Exercise 6.18
a) 
```cpp
bool compare(const matrix& m1, const matrix& m2){/*...*/}  // no need const here?
```
b)
```cpp
vector<int>::iterator change_val(int, vector<int>::iterator){/*...*/}
```

## Exercise 6.19
```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```
(a) calc(23.4, 55.1); // illegal, take in too much parameters.
(b) count("abcda", 'a'); //legal
(c) calc(66); // legal, but the 66 will be converted to double type 66.0.
(d) sum(vec.begin(), vec.end(), 3.8); //legal, but the value 3.8 will be converted to int 3.

## Exercise 6.20
When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?
When the value of the reference parameters should not be changed, we set the reference to const. If we make a parameter a plain reference when it could be a reference to const, the value of the reference maybe changed which we don't want to.

## Array Parameters
These declarations are equivalent: Each declares a function with a single parameter of type const int*.
```cpp
void print(const int*);
void print(const int[]); // shows the intent that the function takes an array
void print(const int[10]); // dimension for doumentation purposes(at best)
```
If we pass an array to print, that argument is automatically converted to a pointer to the first element in the array; the size of the array is irrelevant.
```cpp
int i = 0, j[2] = {0, 1};
pring(&i); //ok: &i is int*
print(j); // ok: j in converted to an int* that points to j[0]
```
### Array Reference Parameters
```cpp
void print(int (&arr)[10]){ // () here shows that arr is a reference to an array of ten ints
for (auto elem : arr) cout << elem << endl;

int i = 0, j[2] = {0, 1};
print(&i); print(j); // error: both arguments are not arrays of ten ints
int k[10] = {0,1,2,3,4,5,6,7,8,9}; 
print(k); // ok: argument is an array of ten ints
```
## [Exercise 6.21](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.21.cpp)
A function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. 

## [Exercise 6.22](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.22.cpp)

## [Exercise 6.23](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.23.cpp)
Write own version of each print function in this section.

## Exercise 6.24
Explain the behavior of the following function. Fix the problems if they exist.
```cpp
void print(const int ia[10]) // This code wants to print the array of ten ints.
{
      for (size_t i = 0; i != 10; ++i)
            cout << ia[i] << endl;
}
```

Arrays have two special properties that affect how we define and use functions that operate on arrays: We cannot copy an array, and when we use an array it is (usually) converted to a pointer.

So we cannot pass an array by value, and when we pass an array to a function, we are actually passing a pointer to the array's first element.
Here const int ia[10] basicly pass the value as int* where the size of the array does not matter.
So if we want to pass an array of ten ints, we should modify the declaration part like this:
```cpp
void print10(const int (&ia)[10]) { /*...*/ }
```
## [Exercise 6.27](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.27.cpp)

## Exercise 6.28 
for (const auto &elem : il)  //here the type of &elem is const std::string&

## Exercise 6.29
When you use an initializer_list in a range for would you ever use a reference as the loop control variable?
Depends on the type of elements of initializer_list. When the type is PODType, reference is unnecessary. Because POD is cheap to copy(such as int). Otherwise, Using reference(const) is the better choice. ///Don't quite understand here.

## Exercise 6.30
Error (Clang):
Non-void function 'str_subrange' should return a value. // error #1
Control may reach end of non-void function. // error #2

## Exercise 6.31
when you can find the preexisting object that the reference refered.

## Exercise 6.32
legal, it gave the values (0 ~ 9) to array ia.

## [Exercise 6.33](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.33.cpp)
Write a recursive function, to print the contents of a vector.

## Exercise 6.34
What would happen if the stopping condition in factorial were "if (val != 0)"
- case 1 : If the argument is positive, recursion stops at 0.(Note : There is one extra multiplication step though as the combined expression for factorial(5) reads 5 * 4 * 3 * 2 * 1 * 1. In terms of programming languages learning, such subtle difference probably looks quite trivial. In algorithms analysis and proof, however, this extra step may be super important.)
- case 2 : if the argument is negative, recursion would never stop. As a result, a stack overflow would occur.

## Exercise 6.35
pass val - 1 instead of val --
the recursive function will always use val as the parameter. a recursion loop would happen.

## Exercise 6.36
// Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.
```cpp
string (&func(string (&arrStr)[10]))[10]
```
## Exercise 6.37
```cpp
using ArrT = string[10];
ArrT& func1(ArrT& arr);

auto func2(ArrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT& arr);
```
## Exercise 6.38
```cpp
decltype(arrStr)& arrPtr(int i)
{
          return (i % 2) ? odd : even;
}
```
## Exercise 6.39
(a) legal, repeated declarations(without definition) are legal in C++
(b) illegal, only the return type is different
(c) legal, the parameter type is different and return type is changed

## Exercise 6.40
(a) no error
(b) Missing default argument on parameter 'wd', 'bckgrnd'.

## Exercise 6.41
(a) illegal. No matching function for call to 'init'.
(b) legal, and match.
(c) legal, but not match. wd whould be setting to '*'.


## [Exercise 6.42](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.42.cpp)

## Exercise 6.43
Both two should put in a header. (a) is an inline function. (b) is the declaration of useful function. we always put them in the header.

## Exercise 6.44
```cpp
#include <iostream>
#include <string>
using std::string; using std::cout; using std::endl;

inline bool is_shorter(const string &lft, const string &rht) // defining in the header is better.
{
    return lft.size() < rht.size();
}

int main()
{
    cout << is_shorter("pezy", "mooophy") << endl;
    return 0;
}
```

## Exercise 6.45
For example, the function arrPtr in [Exercise 6.38](# Exercise-638) and make_plural in [Exercise 6.42](# Exercise-642) should be defined as inline. But the function func in [Exercise 6.4](# Exercise-64) shouldn't. It is not that small and it's only being called once. Hence, it will probably not expand as inline.

## Exercise 6.46

Would it be possible to define isShorter as a constexpr? If so, do so. If not, explain why not.

No.

Because std::string::size() is not a constexpr function and s1.size() == s2.size() is not a constant expression.

For a non-template, non-defaulted constexpr function or a non-template, non-defaulted, non-inheriting constexpr constructor, if no argument values exist such that an invocation of the function or constructor could be an evaluated subexpression of a core constant expression (5.19), the program is ill-formed; no diagnostic required. (N3690 §7.1.5 [dcl.constexpr]/5)

## [Exercise 6.47](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.47.cpp)

## Exercise 6.48
This loop let user input a word all the way until the word is sought.

It isn't a good use of assert. because if user begin to input a word, the cin would be always have content. so the assert would be always true. It is meaningless. using assert(s == sought) is better.

## Exercise 6.49
candidate function: Set of functions that are considered when resolving a function call. (all the functions with the name used in the call for which a declaration is in scope at the time of the call.)
viable function: Subset of the candidate functions that could match a given call. It have the same number of parameters as arguments to the call, and each argument type can be converted to the corresponding parameter type.

## Exercise 6.50
(a) illegal. 2.56 match the double, but 42 match the int.
(b) match void f(int).
(c) match void f(int, int).
(d) match void f(double, double = 3.14).

## [Exercise 6.51](https://github.com/QuJia-Jessica/cpp/edit/QuJia-Jessica-patch-1/Exe_6.51.cpp)
