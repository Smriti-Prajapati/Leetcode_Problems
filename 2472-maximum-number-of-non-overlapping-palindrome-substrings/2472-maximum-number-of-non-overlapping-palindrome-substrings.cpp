class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // isPal[l][r] = true if s[l...r] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Build palindrome DP table
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if (len == 1) {
                    isPal[l][r] = true;
                }
                else if (len == 2) {
                    isPal[l][r] = (s[l] == s[r]);
                }
                else {
                    isPal[l][r] =
                        (s[l] == s[r]) &&
                        isPal[l + 1][r - 1];
                }
            }
        }

        // dp[i] = maximum number of non-overlapping
        // valid palindromes in s[0 ... i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't select a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int l = 0; l < i; l++) {

                int len = i - l;

                if (len >= k && isPal[l][i - 1]) {
                    dp[i] = max(dp[i], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};