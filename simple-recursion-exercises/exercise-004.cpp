// Given a non-negative index k where k ≤ 33,
// return the kth index row of the Pascal's triangle.
// Input: 3
// Output: [1,3,3,1]
//Note that the row index starts from 0.
class Solution {
public:
    vector<int> getRow(int n) {
        if (n == 0) { return {1}; }
        if (n == 1) { return {1, 1}; }

        vector<int> row_above = getRow(n - 1);
        vector<int> row;
        row.resize(n + 1);
        row[0] = 1;
        row[n] = 1;

        for (int i = 1; i <= n - i; i++) {
            int x = row_above[i - 1] + row_above[i];
            row[i] = x;
            row[n - i] = x;
        }
        return row;
    }
};
