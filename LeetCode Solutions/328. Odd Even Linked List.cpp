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
    vector <int> odder, evener;
    ListNode* oddEvenList(ListNode* head) {
        int cur = 1;

        while (head != NULL){
            if (cur % 2 == 0){
                evener.push_back(head -> val);
            }else{
                odder.push_back(head -> val);
            }
            cur = 1 - cur;

            head = head -> next;
        }

        ListNode* ret = new ListNode();
        ListNode* tmp = ret;

        for (int x : odder){
            tmp -> next = new ListNode(x);
            tmp = tmp -> next;
        }for (int x : evener){
            tmp -> next = new ListNode(x);
            tmp = tmp -> next;
        }

        return ret -> next;
    }
};
