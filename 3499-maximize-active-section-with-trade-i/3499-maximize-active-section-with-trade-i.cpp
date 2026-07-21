class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;
        string t = "1" + s + "1";
        vector<pair<char, int>> runs;
        int n = t.size();
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }
        int bestGain = 0;
        for (int i = 1; i + 1 < (int)runs.size(); i++) {
            if (runs[i].first == '1') {
                bestGain = max(bestGain,
                               runs[i - 1].second + runs[i + 1].second);
            }
        }
        return ones + bestGain;
    }
};