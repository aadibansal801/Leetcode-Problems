# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def findKthNode(temp, k):
            k-=1
            while temp is not None and k>0:
                k-=1
                temp = temp.next
            return temp
        def reverse(temp):
            dummy = None
            curr = temp
            while(curr):
                nextNode = curr.next
                curr.next = dummy
                dummy = curr
                curr = nextNode
            return dummy
        temp = head
        prevNode = None
        while temp is not None:
            kthNode = findKthNode(temp,k)
            if kthNode is None:
                if prevNode is not None:
                    prevNode.next = temp
                break
            nextNode = kthNode.next
            kthNode.next = None
            reverse(temp)
            if(temp == head):
                head = kthNode
            else:
                prevNode.next = kthNode
            prevNode = temp
            temp = nextNode
        return head

