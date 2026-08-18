"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return head
        temp = head
        while temp is not None:
            copy = Node(temp.val)
            copy.next = temp.next
            temp.next = copy
            temp = temp.next.next
        temp = head
        while temp is not None:
            if temp.random is not None:
                temp.next.random = temp.random.next
            temp = temp.next.next
        temp = head
        newHead = head.next
        while temp is not None:
            copy = temp.next
            temp.next = copy.next
            if copy.next is not None:
                copy.next = copy.next.next
            temp = temp.next
        return newHead