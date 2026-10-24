# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: list[int]) -> TreeNode | None:
        preIdx = 0
        def build(low, high):
            nonlocal preIdx
            if preIdx == len(preorder):
                return None
            if preorder[preIdx] < low or preorder[preIdx] > high:
                return None
            root = TreeNode(preorder[preIdx])
            preIdx+=1
            root.left = build(low, root.val)
            root.right = build(root.val, high)
            return root
        return build(float('-inf'), float('inf'))
