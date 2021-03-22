# Excercise 6.1

Parameters: Local variable declared inside the function parameter list. they are initialized by the arguments provided in the each function call.

Arguments: Values supplied in a function call that are used to initialize the function's parameters.

# Exercise 6.2

a) int f() {
      string s;
      // ...
      return s;
} // Error: return type must be the same as the function declaration type, as in int.

b) f2(int i) { /* ... */ }  // ok

c) int calc(int v1, int v1) /* ... */ } // Error: firstly, the v1 has been seclared so cannot be declared again. Secondly, this function missed a { at the beginning.

d) double squre(double x) return x * x; // okay.
