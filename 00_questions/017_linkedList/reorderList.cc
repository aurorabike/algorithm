#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        ListNode* dummy = head;

        while(dummy){
            nodes.push_back(dummy);
            dummy = dummy->next;
        }

        int l = 1, r = nodes.size()-1;

        for (int i = 0 ; i < nodes.size(); ++i){
            if (i % 2 == 0){
                head->next = nodes[r--];
            }
            else{
                head->next = nodes[l++];
            }
            head = head->next;
        }

        if (head) {
            head->next = nullptr;
        }
    }
};

// Utility function to create a linked list from a vector of integers
ListNode* createLinkedList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int num : nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy->next;
}

// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1: Basic Case
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createLinkedList(nums1);
    cout << "Original List 1: ";
    printLinkedList(head1);
    solution.reorderList(head1);
    cout << "Reordered List 1: ";
    printLinkedList(head1);
    cout << endl;

    // Test Case 2: Even Number of Nodes
    vector<int> nums2 = {1, 2, 3, 4};
    ListNode* head2 = createLinkedList(nums2);
    cout << "Original List 2: ";
    printLinkedList(head2);
    solution.reorderList(head2);
    cout << "Reordered List 2: ";
    printLinkedList(head2);
    cout << endl;

    // Test Case 3: Odd Number of Nodes
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head3 = createLinkedList(nums3);
    cout << "Original List 3: ";
    printLinkedList(head3);
    solution.reorderList(head3);
    cout << "Reordered List 3: ";
    printLinkedList(head3);
    cout << endl;

    // Test Case 4: Empty List
    ListNode* head4 = nullptr;
    cout << "Original List 4: ";
    printLinkedList(head4);
    solution.reorderList(head4);
    cout << "Reordered List 4: ";
    printLinkedList(head4);
    cout << endl;

    // Test Case 5: Single Node
    vector<int> nums5 = {1};
    ListNode* head5 = createLinkedList(nums5);
    cout << "Original List 5: ";
    printLinkedList(head5);
    solution.reorderList(head5);
    cout << "Reordered List 5: ";
    printLinkedList(head5);
    cout << endl;

    return 0;
}
