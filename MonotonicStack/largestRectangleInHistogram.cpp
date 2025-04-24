class Solution {
    private:
        void nextSmaller(vector<int>& heights, vector<int>& nse) {
            stack<int> st;
            int n = heights.size();
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    nse[i] = st.top();
                }
                st.push(i);
            }
        }
        void previousSmaller(vector<int>& heights, vector<int>& pse) {
            stack<int> st;
            int n = heights.size();
    
            for (int i = 0; i < n; i++) {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (!st.empty()) {
                    pse[i] = st.top();
                }
                st.push(i);
            }
        }
    
    public:
        int largestRectangleArea(vector<int>& heights) {
            // step 1 create nse and pse vector
            int n = heights.size();
            vector<int> nse(n, n);
            nextSmaller(heights, nse);
            vector<int> pse(n, -1);
            previousSmaller(heights, pse);
            int maxArea = 0;
            // step 2 compute max area
            for (int i = 0; i < n; i++) {
                maxArea = max(maxArea, (nse[i] - pse[i] - 1) * heights[i]);
            }
            return maxArea;
        }
    };