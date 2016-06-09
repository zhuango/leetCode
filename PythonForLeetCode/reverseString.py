def reverseString(s):
    """
    :type s: str
    :rtype: str
    """
    result = ''
    i = len(s) - 1
    while(i >= 0):
        result += s[i]
    return result
    #for alph in s:
s = 'liuzhuang'
print(reverseString(s))