class Solution {
public:
    struct State {
        long long score;
        vector<int> indices;
    };

    State better(State a, State b) {
        if (a.score != b.score)
            return a.score > b.score ? a : b;

        return a.indices < b.indices ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        vector<long long> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(
                starts.begin(),
                starts.end(),
                a[i][1]
            ) - starts.begin();
        }

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                State skip = dp[i + 1][k];

                State take;
                take.score = a[i][2] + dp[nxt[i]][k - 1].score;
                take.indices = dp[nxt[i]][k - 1].indices;
                take.indices.push_back(a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(skip, take);
            }
        }

        return dp[0][4].indices;
    }
};