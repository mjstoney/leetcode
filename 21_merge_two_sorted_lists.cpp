/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: l1 = [], l2 = []
Output: []

Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both l1 and l2 are sorted in non-decreasing order.

 */

#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *merged = new ListNode(0);
    ListNode *head = merged;
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            merged->next = l1;
            l1 = l1->next;
        } else {
            merged->next = l2;
            l2 = l2->next;
        }
        merged = merged->next;

        }
    if(l1){
        merged->next = l1;
        l1 = l1->next;
    }
    if(l2) {
        merged->next = l2;
        l2 = l2->next;
    }
    return head->next;
}

int main() {
    ListNode *temp3, *temp2, *l1, *l2, *result;
    temp3 = new ListNode(4);
    temp2 = new ListNode(2, temp3);
    l1 = new ListNode(1, temp2);

    temp3 = new ListNode(4);
    temp2 = new ListNode(3, temp3);
    l2 = new ListNode(1, temp2);
    result = mergeTwoLists(l1, l2);
    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}