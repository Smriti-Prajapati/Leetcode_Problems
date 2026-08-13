class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;
        int n = words.size();

        int i = 0;

        while (i < n) {

            
            int j = i;
            int totalLength = 0;

            while (j < n) {

                int wordLength = words[j].length();

            
                int requiredLength = totalLength + wordLength;

                if (j > i)
                    requiredLength += (j - i);

                if (requiredLength > maxWidth)
                    break;

                totalLength += wordLength;
                j++;
            }

        
            int numberOfWords = j - i;

            if (j == n || numberOfWords == 1) {

                string line = words[i];

                for (int k = i + 1; k < j; k++) {
                    line += " ";
                    line += words[k];
                }


                line += string(maxWidth - line.length(), ' ');

                ans.push_back(line);
            }

            else {

                int totalSpaces = maxWidth - totalLength;

                int gaps = numberOfWords - 1;

                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                string line = "";

                for (int k = i; k < j; k++) {

                    line += words[k];


                    if (k < j - 1) {

                        int spaces = spacesPerGap;


                        if (k - i < extraSpaces)
                            spaces++;

                        line += string(spaces, ' ');
                    }
                }

                ans.push_back(line);
            }

           
            i = j;
        }

        return ans;
    }
};