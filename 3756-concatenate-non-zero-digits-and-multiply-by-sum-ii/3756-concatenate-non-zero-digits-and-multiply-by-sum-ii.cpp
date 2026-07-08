class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        vector<int> pos;
        vector<int> digit;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }
        int m = digit.size();
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        vector<long long> prefValue(m + 1, 0);
        vector<int> prefSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefValue[i + 1] = (prefValue[i] * 10 + digit[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digit[i];
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;
            if (left > right) {
                ans.push_back(0);
                continue;
            }
            int len = right - left + 1;
            long long x =
                (prefValue[right + 1] -
                 prefValue[left] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[right + 1] - prefSum[left];

            ans.push_back((x * sum) % MOD);
        }
        return ans;
    }
};