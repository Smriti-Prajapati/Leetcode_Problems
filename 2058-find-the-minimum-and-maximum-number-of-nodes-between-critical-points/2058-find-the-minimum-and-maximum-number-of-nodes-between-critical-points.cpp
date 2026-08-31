class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        
        int first = -1;
        int last = -1;
        
        int position = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);
            
            if (isCritical) {
                if (first == -1) {
                    first = position;
                } else {
                    minDistance = min(minDistance, position - last);
                }
                
                last = position;
            }
            
            prev = curr;
            curr = next;
            position++;
        }
        
        if (first == -1 || first == last) {
            return {-1, -1};
        }
        
        int maxDistance = last - first;
        
        return {minDistance, maxDistance};
    }
};