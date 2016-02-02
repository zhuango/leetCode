def wordPattern(pattern, str):
    """
    :type pattern: str
    :type str: str
    :rtype: bool
    """
    mapingtest = {}
    antiMaping = {}
    strSet = str.split(" ")
    if not len(pattern) == len(strSet):
        return False

    for i in range(len(strSet)):
        if not mapingtest.get(pattern[i]) and not antiMaping.get(strSet[i]):
            mapingtest[pattern[i]] = strSet[i]
            antiMaping[strSet[i]] = True
        elif not mapingtest.get(pattern[i]) or not antiMaping.get(strSet[i]):
            return False
        elif not mapingtest[pattern[i]] == strSet[i]:
            return False

    return True

print (wordPattern("abba", "dog cat cat fish") == False)
print (wordPattern("aaaa", "dog dog dog dog") == True)
print (wordPattern("abcd", "dog og dg d") == True)
print (wordPattern("abcc", "dog og dg d") == False)
print (wordPattern("abba", "dog a dog a") == False)
print (wordPattern("abba", "dog dog dog dog") == False)