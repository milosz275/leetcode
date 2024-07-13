from typing import Union, Optional

class TreeNode(object):
    def __init__(self, val: int = 0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        """Construct a new TreeNode object.

        Args:
            val (int, optional): Node value. Defaults to 0.
            left (Union['TreeNode', None], optional): Left child. Defaults to None.
            right (Union['TreeNode', None], optional): Right child. Defaults to None.
        """
        self.val = val
        self.left = left
        self.right = right
        
def insert_level_order(arr, root, i, n):
    if i < n:
        temp = None if arr[i] is None else TreeNode(arr[i])
        root = temp

        if root is not None:
            root.left = insert_level_order(arr, root.left, 2 * i + 1, n)

        if root is not None:
            root.right = insert_level_order(arr, root.right, 2 * i + 2, n)
    return root

class Solution(object):
    def maxLevelSum(self, root):
        """Get the level with the maximum sum in a binary tree.
        :type root: TreeNode
        :rtype: int
        """
        max_level = 0

        return max_level
        
arr = [1,7,0,7,-8,None,None]
n = len(arr)
root = None
root = insert_level_order(arr, root, 0, n)

solution = Solution()

print(solution.maxLevelSum(root))
