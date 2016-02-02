class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        tags = []
        localted = [0, 0, 0,
                    0, 0, 0,
                    0, 0, 0, 0]
        for i in range(len(secret)):
            tags.append(False)
            localted[int(secret[i])] += 1
            if(secret[i] == guess[i]):
                tags[i] = True
        #hit = [False, False, False,
        #       False, False, False,
        #       False, False, False, False]
        countA = 0
        countB = 0
        for i in range(len(secret)):
            if(tags[i]):
                countA = countA + 1
                localted[int(secret[i])] -= 1
            elif(localted[int(guess[i])]):
                countB = countB + 1
                localted[int(guess[i])] -= 1
        else:
            return str(countA) + "A" + str(countB) + "B"
