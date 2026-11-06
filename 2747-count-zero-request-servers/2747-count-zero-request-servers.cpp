class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        int left = 0, right = 0;
        int inactive = n;

        for (auto &q : sortedQueries) {

            int start = q.first - x;
            int end = q.first;

            // Add logs within the right boundary
            while (right < logs.size() && logs[right][1] <= end) {

                int id = logs[right][0];

                if (freq[id] == 0) {
                    inactive--;
                }

                freq[id]++;
                right++;
            }

            // Remove logs outside the left boundary
            while (left < right && logs[left][1] < start) {

                int id = logs[left][0];

                freq[id]--;

                if (freq[id] == 0) {
                    inactive++;
                }

                left++;
            }

            ans[q.second] = inactive;
        }

        return ans;
    }
};