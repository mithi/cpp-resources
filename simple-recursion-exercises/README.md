# Simple Recursion
- When in doubt, write down the recurrence relationship.
- Whenever possible, apply memoization.
- Avoid duplicate computations
- When stack overflows, tail recursion might come to help.

> Recursion is an approach to solving problems using a function that calls itself as a subroutine.

> The trick is that each time a recursive function calls itself, it reduces the given problem into subproblems. The recursion call continues until it reaches a point where the subproblem can be solved without further recursion.

> A recursive function has:

    A simple base case (or cases) — a terminating scenario that does not use recursion to produce an answer.
    A set of rules, also known as recurrence relation that reduces all other cases towards the base case.

> Note that there could be multiple places where the function may call itself.

- `recurrence relation`: the relationship between the result of a problem and the result of its subproblems.

- `base case`: the case where one can compute the answer directly without any further recursion calls, terminating scenario.

> Pascal's triangle are a series of numbers arranged in the shape of triangle. In Pascal's triangle, the leftmost and the rightmost numbers of each row are always 1. For the rest, each number is the sum of the two numbers directly above it in the previous row.

> Memoization is an optimization technique used primarily to speed up computer programs by storing the results of expensive function calls and returning the cached result when the same inputs occur again.

> Tail recursion is a recursion where the recursive call is the final instruction in the recursion function. And there should be only one recursive call in the function.

# Terms
- Backtrracking
- Memoization
- Dynamic programming
- Tail-recursion vs non tail recursion


# TODO:
```
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```


