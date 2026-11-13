
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;

        deque<pair<int, int>> dq;
        int right = n - 1;

        for (int left = n - 1; left >= 0; left--) {
            int cnt = 1;

            while (!dq.empty() && dq.back().first < nums[left]) {
                auto [val, freq] = dq.back();
                dq.pop_back();

                cost += 1LL * (nums[left] - val) * freq;
                cnt += freq;
            }

            dq.push_back({nums[left], cnt});

            while (cost > k) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost -= val - nums[right];
                right--;

                if (freq > 1) {
                    dq.push_front({val, freq - 1});
                }
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
