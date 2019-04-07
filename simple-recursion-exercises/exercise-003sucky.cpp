// NOTE: WORST SOLUTION EVER???
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
class Solution {
public:

    void gen(vector<vector<int>>& levels, int max){

        int n = levels.size();

        if (n == max) {
            return;
        }

        levels.push_back(vector<int>());

        if (n == 0) {
            levels[n] = {1};
            gen(levels, max);
        }

        if (n == 1) {
            levels[n] = {1, 1};
            gen(levels, max);
        }


        levels[n].resize(n + 1);

        levels[n][0] = 1;
        levels[n][n] = 1;
        int j = n - 1;
        int i = 1;

        while (true) {
            if (i > j) {break;}
            int x = levels[n-1][i-1] + levels[n-1][i];
            cout << x << ":";
            levels[n][i] = x;
            levels[n][j] = x;
            i++;
            j--;
        }
        cout << endl;

        gen(levels, max);
    }
    void gen2(vector<vector<int>>& levels, int max){

        int n = levels.size();
        if (n == max) { return; }
        levels.push_back(vector<int>());

        int half = n / 2;
        levels[n].push_back(1);

        int i = 0;

        while (i < half) {
            int x = levels[n-1][i] + levels[n-1][i+1];
            levels[n].push_back(x);
            i++;
        }

        i = half;
        if (n % 2 == 0) { i = half - 1; }

        while ( i >= 0) {
            int x = levels[n][i];
            levels[n].push_back(x);
            i--;
        }

        gen2(levels, max);

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> levels = {};
        gen2(levels, numRows);
        return levels;
    }
};
