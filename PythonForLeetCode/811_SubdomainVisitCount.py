from collections import defaultdict
class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        mapping = defaultdict(lambda : 0)
        for record in cpdomains:
            countAndDomain = record.split(" ")
            visited = int(countAndDomain[0])
            subdomains = countAndDomain[1].split(".")
            subdomain = subdomains[-1]
            mapping[subdomain] += visited
            i = len(subdomains) - 2
            while i >= 0:
                subdomain = subdomains[i] + "." + subdomain
                mapping[subdomain] += visited
                i -= 1
        results = []
        for key in mapping:
            results.append("{} {}".format(mapping[key], key))
        return results