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

    ListNode* merge2Lists(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(a && b){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* merge(vector<ListNode*>&lists, int left, int right){
        if(left == right){
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* a = merge(lists, left, mid);
        ListNode* b = merge(lists, mid+1, right);
        return merge2Lists(a,b);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return merge(lists, 0, lists.size()-1);
    }
};