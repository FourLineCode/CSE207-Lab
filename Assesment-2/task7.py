# CD+A+B+EF+*
from binarytree import Node

class Et:
    def __init__(self , value):
        self.data = value
        self.left = None
        self.right = None
 
def isOperator(c):
    if (c == '+' or c == '-' or c == '*'
        or c == '/' or c == '^'):
        return True
    else:
        return False
 
def inorder(t):
    if t is not None:
        inorder(t.left)
        print(t.value, end='')
        inorder(t.right)
 
def constructTree(postfix):
    stack = []
    for char in postfix :
        if not isOperator(char):
            t = Et(char)
            stack.append(t)
        else:
            t = Et(char)
            t1 = stack.pop()
            t2 = stack.pop()
            t.right = t1
            t.left = t2
            stack.append(t)
 
    t = stack.pop()
    return t
 
def bu(node, tr):
    if not node:
        return None
    tr = Node(ord(node.data))

    tr.left = bu(node.left, tr.left)
    tr.right = bu(node.right, tr.right)

    return tr



postfix = "AB*CD/+EF-*"
r = constructTree(postfix)

tr = None
tr = bu(r, tr)

print(tr)
print(''.join([chr(x.value) for x in tr.preorder]))
print(''.join([chr(x.value) for x in tr.inorder]))