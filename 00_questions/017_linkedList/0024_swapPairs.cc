
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head; // If list is empty or has only one node, no swapping needed
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* next = head->next;
        
        while (curr && next) {
            // Swap nodes
            prev->next = next;
            curr->next = next->next;
            next->next = curr;
            
            // Move pointers forward
            prev = curr;
            curr = curr->next;
            if (curr) {
                next = curr->next;
            }
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};