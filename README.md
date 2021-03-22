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
