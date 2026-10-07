class Solution {
public:
    vector<string> ans;
    unordered_set<string> seen;
    string path;

    void dfs(string &s, int index, int left, int right,
             int removeLeft, int removeRight) {

        // End of string
        if (index == s.size()) {
            if (removeLeft == 0 && removeRight == 0) {
                if (seen.insert(path).second) {
                    ans.push_back(path);
                }
            }
            return;
        }

        char ch = s[index];

        // ---------------- '(' ----------------
        if (ch == '(') {

            // Remove '('
            if (removeLeft > 0) {
                dfs(s, index + 1,
                    left, right,
                    removeLeft - 1, removeRight);
            }

            // Keep '('
            path.push_back('(');

            dfs(s, index + 1,
                left + 1, right,
                removeLeft, removeRight);

            path.pop_back();
        }

        // ---------------- ')' ----------------
        else if (ch == ')') {

            // Remove ')'
            if (removeRight > 0) {
                dfs(s, index + 1,
                    left, right,
                    removeLeft, removeRight - 1);
            }

            // Keep ')' only if it has a matching '('
            if (right < left) {

                path.push_back(')');

                dfs(s, index + 1,
                    left, right + 1,
                    removeLeft, removeRight);

                path.pop_back();
            }
        }

        // ---------------- Letter ----------------
        else {

            path.push_back(ch);

            dfs(s, index + 1,
                left, right,
                removeLeft, removeRight);

            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int removeLeft = 0;
        int removeRight = 0;

        // Find the minimum number of removals required
        for (char ch : s) {

            if (ch == '(') {
                removeLeft++;
            }
            else if (ch == ')') {

                if (removeLeft > 0) {
                    removeLeft--;
                }
                else {
                    removeRight++;
                }
            }
        }

        dfs(s, 0, 0, 0, removeLeft, removeRight);

        return ans;
    }
};