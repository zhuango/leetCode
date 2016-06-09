import time
def intersect(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: List[int]
    """
    start = time.time()
    resultList = []
    # O(m*n)
    for i in range(0, len(nums2)):
        if(nums2[i] in nums1):
            nums1.remove(nums2[i])
            resultList.append(nums2[i])
    end = time.time()
    print("intersect used : " + str(end - start) + " seconds")
    return resultList

def intersect_sort(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: List[int]
    """
    nums1 = sorted(nums1)
    nums2 = sorted(nums2)
    start = time.time()
    resultList = []
    i = 0
    j = 0
    # O(m + n)
    len1 = len(nums1)
    len2 = len(nums2)
    while(i < len1 and j < len2):
        if(nums1[i] == nums2[j]):
            resultList.append(nums1[i])
            i+=1
            j+=1
        elif(nums1[i] > nums2[j]):
            j+=1
        else :
            i+=1
    end = time.time()
    print("intersect used : " + str(end - start) + " seconds")
    return resultList


def intersect_unique(nums1, nums2):
    """
    :type nums1: List[int]
    :type nums2: List[int]
    :rtype: List[int]
    """
    nums1 = sorted(nums1)
    nums2 = sorted(nums2)
    start = time.time()
    resultList = []
    i = 0
    j = 0
    # O(m + n)
    len1 = len(nums1)
    len2 = len(nums2)
    while(i < len1 and j < len2):
        if(j > 0 and nums2[j] == nums2[j - 1]):
            j+=1
            continue
        if(nums1[i] == nums2[j]):
            resultList.append(nums1[i])
            i+=1
            j+=1
        elif(nums1[i] > nums2[j]):
            j+=1
        else :
            i+=1
    end = time.time()
    print("intersect used : " + str(end - start) + " seconds")
    return resultList

result = intersect([1, 1, 1, 2,1, 3, 21, 2],[2, 1, 1, 1, 54, 2,4 , 123, 123, 32])
print(result)

result = intersect_sort([1, 1, 1, 2,1, 3, 21, 2],[2, 1, 1, 1, 54, 2,4 , 123, 123, 32])
print(result)

result = intersect_unique([1, 1, 1, 2,1, 3, 21, 2],[2, 1, 1, 1, 54, 2,4 , 123, 123, 32])
print(result)