class Solution {
public:
    using ll = long long;

    struct BIT {
        int n;
        vector<ll> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, ll val) {
            while (i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        ll query(int i) {
            ll s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }

        int kth(ll k) {
            int idx = 0;
            for (int p = 1 << 17; p; p >>= 1) {
                int next = idx + p;
                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }
            return idx + 1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> a = nums;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int m = a.size();

        BIT count(m), sum(m);

        vector<ll> cost(n - x + 1);

        ll total = 0;

        auto add = [&](int val, int diff) {
            int id = lower_bound(a.begin(), a.end(), val) - a.begin() + 1;
            count.update(id, diff);
            sum.update(id, 1LL * val * diff);
            total += 1LL * val * diff;
        };

        for (int i = 0; i < n; i++) {
            add(nums[i], 1);

            if (i >= x) {
                add(nums[i - x], -1);
            }

            if (i >= x - 1) {
                int id = count.kth((x + 1) / 2);
                ll med = a[id - 1];

                ll leftCount = count.query(id);
                ll leftSum = sum.query(id);

                ll rightCount = x - leftCount;
                ll rightSum = total - leftSum;

                cost[i - x + 1] =
                    med * leftCount - leftSum +
                    rightSum - med * rightCount;
            }
        }

        const ll INF = LLONG_MAX / 4;

        vector<vector<ll>> dp(
            n + 1, vector<ll>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};