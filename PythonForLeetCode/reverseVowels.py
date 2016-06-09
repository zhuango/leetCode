def reverseVowels(self, s):
    """
    :type s: str
    :rtype: str
    """
    vowels='aeiouAEIOU'
    vpos=[i for i,j in enumerate(s) if j in vowels]
    svrev=list(s)
    i,j=0,len(vpos)-1
    while i<j:
        svrev[vpos[i]],svrev[vpos[j]]=svrev[vpos[j]],svrev[vpos[i]]
        i+=1
        j-=1
    return ''.join(svrev)
    
for i, j in enumerate("liuzhuang"):
    print(str(i) + " " + str(j))

