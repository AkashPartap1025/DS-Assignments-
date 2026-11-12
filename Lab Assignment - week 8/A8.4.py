class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def is_bst(root, min_val=float('-inf'), max_val=float('inf')):

    if root is None:
        return True

    if root.data <= min_val or root.data >= max_val:
        return False

    return (is_bst(root.left, min_val, root.data) and
            is_bst(root.right, root.data, max_val))


# Example BST
root = Node(50)
root.left = Node(30)
root.right = Node(70)
root.left.left = Node(20)
root.left.right = Node(40)

if is_bst(root):
    print(" What is Result ?")
    print(" Valid BST")
else:
    print(" Not a BST")