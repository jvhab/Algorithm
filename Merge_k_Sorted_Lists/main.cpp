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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v1;
        for (size_t i = 0; i < lists.size(); ++i) {
            ListNode* temp;
            temp = lists[i];
            while (temp) {
                v1.push_back(temp->val);
                temp = temp->next;
            }
        }
        if (v1.size() == 0)
            return nullptr;


        sort(v1.begin(), v1.end());
        int i{ 0 };
        ListNode* res;
        ListNode* temps = new ListNode;
        res = temps;
        while (i < v1.size()) {
            temps->val = v1[i];
            if (i < v1.size() - 1) {
                temps->next = new ListNode;
                temps = temps->next;
            }
            i++;
        }

        return res;
    }
};