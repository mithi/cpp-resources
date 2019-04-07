# Simple Recursion

> Recursion is an approach to solving problems using a function that calls itself as a subroutine.

> The trick is that each time a recursive function calls itself, it reduces the given problem into subproblems. The recursion call continues until it reaches a point where the subproblem can be solved without further recursion.

> A recursive function should have the following properties so that it does not result in an infinite loop:

    A simple base case (or cases) — a terminating scenario that does not use recursion to produce an answer.
    A set of rules, also known as recurrence relation that reduces all other cases towards the base case.

> Note that there could be multiple places where the function may call itself.

- `recurrence relation`: the relationship between the result of a problem and the result of its subproblems.

- `base case`: the case where one can compute the answer directly without any further recursion calls

> Pascal's triangle are a series of numbers arranged in the shape of triangle. In Pascal's triangle, the leftmost and the rightmost numbers of each row are always 1. For the rest, each number is the sum of the two numbers directly above it in the previous row.

> Memoization is an optimization technique used primarily to speed up computer programs by storing the results of expensive function calls and returning the cached result when the same inputs occur again.
