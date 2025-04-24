class Solution {
    private:
        int findMax(const vector<int>& piles) {
            int maxi = INT_MIN;
            for (int pile : piles) {
                maxi = max(maxi, pile);
            }
            return maxi;
        }
        
        long calcTime(const vector<int>& piles, int k) {
            long totalTime = 0;
            for (int pile : piles) {
                totalTime += (pile + k - 1) / k;  // Integer ceiling without floating-point arithmetic
            }
            return totalTime;
        }
    
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int maxi = findMax(piles);
            int start = 1;
            int end = maxi;
            int ans = maxi;
            
            while (start <= end) {
                int mid = start + (end - start) / 2;
                
                long reqTime = calcTime(piles, mid);  // Use long to avoid overflow
                
                if (reqTime <= h) {
                    ans = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            
            return ans;
        }
    };