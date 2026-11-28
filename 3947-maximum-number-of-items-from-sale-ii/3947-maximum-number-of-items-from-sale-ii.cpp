class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Find minimum price
        int minPrice = INT_MAX;

        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // Count frequency of each factor
        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Calculate eligible free items for each factor
        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
            cnt[i]--;
        }

        // Sort items by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        // Buy copies that provide free items
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price > 2LL * minPrice) {
                break;
            }

            long long canBuy = min(
                (long long)cnt[factor],
                remaining / price
            );

            ans += 2 * canBuy;
            remaining -= canBuy * price;
        }

        // Spend remaining budget on cheapest item
        ans += remaining / minPrice;

        return (int)ans;
    }
};
