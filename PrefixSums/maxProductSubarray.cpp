Input Array:

3, 2, -1, 4, -6, 3, -2, 6
Goal:
Find the maximum product subarray.

Key Observations:
The answer can come from either the prefix or the suffix.
→ So, we will calculate the maximum product while iterating from left to right (prefix) and from right to left (suffix).

Keep including negative numbers.
→ A negative number might help form a larger product in the future when multiplied with another negative.

Reset product to 1 when 0 is encountered.
→ Multiplying by 0 would reset the entire product chain.
→ So, when we hit 0, reset the running product (prefix or suffix) to 1.

// code ->
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int pre = 1, suff = 1;
            int maxi = INT_MIN;
    
            for (int i = 0; i < nums.size(); i++) {
                if (pre == 0)
                    pre = 1;
                if (suff == 0)
                    suff = 1;
    
                pre *= nums[i];
                suff *= nums[n - i - 1];
                maxi = max(maxi, max(pre, suff));
            }
            return maxi;
        }
    };