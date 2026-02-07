/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* ansList = ans;
        ListNode* ansListHead = ansList;

        int carry = 0;

        while(l1 != nullptr && l2 != nullptr){
            int val1 = l1->val;
            int val2 = l2->val;

            int Total = val1+val2+carry;
            int digit = Total%10;
            carry = Total/10;
            ListNode* temp = new ListNode(digit);
            ansList->next = temp;
            ansList = ansList->next;


            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 != nullptr){
            while(l1 != nullptr){
                int val = l1->val;
                val += carry;

                int digit = val%10;
                carry = val/10;

                ListNode* temp = new ListNode(digit);
                ansList->next = temp;
                ansList = ansList->next;

                l1 = l1->next;
            }
        }
        if(l2 != nullptr){
            while(l2 != nullptr){
                int val = l2->val;
                val += carry;

                int digit = val%10;
                carry = val/10;

                ListNode* temp = new ListNode(digit);
                ansList->next = temp;
                ansList = ansList->next;

                l2 = l2->next;
            }
        }

        if(carry != 0){
            ListNode* temp = new ListNode(carry);
            ansList->next = temp;
        }

        return ansListHead->next;
    }
};
