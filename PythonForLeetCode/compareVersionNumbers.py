#!/usr/bin/python3
class Solution(object):
    def getVersionNumberList(self, version1):
        length = len(version1)
        i = 0
        result = []
        counter = 0
        singleNumberStr = ""
        while i < length:
            if version1[i] == '.':
                result.append(singleNumberStr)
                singleNumberStr = ''
                counter += 1
            else:
                singleNumberStr += version1[i]
            i += 1
        if not singleNumberStr == '':
            result.append(singleNumberStr)
            counter += 1
        result.append('0')
        return (result, counter)
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        versionNumberlist1, length1 = self.getVersionNumberList(version1)
        versionNumberlist2, length2 = self.getVersionNumberList(version2)

        i = 0
        j = 0
        while i < length1 and j < length2:
            if   int(versionNumberlist1[i]) > int(versionNumberlist2[i]):
                return 1
            elif int(versionNumberlist1[i]) < int(versionNumberlist2[i]):
                return -1
            i += 1
            j += 1
        if i < length1:
            while i < length1:
                if int(versionNumberlist1[i]) > 0:
                    return 1 
                i += 1
            return 0
        if j < length2:
            while j < length2:
                if int(versionNumberlist2[j]) > 0:
                    return -1 
                j += 1
            return 0
        return 0

sol = Solution()
print(sol.compareVersion("1.0", "1"))