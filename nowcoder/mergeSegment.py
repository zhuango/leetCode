import os
s = int(input())
ranges = []
for i in range(s):
    line = input()
    rangesStr = line.strip().split(";")
    for ran in rangesStr:
        ranges.append([int(elem) for elem in ran.split(",")])
ranges = list(sorted(ranges, key=lambda x: x[0]))

result = []
temp = ranges[0]
i = 1
while i < len(ranges):
    if ranges[i][0] <= temp[1]:
        temp = [min([temp[0], ranges[i][0]]), max([temp[1], ranges[i][1]])]
    else:
        result.append(temp)
        temp = ranges[i]
    i+=1
result.append(temp)
s = []
for rang in result:
    s.append(",".join([str(elem) for elem in rang]))
print(";".join(s))