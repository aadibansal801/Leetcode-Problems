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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left) temp->next = left;
        if(right) temp->next = right;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        right = sortList(right);
        return merge(left,right);
    }
};