class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> map;
            int prefixSum = 0;
            int count = 0;
            for (int num : nums) {
                map[prefixSum]++;
                prefixSum += num;
    
                int remove = prefixSum - k;
                // found
                if (map.find(remove) != map.end()) {
                    count += map[remove];
                }
            }
            return count;
        }
    };