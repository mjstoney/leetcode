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

Plan: 
create new list l3
traverse both lists
    if (l1 < l2) l3 = l1
        l1 -> next
        l3->next (new node)

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
    ListNode *l3 = new ListNode();
    ListNode *curr1 = l1;
    ListNode *curr2 = l2;
    ListNode *curr3 = l3;
    if (curr1 == nullptr) return curr2;
    if (curr2 == nullptr) return curr1;

    if(curr1->val <= curr2->val) {
        l3->val = curr1->val;
        curr1 = curr1->next;
    } else {
        l3->val = curr2->val;
        curr2 = curr2->next;
    }
    while(curr1 && curr2) {
        if (curr1->val <= curr2->val) {
            curr3->next = new ListNode(curr1->val);
            curr3 = curr3->next;
            curr1 = curr1->next;
        } else {
            curr3->next = new ListNode(curr2->val);
            curr3 = curr3->next;
            curr2 = curr2->next;
        }
    }
    if(curr1) {
        curr3->next = curr1;
    }
    if(curr2) {
        curr3->next = curr2;
    }
    return l3;
}

int main() {
    ListNode *temp3, *temp2, *l1, *l2, *result;
    temp3 = new ListNode(4);
    temp2 = new ListNode(2, temp3);
    l1 = new ListNode(1, temp2);

    temp3 = new ListNode(4);
    temp2 = new ListNode(3, temp3);
    l2 = new ListNode(1, temp2);
    /*
    while(l1 && l2) {
        std::cout << l1->val << "\t" << l2->val << std::endl;
        l1 = l1->next; l2=l2->next;
    }
*/
    result = mergeTwoLists(l1, l2);
    while(result) {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}