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
    bool isPalindrome(string s, int start, int end) {      
        
        while (1) {
            if (s[start] != s[end]) {
                return false;
            }
            
            start++;
            end--;
            
            if (start >= end) {
                return true;
            }
        }
        return true;
    }
    
    
    string longestPalindrome(string s) {        
        if (s.size() <= 1) {
            return s;
        }
       
        int start = 0;
        string current_string = s.substr(start, 1);
        int current_length = 1;

        while (start < s.size()) {
            int end = s.size() - 1;
            
            while (end > start) {
                int length = end - start + 1;
                
                if (length <= current_length) {
                    break;
                }
                
                if (s[start] == s[end]) {
                    if (isPalindrome(s, start, end)) {
                        
                        if (length > current_length) {
                            current_string = s.substr(start, length);
                            //cout << current_string << endl;
                            current_length = length;
                        }
                        break;
                    }
                }
                end--;
            }
            start++; 
        }
        return current_string; 
    }
};
