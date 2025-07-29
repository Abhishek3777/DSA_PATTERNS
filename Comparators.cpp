#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

int main()
{
     vector<int> arr = {4, 1, 5, 2, 3};

     // Sort in descending order using lambda
     sort(arr.begin(), arr.end(), [](int a, int b)
          { return a > b; });

     // sort in ascending order
     sort(arr.begin(), arr.end(), [](int a, int b)
          { return a < b; });

     // Print the sorted array
     // for (int x : arr)
     // {
     //     cout << x << " ";
     // }
     // sort strings by length
     vector<string> words = {"ab", "afafae", "adaedadadad"};

     sort(words.begin(), words.end(), [](string &a, string &b)
          { return a.length() > b.length(); });

     // for (string s : words)
     // {
     //     cout << s << " ";
     // }
     // largest number
     
     vector<int> nums = {3, 30, 34, 5, 9};

     sort(nums.begin(), nums.end(), [](int &a, int &b)
          {
          string s1 = to_string(a);
          string s2 = to_string(b);
          return s1 + s2 > s2 + s1; });

     for (int num : nums)
     {
          cout << num << " ";
     }

     return 0;
}
