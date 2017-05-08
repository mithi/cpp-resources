# NOTES FROM
[CPP BEST PRACTICES -LEFTICUS](https://lefticus.gitbooks.io/cpp-best-practices/content/03-Style.html)


# STYLE SUGGESTIONS

> Consistency is the most important aspect of style. The second most important aspect is following a style that the average C++ programmer is used to reading. - Lefticus C++ Best Practices

You can consider adopting a style. You don't have to be religious in following a coding style, see the reason they were recommended and use your common sense.

Here are some of my favorites that I learned from this book.

1. **Never Use `using namespace` in a header file**
- The namespace will be pulled into all the files that include the header file.
This pollutes the namespace and may lead to name collisions. Use it
in the implementation file instead.

2. **Prefer {} initialization unless you have a strong reason not to.**
- Here's an example copied from a [stack overflow discussion](http://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives)

```cpp
void fun(double val, int val2) {

  int x2 = val;   // if val==7.9, x2 becomes 7 (bad)
  char c2 = val2; // if val2==1025, c2 becomes 1 (bad)
  int x3 {val};   // error: possible truncation (good)
  char c3 {val2}; // error: possible narrowing (good)
  char c4 {24};   // OK: 24 can be represented exactly as a char (good)
  char c5 {264};  // error (assuming 8-bit chars): 264 cannot be represented as a char (good)
  int x4 {2.0};   // error: no double to int value conversion (good)
}
```

3. **Consider Distinguishing Private Member and Function Parameters**
- Any prefix or postfix can be chosen, but don't name anything starting with _ because there's a risk colliding with names reserved for compiler and standard library.
It saves you some brain cycles are you no longer have to think of a name that conflicts
with some member variable and you no longer have to think about where it came from.

```c++
PrivateSize(int t_width, int t_height) : m_width(t_width), m_height(t_height) {}
```

4. **Use nullptr**
-  Use instead of 0 or NULL to indicate a null pointer
