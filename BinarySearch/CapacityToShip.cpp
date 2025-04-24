// 1011. Capacity To Ship Packages Within D Days

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

class Solution {
    private:
        bool possible(vector<int>& weights, int presentWeight, int days) {
            int tempSum = 0;
            int requiredDays = 1;
    
            for (int weight : weights) {
                if (weight > presentWeight) {
                    return false;
                }
                if (tempSum + weight > presentWeight) {
                    requiredDays++;
                    tempSum = weight;
                    if (requiredDays > days) {
                        return false;
                    }
                } else {
                    tempSum += weight;
                }
            }
            return true;
        }
    
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int mini = INT_MIN;
            int totalReqWeight = 0;
            for (int i = 0; i < weights.size(); i++) {
                mini = max(mini, weights[i]);
                totalReqWeight += weights[i];
            }
            int start = mini;
            int end = totalReqWeight;
            int ans = totalReqWeight;
    
            while (start <= end) {
                int mid = start + (end - start) / 2;
    
                if (possible(weights, mid, days)) {
                    ans = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            return ans;
        }
    };  