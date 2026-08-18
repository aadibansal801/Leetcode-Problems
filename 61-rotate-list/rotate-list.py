# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if(head is None or head.next is None):
            return head
        temp = head
        count = 0
        end = None
        while temp is not None:
            if(temp.next is None):
                end = temp
            temp = temp.next
            count+=1
        end.next = head
        k = k%count
        k = count - k
        k-=1
        temp = head
        while temp is not None and k > 0:
            k-=1
            temp = temp.next
        head = temp.next
        temp.next = None
        return head
        