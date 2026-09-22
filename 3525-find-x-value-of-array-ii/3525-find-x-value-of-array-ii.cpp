class Solution {
public:

    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    Node mergeNode(const Node& a, const Node& b) {

        Node res;

        // Product of complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.pref[r] = a.pref[r];
        }

        // Prefixes containing all of left
        // and some prefix of right
        for (int r = 0; r < k; r++) {

            int newRem = (a.prod * r) % k;

            res.pref[newRem] += b.pref[r];
        }

        return res;
    }

    void build(int node, int l, int r,
               vector<int>& nums) {

        if (l == r) {

            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].pref[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = mergeNode(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r,
                int idx, int value) {

        if (l == r) {

            int rem = value % k;

            tree[node].prod = rem;

            for (int i = 0; i < 5; i++)
                tree[node].pref[i] = 0;

            tree[node].pref[rem] = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid) {

            update(
                node * 2,
                l,
                mid,
                idx,
                value
            );

        } else {

            update(
                node * 2 + 1,
                mid + 1,
                r,
                idx,
                value
            );
        }

        tree[node] = mergeNode(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void query(int node, int l, int r,
               int ql, int qr,
               Node& result,
               bool& initialized) {

        // Completely outside
        if (r < ql || l > qr)
            return;

        // Completely inside
        if (ql <= l && r <= qr) {

            if (!initialized) {

                result = tree[node];
                initialized = true;

            } else {

                result = mergeNode(
                    result,
                    tree[node]
                );
            }

            return;
        }

        int mid = l + (r - l) / 2;

        query(
            node * 2,
            l,
            mid,
            ql,
            qr,
            result,
            initialized
        );

        query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr,
            result,
            initialized
        );
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n + 5);

        build(
            1,
            0,
            n - 1,
            nums
        );

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            Node result;
            bool initialized = false;

            // Query [start, n-1]
            query(
                1,
                0,
                n - 1,
                start,
                n - 1,
                result,
                initialized
            );

            ans.push_back(result.pref[x]);
        }

        return ans;
    }
};