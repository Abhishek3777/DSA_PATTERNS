// using space O(2N) + O(N) time
// prefix and suffix product arrays
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            // step 1 prefix product array
            vector<int> prefix;
            prefix.push_back(nums[0]);
            for (int i = 1; i < n; i++) {
                int prod = nums[i] * prefix[i - 1];
                prefix.push_back(prod);
            }
            /// step 2 suffix product array
            vector<int> suffix(n, 0);
            suffix[n - 1] = nums[n - 1];
    
            for (int i = n - 2; i >= 0; i--) {
                int prod = nums[i] * suffix[i + 1];
                suffix[i] = prod;
            }
            vector<int> ans;
            for (int i = 0; i < n; i++) {
                int prod = 1;
                if (i + 1 < n)
                    prod *= suffix[i + 1];
                if (i - 1 >= 0)
                    prod *= prefix[i - 1];
                ans.push_back(prod);
            }
            return ans;
        }
    };
    // space optimsied using ans vector to store left product and thru left and nums creating right product
    class Solution {
        public:
            vector<int> productExceptSelf(vector<int>& nums) {
                int n = nums.size();
                vector<int> left(n);
                left[0] = 1;
        
                // step 1 left product
                for (int i = 1; i < n; i++) {
                    left[i] = left[i - 1] * nums[i - 1];
                }
                int rightProduct = 1;
                for (int i = n - 1; i >= 0; i--) {
                    left[i] = rightProduct * left[i]; // right proudct * left product
                    rightProduct *= nums[i];
                }
                return left;
            }
        };