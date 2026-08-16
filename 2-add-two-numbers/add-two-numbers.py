# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        newHead = ListNode(0)
        temp = newHead
        carry = 0
        while(l1 or l2):
            if(l1):
                x = l1.val
            else:
                x = 0
            if(l2):
                y = l2.val
            else:
                y = 0
            total = x+y+carry
            digit = total%10
            carry = total//10
            temp.next = ListNode(digit)
            temp = temp.next
            if(l1):
                l1 = l1.next
            if(l2):
                l2 = l2.next
        if(carry):
            temp.next = ListNode(carry)
        return newHead.next
            
