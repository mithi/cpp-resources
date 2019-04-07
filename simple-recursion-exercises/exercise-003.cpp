class Solution {
public:
    void gen(vector<vector<int>>& levels, int N){

        int n = levels.size();

        if (n == N) { return;}

        levels.push_back(vector<int>());
        levels[n].resize(n + 1);
        levels[n][0] = 1;
        levels[n][n] = 1;

        for (int i = 1; i <= n - i; i++) {
            int x = levels[n - 1][i - 1] + levels[n - 1][i];
            levels[n][i] = x;
            levels[n][n - i] = x;
        }
        gen(levels, N);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> levels = {};
        gen(levels, numRows);
        return levels;
    }
};
