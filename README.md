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
