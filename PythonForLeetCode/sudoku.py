#!/usr/bin/python3
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        from collections import defaultdict
        n = len(board)
        table = defaultdict(lambda:False)
        i = 0
        j = 0
        for i in range(n):
            for key in table:
                table[key] = False
            for j in range(n):
                curNumber = board[i][j]
                if curNumber == '.':
                    continue
                if table[curNumber]:
                    return False
                table[curNumber] = True
        for j in range(n):
            for key in table:
                table[key] = False
            for i in range(n):
                curNumber = board[i][j]
                if curNumber == '.':
                    continue
                if table[curNumber]:
                    return False
                table[curNumber] = True
        for i in range(n // 3):
            for j in range(n // 3):
                for key in table:
                    table[key] = False
                k = 0
                while k < 3:
                    l = 0
                    while l < 3:
                        curNumber = board[i*3 + k][j*3 + l]
                        if curNumber == '.':
                            l+=1
                            continue
                        if table[curNumber]:
                            return False
                        table[curNumber] = True
                        l += 1
                    k += 1
        
        return True

pro = Solution()
print(pro.isValidSudoku(["....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"]))