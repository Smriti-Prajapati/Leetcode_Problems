class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X')
                 continue;
                if (i == n - 1 && j == n - 1) continue;
                int bestScore = -1;
                int count = 0;
                if (i + 1 < n && score[i + 1][j] != -1) {
                    if (score[i + 1][j] > bestScore) {
                        bestScore = score[i + 1][j];
                        count = ways[i + 1][j];
                    } else if (score[i + 1][j] == bestScore) {
                        count = (count + ways[i + 1][j]) % MOD;
                    }
                }
                if (j + 1 < n && score[i][j + 1] != -1) {
                    if (score[i][j + 1] > bestScore) {
                        bestScore = score[i][j + 1];
                        count = ways[i][j + 1];
                    } else if (score[i][j + 1] == bestScore) {
                        count = (count + ways[i][j + 1]) % MOD;
                    }
                }
                if (i + 1 < n && j + 1 < n && score[i + 1][j + 1] != -1) {
                    if (score[i + 1][j + 1] > bestScore) {
                        bestScore = score[i + 1][j + 1];
                        count = ways[i + 1][j + 1];
                    } else if (score[i + 1][j + 1] == bestScore) {
                        count = (count + ways[i + 1][j + 1]) % MOD;
                    }
                }
                if (bestScore == -1) continue;
                score[i][j] = bestScore;
                if (board[i][j] >= '1' && board[i][j] <= '9')
                    score[i][j] += board[i][j] - '0';

                ways[i][j] = count;
            }
        }
        if (ways[0][0] == 0)
            return {0, 0};
        return {score[0][0], ways[0][0]};
    }
};