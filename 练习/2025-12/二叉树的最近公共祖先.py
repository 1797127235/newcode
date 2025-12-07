from collections import defaultdict


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #记录深度以及子节点的父亲
        depth = defaultdict(int)
        ps = defaultdict(lambda:None)
        def dfs(node,parent):
            if node is None:
                return 

            depth[node] = depth[parent]+1 if parent else 0
            ps[node] = parent
            dfs(node.left,node)
            dfs(node.right,node)

        dfs(root,None)

        #找两节点公告祖先
        while(1):
            if depth[p]>depth[q]:
                p = ps[p]
            elif depth[q]>depth[p]:
                q = ps[q]
            else:
                if p==q:
                    return p
                p = ps[p]
                q = ps[q]
