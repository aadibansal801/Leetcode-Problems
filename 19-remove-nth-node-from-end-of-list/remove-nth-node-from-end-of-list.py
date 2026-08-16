# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        temp = head
        while temp is not None:
            temp = temp.next
            count+=1
        pos = count-n
        if pos == 0:
            return head.next
        temp = head
        for i in range(pos-1):
            temp = temp.next
        temp.next = temp.next.next
        return head