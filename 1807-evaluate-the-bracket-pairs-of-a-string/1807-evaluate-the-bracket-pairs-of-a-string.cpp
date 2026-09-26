class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        // key -> value
        unordered_map<string, string> mp;

        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";

        int i = 0;

        while (i < s.length()) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
                i++;
            }

            // Bracket pair
            else {
                i++;  // skip '('

                string key = "";

                // Collect characters until ')'
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Now s[i] == ')'
                i++;  // skip ')'

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }
            }
        }

        return ans;
    }
};