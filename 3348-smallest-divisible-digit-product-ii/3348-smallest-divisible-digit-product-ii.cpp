#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int get_required_length(int c2, int c3, int c5, int c7) {
        int length = c5 + c7;

        int pairs_of_3 = c3 / 2;
        length += pairs_of_3;
        c3 %= 2;

        int trios_of_2 = c2 / 3;
        length += trios_of_2;
        c2 %= 3;

        if (c3 == 1 && c2 == 2)
            length += 2;
        else if (c3 == 1 && c2 == 1)
            length += 1;
        else if (c3 == 1)
            length += 1;
        else if (c2 > 0)
            length += 1;

        return length;
    }

public:
    string smallestNumber(string num, long long t) {
        int rem2 = 0, rem3 = 0, rem5 = 0, rem7 = 0;

        while (t % 2 == 0) rem2++, t /= 2;
        while (t % 3 == 0) rem3++, t /= 3;
        while (t % 5 == 0) rem5++, t /= 5;
        while (t % 7 == 0) rem7++, t /= 7;

        if (t > 1) return "-1";

        int n = num.size();

        vector<int> req2(n + 1), req3(n + 1), req5(n + 1), req7(n + 1);

        req2[0] = rem2;
        req3[0] = rem3;
        req5[0] = rem5;
        req7[0] = rem7;

        int first_zero = -1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }

            int d = num[i] - '0';
            int c2 = 0, c3 = 0, c5 = 0, c7 = 0;

            while (d % 2 == 0) c2++, d /= 2;
            while (d % 3 == 0) c3++, d /= 3;
            if (d == 5) c5++;
            if (d == 7) c7++;

            req2[i + 1] = max(0, req2[i] - c2);
            req3[i + 1] = max(0, req3[i] - c3);
            req5[i + 1] = max(0, req5[i] - c5);
            req7[i + 1] = max(0, req7[i] - c7);
        }

        if (first_zero == -1 &&
            req2[n] == 0 &&
            req3[n] == 0 &&
            req5[n] == 0 &&
            req7[n] == 0)
            return num;

        int start = (first_zero == -1 ? n - 1 : first_zero);

        for (int i = start; i >= 0; i--) {

            int begin = (num[i] - '0') + 1;
            if (first_zero != -1 && i == first_zero)
                begin = 1;

            for (int d = begin; d <= 9; d++) {

                int c2 = 0, c3 = 0, c5 = 0, c7 = 0;

                int x = d;

                while (x % 2 == 0) c2++, x /= 2;
                while (x % 3 == 0) c3++, x /= 3;
                if (x == 5) c5++;
                if (x == 7) c7++;

                int n2 = max(0, req2[i] - c2);
                int n3 = max(0, req3[i] - c3);
                int n5 = max(0, req5[i] - c5);
                int n7 = max(0, req7[i] - c7);

                int remain = n - i - 1;

                if (get_required_length(n2, n3, n5, n7) <= remain) {

                    string ans = num.substr(0, i);
                    ans.push_back(char('0' + d));

                    string suf;

                    while (n7--) suf += '7';
                    while (n5--) suf += '5';

                    while (n3 >= 2) {
                        suf += '9';
                        n3 -= 2;
                    }

                    while (n2 >= 3) {
                        suf += '8';
                        n2 -= 3;
                    }

                    if (n3 == 1 && n2 == 2) {
                        suf += '6';
                        suf += '2';
                    } else if (n3 == 1 && n2 == 1) {
                        suf += '6';
                    } else if (n3 == 1) {
                        suf += '3';
                    } else if (n2 == 2) {
                        suf += '4';
                    } else if (n2 == 1) {
                        suf += '2';
                    }

                    while ((int)suf.size() < remain)
                        suf += '1';

                    sort(suf.begin(), suf.end());

                    return ans + suf;
                }
            }
        }

        int len = n + 1;

        while (true) {

            if (get_required_length(rem2, rem3, rem5, rem7) <= len) {

                string ans;

                while (rem7--) ans += '7';
                while (rem5--) ans += '5';

                while (rem3 >= 2) {
                    ans += '9';
                    rem3 -= 2;
                }

                while (rem2 >= 3) {
                    ans += '8';
                    rem2 -= 3;
                }

                if (rem3 == 1 && rem2 == 2) {
                    ans += '6';
                    ans += '2';
                } else if (rem3 == 1 && rem2 == 1) {
                    ans += '6';
                } else if (rem3 == 1) {
                    ans += '3';
                } else if (rem2 == 2) {
                    ans += '4';
                } else if (rem2 == 1) {
                    ans += '2';
                }

                while ((int)ans.size() < len)
                    ans += '1';

                sort(ans.begin(), ans.end());

                return ans;
            }

            len++;
        }

        return "-1";
    }
};