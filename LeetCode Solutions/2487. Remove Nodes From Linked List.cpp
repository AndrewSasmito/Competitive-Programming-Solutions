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

//So much trouble trying to fix my linked list
class Solution {
public:
    vector <int> ans, temp;
    void dfs (ListNode* x){
        if (x == NULL){
            return;
        }
        temp.push_back(x -> val);
        dfs(x -> next);
    }
    ListNode* removeNodes(ListNode* head){
        ListNode* ret = new ListNode();
        ListNode* tmp = ret;
        dfs(head);
        ans.push_back(temp.back());
        for (int i = temp.size() - 2; i>=0; --i){
            if (ans.back() <= temp[i]){
                ans.push_back(temp[i]);
            }
        }
        
        for (int i = ans.size() - 1; i>=0; --i){
            tmp -> next = new ListNode(ans[i]);
            tmp = tmp -> next;
        }
        return ret -> next;
    }
};
