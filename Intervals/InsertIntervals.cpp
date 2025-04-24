// brute force
// simply push the new interval and then as you did in merge intervals
// i.e sort and merge

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            // Step 1: Insert the new interval
            intervals.push_back(newInterval);
    
            // Step 2: Sort the intervals by starting time
            sort(intervals.begin(), intervals.end());
    
            // Step 3: Merge intervals
            vector<vector<int>> ans;
            for (auto& interval : intervals) {
                if (ans.empty() || interval[0] > ans.back()[1]) {
                    ans.push_back(interval);
                } else {
                    ans.back()[1] = max(ans.back()[1], interval[1]);
                }
            }
            return ans;
        }
    };
    // OPTIMAL  
    // since its already sorted we need not sort it again
    // There will be 3 portion in array
    // [[1,2], [3,4], [5,7], [8,10], [12, 16]] newInterval = [6,8]

    // case 1
    // till 3,4 no overlap so just push 

    // case 2 overlap
    // 


    // case 3 - push remaining elements as its sorted already so we need not do anything again