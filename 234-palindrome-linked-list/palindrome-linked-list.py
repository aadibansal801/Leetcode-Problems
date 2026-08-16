# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    @staticmethod
    def reverse(head):
        dummy = None
        while head is not None:
            front = head.next
            head.next = dummy
            dummy = head
            head = front
        return dummy
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        if fast is not None:
            slow = slow.next
        secHalf = Solution.reverse(slow)
        firstHalf = head
        while secHalf is not None:
            if(firstHalf.val != secHalf.val):
                return False
            firstHalf = firstHalf.next
            secHalf = secHalf.next
        return True
            