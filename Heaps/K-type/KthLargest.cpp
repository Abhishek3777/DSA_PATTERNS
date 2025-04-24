class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            // step 1 push all first k elements in minheap
            priority_queue<int, std::vector<int>, std::greater<int>> pq;
            for (int i = 0; i < k; i++) {
                pq.push(nums[i]);
            }
            // step 2 push all remaining elements and if larger than top pop and
            // push, this way larger element stays in it
            for (int i = k; i < nums.size(); i++) {
                if (nums[i] > pq.top()) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            return pq.top();
            // TC - O(N * log(k))
        }
    };