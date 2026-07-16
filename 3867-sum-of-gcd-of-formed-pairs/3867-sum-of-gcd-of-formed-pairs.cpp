#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            a[i] = gcd(nums[i], mx);
        }

        sort(a.begin(), a.end());

        long long ans = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            ans += gcd(a[l], a[r]);
            l++;
            r--;
        }

        return ans;
    }
};