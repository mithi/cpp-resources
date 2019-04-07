// reverse a string

class Solution {
public:

    void reverse(vector<char>&s, int i, int j){

        if (i > j) { return; }

        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;

        reverse(s, i, j);
    }
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }
};
