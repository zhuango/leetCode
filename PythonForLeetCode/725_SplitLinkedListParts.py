# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        result = []
        length = 0
        temp = root
        while temp != None:
            length += 1
            temp = temp.next
        print(length)
        if k >= length:
            while root != None:
                result.append(root)
                temp = root
                root = root.next
                temp.next = None
                k -= 1
            while k != 0:
                result.append(None)
                k -= 1
            return result
        temp = 0
        while temp < k:
            left = length - temp
            if left % k == 0:
                print(left)
                pieceLength = left / k
                while temp > 0:
                    curPiece = root
                    curLength = 0
                    preRoot = None
                    while curLength < pieceLength + 1:
                        preRoot = root
                        root = root.next
                        curLength += 1
                    preRoot.next = None
                    result.append(curPiece)
                    temp -= 1
                    k -= 1
                while k > 0:
                    curPiece = root
                    curLength = 0
                    preRoot = None
                    while curLength < pieceLength:
                        preRoot = root
                        root = root.next
                        curLength += 1
                    preRoot.next = None
                    result.append(curPiece)
                    k -= 1
            temp += 1
        return result

l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 4
root = ListNode(1)
temproot = root
for i in l[1:]:
    temproot.next = ListNode(i)
    temproot = temproot.next

sol = Solution()
result = sol.splitListToParts(root, k)
print(result)