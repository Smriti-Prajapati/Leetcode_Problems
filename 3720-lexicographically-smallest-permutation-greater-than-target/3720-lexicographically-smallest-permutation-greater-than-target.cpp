class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < n; i++) {
            int cur = target[i] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string candidate = target.substr(0, i);
                    candidate += char('a' + c);

                    cnt[c]--;

                    for (int j = 0; j < 26; j++)
                        candidate.append(cnt[j], char('a' + j));

                    cnt[c]++;

                    if (ans.empty() || candidate < ans)
                        ans = candidate;
                }
            }

            if (cnt[cur] == 0)
                break;

            cnt[cur]--;
        }

        return ans;
    }
};