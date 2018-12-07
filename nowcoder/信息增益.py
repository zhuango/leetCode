import sys
import math

n = int(sys.stdin.readline().strip())

data = []
for i in range(n):
    wordlist = sys.stdin.readline().strip().split(",")
    data.append(wordlist)

label = [0, 0]
for sample in data:
    if sample[1] == "0":
        label[0] += 1
    else:
        label[1] += 1
label[0] /= len(data)
label[1] /= len(data)

if(label[0] == 0 or label[1] == 0):
    before = 0
else:
    before = -(label[0] * math.log(label[0], 2) + label[1] * math.log(label[1], 2))

dd = {}
for sample in data:
    if sample[0] not in dd:
        dd[sample[0]] = [0, 0, 0]
    if sample[1] == "0":
        dd[sample[0]][0] += 1
    else:
        dd[sample[0]][1] += 1
    dd[sample[0]][2] += 1
after = 0
for key in dd:
    d = dd[key]
    d[0] = d[0] / d[2]
    d[1] = d[1] / d[2]
    if(d[0] == 0 or d[1] == 0):
        temp = 0
    else:
        temp = -(d[0] * math.log(d[0], 2) + d[1] * math.log(d[1], 2))
    after += temp * (d[2] / len(data))

print('%.2f' % (before - after))
    

