from collections import defaultdict
class Solution(object):
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        mapping = defaultdict(lambda : -1)
        tagedNode = defaultdict(lambda:[])
        groupTag = 0
        removedEdge = None
        for edge in edges:
            if mapping[edge[0]] == -1 and mapping[edge[1]] == -1:
                mapping[edge[0]] = groupTag
                mapping[edge[1]] = groupTag
                tagedNode[groupTag] += edge
                groupTag += 1
            elif mapping[edge[0]] == mapping[edge[1]]:
                removedEdge = edge
            elif mapping[edge[0]] == -1:
                mapping[edge[0]] = mapping[edge[1]]
                tagedNode[mapping[edge[0]]].append(edge[0])
            elif mapping[edge[1]] == -1:
                mapping[edge[1]] = mapping[edge[0]]
                tagedNode[mapping[edge[1]]].append(edge[1])
            else:
                oldTag = mapping[edge[0]]
                for node in tagedNode[oldTag]:
                    mapping[node] = mapping[edge[1]]
                    tagedNode[mapping[edge[1]]].append(node)
                tagedNode[oldTag] = []
        return removedEdge

sol = Solution()
result = sol.findRedundantConnection([[1,2], [2,3], [3,4], [1,4], [1,5]])
print(result)
result = sol.findRedundantConnection([[1,2], [1,3], [2,3]])
print(result)

result = sol.findRedundantConnection([[21,22],[4,7],[12,13],[13,25],[12,15],[17,23],[15,16],[8,21],[23,24],[3,9],[19,21],[13,21],[4,10],[5,6],[1,20],[10,16],[1,4],[10,14],[5,20],[1,2],[3,24],[2,11],[11,24],[24,25],[17,18]])
print(result)