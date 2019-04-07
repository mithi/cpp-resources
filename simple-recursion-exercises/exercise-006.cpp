/*

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/
// 0 1 1 2 3 5 8 13 21
class Solution {
public:
    int rfib(int N, int x, int y) {
        if (N == 1) { return y; }
        return rfib(N - 1, y, x + y);
    }
    int fib(int N) {
        if (N == 0 || N == 1)  { return N; }
        return rfib(N, 0, 1);
    }
};
