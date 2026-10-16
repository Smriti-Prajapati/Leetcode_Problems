
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sqSum = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        // New square sum = old square sum
        // + 2 * val * old sum + len * val^2
        tree[node].sqSum =
            (tree[node].sqSum
             + 2LL * val * tree[node].sum
             + len * val % MOD * val) % MOD;

        // Update the sum
        tree[node].sum =
            (tree[node].sum + len * val) % MOD;

        // Store lazy update
        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum
             + tree[node * 2 + 1].sum) % MOD;

        tree[node].sqSum =
            (tree[node * 2].sqSum
             + tree[node * 2 + 1].sqSum) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node());

        // Values are at most 10^5
        vector<int> last(100001, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            // Increase distinct counts for subarrays
            // starting after the previous occurrence.
            update(1, 0, n - 1, prev + 1, i, 1);

            last[nums[i]] = i;

            // Sum of squares for subarrays ending at i
            ans = (ans + tree[1].sqSum) % MOD;
        }

        return (int)ans;
    }
};
