class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);
        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        vector<int> base(26);
        for (int i = 0; i < 26; i++)
            base[i] = cnt[i] / 2;

        auto build = [&](const string& half) {
            string res = half;

            if (n & 1)
                res += char('a' + mid);

            for (int i = m - 1; i >= 0; i--)
                res += half[i];

            return res;
        };

        string ans = "";

        if (m == 0) {
            string cur(1, char('a' + mid));
            return cur > target ? cur : "";
        }

        for (int pivot = m - 1; pivot >= 0; pivot--) {
            vector<int> rem = base;
            bool ok = true;

            for (int i = 0; i < pivot; i++) {
                int c = target[i] - 'a';

                if (rem[c] == 0) {
                    ok = false;
                    break;
                }

                rem[c]--;
            }

            if (!ok)
                continue;

            int need = target[pivot] - 'a';

            for (int c = need + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string half = target.substr(0, pivot);
                half += char('a' + c);
                rem[c]--;

                for (int x = 0; x < 26; x++)
                    half.append(rem[x], char('a' + x));

                string cur = build(half);

                if (cur > target && (ans.empty() || cur < ans))
                    ans = cur;

                rem[c]++;
            }
        }

        vector<int> rem = base;
        string half;
        bool ok = true;

        for (int i = 0; i < m; i++) {
            int c = target[i] - 'a';

            if (rem[c] == 0) {
                ok = false;
                break;
            }

            half += target[i];
            rem[c]--;
        }

        if (ok) {
            string cur = build(half);

            if (cur > target && (ans.empty() || cur < ans))
                ans = cur;
        }

        return ans;
    }
};