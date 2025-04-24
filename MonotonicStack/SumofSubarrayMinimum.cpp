/*
    🔢 Problem: Sum of Subarray Minimums
    ------------------------------------
    Given an array `arr`, we need to find the sum of minimum values of all subarrays.

    📌 Example:
    Input:  [1, 2, 3]
    Subarrays: [1], [2], [3], [1, 2], [2, 3], [1, 2, 3]
    Minimums:  1 + 2 + 3 +   1   +   2   +     1    = 10
    Output: 10

    -------------------------------------------------
    🔁 Approach 1: Brute Force (Nested Loops)
    -------------------------------------------------
    - For every subarray, keep track of the current minimum and add it to the result.
    - Time Complexity: O(n^2)
    - Space Complexity: O(1)
*/

int sumOfSubarrayMinimumsBruteForce(vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        int mini = arr[i];
        for (int j = i; j < arr.size(); j++) {
            mini = min(mini, arr[j]);
            sum += mini;
        }
    }
    return sum;
}

/*
    -------------------------------------------------
    ✅ Approach 2: Optimal (Using Monotonic Stack)
    -------------------------------------------------
    - Every element can be the minimum in multiple subarrays.
    - If we can find out in how many subarrays it's the minimum, we can multiply its value with that count.
    - This gives its total contribution.

    📌 Key Idea:
    - For each element arr[i], find:
        🔸 Previous Smaller Element (PSE)
        🔸 Next Smaller Element (NSE)
    - Let:
        left = i - PSE[i]        // subarrays ending at i
        right = NSE[i] - i       // subarrays starting at i
    - Total subarrays where arr[i] is the minimum = left * right
    - So, total contribution = arr[i] * left * right

    📌 Edge Case:
    - When handling duplicates, use:
        - `<=` for PSE (so equal elements count as part of left stretch)
        - `<`  for NSE (to prevent overcounting on the right)

    - Time Complexity: O(n)
    - Space Complexity: O(n)
*/

int sumOfSubarrayMinimumsOptimal(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n), nse(n);
    stack<int> st;

    // 🔹 Find PSE (Previous Smaller Element)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear the stack for next use
    while (!st.empty()) st.pop();

    // 🔸 Find NSE (Next Smaller Element)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // 🧮 Calculate Total Sum
    long long sum = 0;
    const int MOD = 1e9 + 7;

    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        long long contrib = (arr[i] * left % MOD) * right % MOD;
        sum = (sum + contrib) % MOD;
    }

    return (int)sum;
}
