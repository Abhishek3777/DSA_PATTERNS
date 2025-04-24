class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            unordered_map<int, int> map; // currSum index
            int maxLen = 0;
            int currSum = 0;
            map[0] = -1;
    
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1)
                    currSum += 1;
                else
                    currSum += -1;
                // if currSum seen previously
                if (map.find(currSum) != map.end()) {
                    int prevIndex = map[currSum];
                    maxLen = max(maxLen, i - prevIndex);
                } else {
                    map[currSum] = i;
                }
            }
            return maxLen;
        }
    };