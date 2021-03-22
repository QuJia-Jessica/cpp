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
