from binarytree import Node

class newNode:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None
 
def buildUtil(In, post, inStrt, inEnd, pIndex):
     
    if (inStrt > inEnd):
        return None
 
    node = newNode(post[pIndex[0]])
    pIndex[0] -= 1
 
    if (inStrt == inEnd):
        return node
 
    iIndex = search(In, inStrt, inEnd, node.data)
 
    node.right = buildUtil(In, post, iIndex + 1,
                                  inEnd, pIndex)
    node.left = buildUtil(In, post, inStrt,
                        iIndex - 1, pIndex)
 
    return node
 
def buildTree(In, post, n):
    pIndex = [n - 1]
    return buildUtil(In, post, 0, n - 1, pIndex)
 
def search(arr, strt, end, value):
    i = 0
    for i in range(strt, end + 1):
        if (arr[i] == value):
            break
    return i
 
def preOrder(node):
    if node == None:
        return
    print(node.data,end=" ")
    preOrder(node.left)
    preOrder(node.right)

def bu(node, tr):
    if not node:
        return None
    tr = Node(ord(node.data))

    tr.left = bu(node.left, tr.left)
    tr.right = bu(node.right, tr.right)

    return tr

if __name__ == '__main__':
    In = ['F', 'C', 'E', 'A', 'B', 'H', 'D', 'G']
    post = ['F', 'E', 'C', 'H', 'G', 'D', 'B', 'A']
    pre = ['A', 'C', 'F', 'E', 'B', 'D', 'H', 'G']
    n = len(In)
 
    root = buildTree(In, post, n)

    tr = None
    tr = bu(root, tr)

    print(tr)
    print('          '.join(pre))
    print('pre', tr.preorder)
    print('          '.join(post))
    print('post', tr.postorder)
    print('          '.join(In))
    print('in', tr.inorder)
 
    # print("Preorder of the constructed tree :")
    # preOrder(root)
    # print()
