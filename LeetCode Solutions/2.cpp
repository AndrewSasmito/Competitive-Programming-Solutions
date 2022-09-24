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
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        
        int carry = 0, cnt = 0;
        
        while (l1 != NULL || l2 != NULL || carry > 0){
            cnt = 0;
            if (l1 != NULL){
                cnt += l1 -> val;
                l1 = l1 -> next;
            }
            
            if (l2 != NULL){
                cnt += l2 -> val;
                l2 = l2 -> next;
            }
            
            cnt += carry;
            carry = cnt / 10;
            
            temp -> next = new ListNode(cnt%10);
            temp = temp -> next;
        }
        return ans -> next;
    }
};
