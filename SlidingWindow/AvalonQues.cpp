#include <iostream>
#include <vector>
using namespace std;

bool check(char c)
{
    if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u')
        return true;
    return false;
}

vector<int> countVowelsInEachSubstringOfSizeK(string s, int k, vector<int> &ans)
{
    int l = 0;
    int r = 0;

    int cnt = 0;
    while (r < s.size())
    {
        if (check(s[r]))
            cnt++;

        while (r - l + 1 >= k)
        {
            if (r - l + 1 == k)
                ans.push_back(cnt);

            if (check(s[l]))
                cnt--;
            l++;
        }

        r++;
    }
    return ans;
}
int candySplitter(int n){

    while(to_string(n).size() != 1){
        int sum = 0;
        while(n > 0){
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        n = sum;

    }
    return n;
}
int main()
{

    // string s = "abcde";
    // int k = 2;
    // vector<int> ans;
    // countVowelsInEachSubstringOfSizeK(s, k, ans);
    // for (int num : ans)
    // {
    //     cout << num << " ";
    // }

    cout << candySplitter(9875);

    return 0;
}