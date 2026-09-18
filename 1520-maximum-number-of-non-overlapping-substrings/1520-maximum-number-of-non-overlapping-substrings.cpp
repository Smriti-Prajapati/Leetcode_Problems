class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, s.size());
        vector<int> last(26, -1);

        // 1. Find first and last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            first[ch] = min(first[ch], i);
            last[ch] = i;
        }

        vector<pair<int, int>> intervals;

        // 2. Try to create a valid interval starting from
        //    the first occurrence of every character
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];
            bool valid = true;

            for (int i = left; i <= right; i++) {
                int ch = s[i] - 'a';

                // This character appeared before our left boundary.
                if (first[ch] < left) {
                    valid = false;
                    break;
                }

                // We must include all occurrences of this character.
                right = max(right, last[ch]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // 3. Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // 4. Greedily select non-overlapping intervals
        vector<string> answer;
        int previousEnd = -1;

        for (auto [left, right] : intervals) {
            if (left > previousEnd) {
                answer.push_back(s.substr(left, right - left + 1));
                previousEnd = right;
            }
        }

        return answer;
    }
};