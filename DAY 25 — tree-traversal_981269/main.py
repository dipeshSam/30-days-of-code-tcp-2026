class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def getTreeTraversal(root):
    inorder = []
    preorder = []
    postorder = []

    def dfs(node):
        if not node:
            return

        # Preorder: Root → Left → Right
        preorder.append(node.data)

        dfs(node.left)

        # Inorder: Left → Root → Right
        inorder.append(node.data)

        dfs(node.right)

        # Postorder: Left → Right → Root
        postorder.append(node.data)

    dfs(root)
    return [inorder, preorder, postorder]


def main():
    # Constructing the example tree:
    #
    #          1
    #        /   \
    #       3     4
    #      / \   / \
    #     5   2 7   6

    root = BinaryTreeNode(1)

    root.left = BinaryTreeNode(3)
    root.right = BinaryTreeNode(4)

    root.left.left = BinaryTreeNode(5)
    root.left.right = BinaryTreeNode(2)

    root.right.left = BinaryTreeNode(7)
    root.right.right = BinaryTreeNode(6)

    traversals = getTreeTraversal(root)

    print("Inorder Traversal:  ", traversals[0])
    print("Preorder Traversal:", traversals[1])
    print("Postorder Traversal:", traversals[2])


if __name__ == "__main__":
    main()
