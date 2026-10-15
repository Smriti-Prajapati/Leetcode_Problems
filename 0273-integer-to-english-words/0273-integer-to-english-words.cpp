
class Solution {
public:
    string below20[20] = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"
    };

    string tens[10] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string convert(int num) {
        string ans = "";

        if (num >= 100) {
            ans += below20[num / 100] + " Hundred";
            num %= 100;

            if (num > 0)
                ans += " ";
        }

        if (num >= 20) {
            ans += tens[num / 10];
            num %= 10;

            if (num > 0)
                ans += " ";
        }

        if (num > 0 && num < 20) {
            ans += below20[num];
        }

        return ans;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string result = "";
        string units[] = {"", "Thousand", "Million", "Billion"};
        int index = 0;

        while (num > 0) {
            int group = num % 1000;

            if (group > 0) {
                string part = convert(group);

                if (units[index] != "")
                    part += " " + units[index];

                if (result != "")
                    result = part + " " + result;
                else
                    result = part;
            }

            num /= 1000;
            index++;
        }

        return result;
    }
};
