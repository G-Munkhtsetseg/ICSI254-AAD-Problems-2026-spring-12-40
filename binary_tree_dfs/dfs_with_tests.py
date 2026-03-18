#find the longest way in binary tree

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def find_longest_path(root):
    if not root:
        return []
    
    # First DFS: find farthest node from root
    farthest, _ = dfs(root, [])
    
    # Second DFS: find farthest from that node
    _, path = dfs(farthest, [])
    
    return [node.val for node in path]

def dfs(node, current_path):
    if not node:
        return (None, [])
    
    # Add current node to path
    new_path = current_path + [node]
    
    # If leaf node, return itself
    if not node.left and not node.right:
        return (node, new_path)
    
    # Check left and right
    left_farthest = (None, [])
    right_farthest = (None, [])
    
    if node.left:
        left_farthest = dfs(node.left, new_path)
    if node.right:
        right_farthest = dfs(node.right, new_path)
    
    # Return the longer path
    if len(left_farthest[1]) > len(right_farthest[1]):
        return left_farthest
    else:
        return right_farthest


# Simple test function
def test_longest_path():
    # Test 1: Simple tree
    #     1
    #    / \
    #   2   3
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    
    path = find_longest_path(root)
    print("Test 1 - Simple tree:")
    print(f"Path: {path}")
    print(f"Length: {len(path)-1} edges")
    print()
    
    # Test 2: Tree with deep left side
    #       1
    #      /
    #     2
    #    /
    #   3
    #  /
    # 4
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    root2.left.left = TreeNode(3)
    root2.left.left.left = TreeNode(4)
    
    path2 = find_longest_path(root2)
    print("Test 2 - Left-skewed tree:")
    print(f"Path: {path2}")
    print(f"Length: {len(path2)-1} edges")
    print()
    
    # Test 3: Complex tree
    #        10
    #       /  \
    #      5   15
    #     / \    \
    #    3   7    20
    #   /     \    \
    #  1       9    25
    root3 = TreeNode(10)
    root3.left = TreeNode(5)
    root3.right = TreeNode(15)
    root3.left.left = TreeNode(3)
    root3.left.right = TreeNode(7)
    root3.right.right = TreeNode(20)
    root3.left.left.left = TreeNode(1)
    root3.left.right.right = TreeNode(9)
    root3.right.right.right = TreeNode(25)
    
    path3 = find_longest_path(root3)
    print("Test 3 - Complex tree:")
    print(f"Path: {path3}")
    print(f"Length: {len(path3)-1} edges")
    
# Run the tests
test_longest_path()

