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

        if key < root.data:
            root.left = self.insert(root.left, key)
        elif key > root.data:
            root.right = self.insert(root.right, key)

        return root

    # Recursive Search
    def recursive_search(self, root, key):
        if root is None or root.data == key:
            return root

        if key < root.data:
            return self.recursive_search(root.left, key)

        return self.recursive_search(root.right, key)

    # Non-Recursive Search
    def iterative_search(self, root, key):

        while root:

            if root.data == key:
                return root

            elif key < root.data:
                root = root.left

            else:
                root = root.right

        return None

    # Minimum Element
    def minimum(self, root):

        while root.left:
            root = root.left

        return root.data

    # Maximum Element
    def maximum(self, root):

        while root.right:
            root = root.right

        return root.data

    # Inorder Successor
    def inorder_successor(self, root, key):

        successor = None

        while root:

            if key < root.data:
                successor = root
                root = root.left

            elif key > root.data:
                root = root.right

            else:
                if root.right:
                    temp = root.right

                    while temp.left:
                        temp = temp.left

                    successor = temp
                break

        return successor.data if successor else None

    # Inorder Predecessor
    def inorder_predecessor(self, root, key):

        predecessor = None

        while root:

            if key > root.data:
                predecessor = root
                root = root.right

            elif key < root.data:
                root = root.left

            else:
                if root.left:
                    temp = root.left

                    while temp.right:
                        temp = temp.right

                    predecessor = temp
                break

        return predecessor.data if predecessor else None


# Driver Program
bst = BST()
root = None

values = [50, 30, 70, 20, 40, 60, 80]

for v in values:
    root = bst.insert(root, v)

# Recursive Search
print("Recursive Search for 40:",
      "Found" if bst.recursive_search(root, 40) else "Not Found")

# Non-Recursive Search
print("Non-Recursive Search for 60:",
      "Found" if bst.iterative_search(root, 60) else "Not Found")

print("Minimum Element:", bst.minimum(root))
print("Maximum Element:", bst.maximum(root))

print("Inorder Successor of 40:",
      bst.inorder_successor(root, 40))

print("Inorder Predecessor of 40:",
      bst.inorder_predecessor(root, 40))
