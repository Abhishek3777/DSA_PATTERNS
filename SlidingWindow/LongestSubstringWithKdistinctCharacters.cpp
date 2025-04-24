class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.size() == 0)
                return 0;
            unordered_set<char> set;
            int l = 0;
            int r = 0;
            int maxLen = 0;
    
            while (r < s.size()) {
                if (set.find(s[r]) == set.end()) {
                    set.insert(s[r]);
                    maxLen = max(maxLen, r - l + 1);
                    r++;
                } else {
                    set.erase(s[l]);
                    l++;
                }
            }
            return maxLen;
        }
    };