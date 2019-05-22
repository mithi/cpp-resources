/*

PRELIMINARY

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

*/

class Solution {
public:
    int palindrome_length(string s, int l, int r) {
        while(
            l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1; 
    }    
    
    string longestPalindrome(string s) {        
        if(s.size() <= 1) {
            return s;
        }
        
        int start = 0;
        int l = 1;
        
        for(int i = 0; i < s.size(); i++) {
            int l1 = palindrome_length(s, i, i);
            int l2 = palindrome_length(s, i, i + 1);
            int l_temp = max(l1, l2);
            if(l_temp > l) {
                start = i - (l_temp - 1) / 2;
                l = l_temp;
            }
        }
        return s.substr(start, l);
    }
};
