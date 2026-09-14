class Solution {
public:

    // Get the maximum subsequence of length k
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<int> st;
        int remove = nums.size() - k;

        for (int num : nums) {

            while (!st.empty() && remove > 0 && st.back() < num) {
                st.pop_back();
                remove--;
            }

            st.push_back(num);
        }

        // If some elements still need to be removed,
        // remove them from the end.
        while (remove > 0) {
            st.pop_back();
            remove--;
        }

        return st;
    }


    // Compare two sequences starting from i and j
    // Returns true if A[i...] is greater than B[j...]
    bool greater(vector<int>& A, int i, vector<int>& B, int j) {

        while (i < A.size() && j < B.size() && A[i] == B[j]) {
            i++;
            j++;
        }

        // If B is finished, A is greater
        if (j == B.size())
            return true;

        // Otherwise compare the first different digit
        if (i < A.size() && A[i] > B[j])
            return true;

        return false;
    }


    // Merge two subsequences to create the largest sequence
    vector<int> merge(vector<int>& A, vector<int>& B) {

        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < A.size() || j < B.size()) {

            if (greater(A, i, B, j)) {
                result.push_back(A[i]);
                i++;
            }
            else {
                result.push_back(B[j]);
                j++;
            }
        }

        return result;
    }


    // Check whether A is greater than B
    bool isGreater(vector<int>& A, vector<int>& B) {

        for (int i = 0; i < A.size(); i++) {

            if (A[i] > B[i])
                return true;

            if (A[i] < B[i])
                return false;
        }

        return false;
    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> answer(k, 0);

        int m = nums1.size();
        int n = nums2.size();

        // Try taking x digits from nums1
        for (int x = 0; x <= k; x++) {

            int y = k - x;

            // Can't take more digits than available
            if (x > m || y > n)
                continue;

            // Best x digits from nums1
            vector<int> A = maxSubsequence(nums1, x);

            // Best y digits from nums2
            vector<int> B = maxSubsequence(nums2, y);

            // Merge them
            vector<int> candidate = merge(A, B);

            // Keep the larger answer
            if (isGreater(candidate, answer)) {
                answer = candidate;
            }
        }

        return answer;
    }
};