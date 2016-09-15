#!/usr/bin/python3
class Solution(object):
    def isPrime(self, number):
        if number <= 1:
            return False
        i = 2
        while i * i <= number:
            if number % i == 0:
                return False
            i += 1
        return True 
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        isPrime = {};
        i = 2
        while i < n:
            isPrime[i] = True;
            i += 1
        # Loop's ending condition is i * i < n instead of i < sqrt(n)
        # to avoid repeatedly calling an expensive function sqrt().
        i = 2
        while i * i < n:
            if not isPrime[i]:
                continue
            j = i * i
            while j < n:
                isPrime[j] = False
                j += i
            i += 1
        count = 0
        i = 2
        while i < n:
            if isPrime[i]:
                count += 1
            i += 1
        return count

sol = Solution()
print(sol.countPrimes(499979))