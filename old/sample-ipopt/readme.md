
An example of using the Ipopt package to solve a simple example problem for testing purposes.

# Example problem:
```
   1. minimize cost function: x0 * x3 * (x0 + x1 + x2) + x2
 
   2. subject to the following constraints:
      (A) x0 * x1 * x2 * x3 >= 25
      (B) x0^2 + x1^2 + x2^2 + x3^2 = 40
      (C) 1 <= x0, x1, x2, x3 <= 5
```

# Reference
- https://www.coin-or.org/CppAD/Doc/ipopt_solve_get_started.cpp.htm

# How to use
- Clone this repository and go to the directory
- Make and go inside the build directory
```
mkdir build && cd build
```
- Compile the project
```
cc=gcc-6 cmake .. && make
```
- Run the program
```
./IPOPTTEST
```
- If everything runs as it should, you should see the following:
```
Test passed! :)
```

# Dependencies 
- Ipopt 
```
brew install ipopt --with-openblas
```
- CppAD
```
brew install cppad
```
