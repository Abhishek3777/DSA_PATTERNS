class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            // step 1 -> create map
            unordered_map<int, int> map;
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
    
            for (int num : nums) {
                map[num]++;
            }
            // step 2
            for (auto& it : map) {
                pq.push({it.second, it.first});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
            // step 3 push top k in ans vector
            vector<int> ans;
    
            for (int i = k - 1; i >= 0; i--) {
                auto it = pq.top();
                ans.push_back(it.second);
                pq.pop();
            }
            return ans;
        }
    };