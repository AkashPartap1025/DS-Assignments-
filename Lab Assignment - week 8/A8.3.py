class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BST:

    # Insert Node
    def insert(self, root, key):

        if root is None:
            return Node(key)

        # No duplicates allowed
        if key < root.data:
            root.left = self.insert(root.left, key)

        elif key > root.data:
            root.right = self.insert(root.right, key)

        return root

    # Find Minimum Node
    def find_min(self, root):
        while root.left:
            root = root.left
        return root

    # Delete Node
    def delete(self, root, key):

        if root is None:
            return root

        if key < root.data:
            root.left = self.delete(root.left, key)

        elif key > root.data:
            root.right = self.delete(root.right, key)

        else:

            # Case 1: No Child
            if root.left is None and root.right is None:
                return None

            # Case 2: One Child
            elif root.left is None:
                return root.right

            elif root.right is None:
                return root.left

            # Case 3: Two Children
            temp = self.find_min(root.right)

            root.data = temp.data

            root.right = self.delete(
                root.right, temp.data)

        return root

    # Maximum Depth
    def max_depth(self, root):

        if root is None:
            return 0

        left = self.max_depth(root.left)
        right = self.max_depth(root.right)

        return max(left, right) + 1

    # Minimum Depth
    def min_depth(self, root):

        if root is None:
            return 0

        if root.left is None and root.right is None:
            return 1

        if root.left is None:
            return self.min_depth(root.right) + 1

        if root.right is None:
            return self.min_depth(root.left) + 1

        return min(
            self.min_depth(root.left),
            self.min_depth(root.right)
        ) + 1

    # Inorder Traversal
    def inorder(self, root):

        if root:
            self.inorder(root.left)
            print(root.data, end=" ")
            self.inorder(root.right)


# Driver Program
bst = BST()
root = None

values = [50, 30, 70, 20, 40, 60, 80]

for value in values:
    root = bst.insert(root, value)

print("Inorder Traversal:")
bst.inorder(root)

print("\n\nMaximum Depth:",
      bst.max_depth(root))

print("Minimum Depth:",
      bst.min_depth(root))

root = bst.delete(root, 30)

print("\nAfter Deleting 30:")
bst.inorder(root)
