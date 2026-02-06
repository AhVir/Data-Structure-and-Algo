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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;

        while(temp != nullptr){
            nums.push_back(temp->val);
            // cout << temp->val << endl;
            temp = temp->next;
        }

        int n = nums.size();
        for(int i=0; i<=n/2; i++){
            if(nums[i] != nums[n-1-i]) return false;
        }


        return true;
    }
};
