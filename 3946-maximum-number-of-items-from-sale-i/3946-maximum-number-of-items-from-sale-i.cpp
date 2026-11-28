
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> benefit(n, 0);

        // Calculate free items provided by each item
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j &&
                    items[j][0] % items[i][0] == 0) {
                    benefit[i]++;
                }
            }
        }

        // Group items according to their price
        vector<vector<int>> groups(1501);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int value = 1 + benefit[i];

            groups[price].push_back(value);
        }

        const int NEG = -1000000000;

        // DP for items having strictly greater price
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        // Process possible minimum prices
        for (int p = 1500; p >= 1; p--) {

            // At least one item with price p must be selected
            vector<int> curr(budget + 1, NEG);

            for (int val : groups[p]) {

                for (int c = budget; c >= p; c--) {

                    if (dp[c - p] != NEG) {
                        curr[c] = max(curr[c],
                                      dp[c - p] + val);
                    }

                    if (curr[c - p] != NEG) {
                        curr[c] = max(curr[c],
                                      curr[c - p] + val);
                    }
                }
            }

            // Spend remaining budget on cheapest selected item
            for (int c = p; c <= budget; c++) {
                if (curr[c] != NEG) {
                    int total = curr[c] + (budget - c) / p;
                    ans = max(ans, total);
                }
            }

            // Add current price group to higher-price DP
            for (int val : groups[p]) {
                for (int c = budget; c >= p; c--) {
                    if (dp[c - p] != NEG) {
                        dp[c] = max(dp[c],
                                    dp[c - p] + val);
                    }
                }
            }
        }

        return ans;
    }
};
