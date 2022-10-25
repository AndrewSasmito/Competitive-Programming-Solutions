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
    ListNode* deleteMiddle(ListNode* head) {
        vector <int> v;
        v.push_back(0);
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        int cnt = 0, cur = 0;
        while (head != NULL){
            ++cnt;
            v.push_back(head -> val);
            head = head -> next;
        }
        cnt /= 2;
        ++cnt;

        for (int i = 1; i<v.size(); ++i){
            if (cnt == i){
                continue;
            }
            temp -> next = new ListNode(v[i]);
            temp = temp -> next;
        }

        return ans -> next;
    }
};
