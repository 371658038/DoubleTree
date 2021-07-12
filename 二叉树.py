class Node():
    def __init__(self, item):
        self.item = item
        self.right = None
        self.left = None


class Tree():
    def __init__(self):
        self.root = None

    def add(self, item):
        node = Node(item)
        if self.root is None:
            self.root = node
            return
        else:
            queue = [self.root]
            while queue:
                cur = queue.pop(0)
                if cur.left is None:
                    cur.left = node
                    return
                else:
                    queue.append(cur.left)
                if cur.right is None:
                    cur.right = node
                    return
                else:
                    queue.append(cur.right)

    # 广度遍历
    def travel(self):
        if self.root is None:
            print('')
            return
        else:
            queue = [self.root]
            while queue:
                cur = queue.pop(0)
                print(cur.item)
                if cur.left is not None:
                    queue.append(cur.left)
                if cur.right is not None:
                    queue.append(cur.right)

    # 深度遍历：前序，中序，后序遍历
    def forwordTravel(self, root):
        if root is None:
            return
        print(root.item, end=' ')
        self.forwordTravel(root.left)
        self.forwordTravel(root.right)

    def middleTravel(self, root):
        if root is None:
            return
        self.middleTravel(root.left)
        print(root.item, end=' ')
        self.middleTravel(root.right)

    def backTravel(self, root):
        if root is None:
            return
        self.backTravel(root.left)
        self.backTravel(root.right)
        print(root.item, end=' ')


tree = Tree()
tree.add('0')
tree.add('1')
tree.add('2')
tree.add('3')
tree.add('4')
tree.add('5')
tree.add('6')
tree.add('7')
tree.add('8')
tree.add('9')

tree.travel()
tree.forwordTravel(tree.root)
print('\n')
tree.backTravel(tree.root)
print('\n')
tree.middleTravel(tree.root)
print('\n')