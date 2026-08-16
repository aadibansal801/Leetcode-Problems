# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        lenA = 0
        lenB = 0
        temp = headA
        while(temp):
            lenA+=1
            temp = temp.next
        temp = headB
        while(temp):
            lenB+=1
            temp = temp.next
        diff = abs(lenA - lenB)
        if(lenA>lenB):
            temp = headA
            for i in range(diff):
                temp = temp.next
            curr = headB
            while(temp):
                if(temp == curr):
                    return temp
                temp = temp.next
                curr = curr.next
        else:
            temp = headB
            for i in range(diff):
                temp = temp.next
            curr = headA
            while(temp):
                if(temp == curr):
                    return temp
                temp = temp.next
                curr = curr.next
        return None
