/*
Given a string, find the length of the longest substring without repeating characters.

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3.

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) { return 0; }
        
        int start = 0; 
        int running_max = 1;
        int slength = 0;
        
        for (int i = 1; i < s.size(); i++) {       
            for (int j = start; j < i; j++) {
                if (s[j] == s[i]) {
                    start = j + 1;
                    if (running_max < slength) { 
                        running_max = slength;
                    }                    
                    break;
                }
            }
            slength = 1 + i - start;
        }
        return running_max > slength ? running_max : slength; 
    }
};
