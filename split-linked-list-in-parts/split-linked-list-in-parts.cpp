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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k, NULL);
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;
        int n = len / k;
        int r = len % k; 
        // n : minimum guaranteed part size; 
        // r : extra nodes spread to the first r parts;
        
        ListNode* node = root;
        ListNode* prev = NULL;
        for (int i = 0; node && i < k; i++, r--) {
            ans[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = NULL;
        }
        return ans;
    }
};