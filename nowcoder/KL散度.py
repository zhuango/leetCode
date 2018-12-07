import sys
import math

la = sys.stdin.readline().strip().split(" ")
lb = sys.stdin.readline().strip().split(" ")

da = {}
db = {}
for ch in la:
    if ch not in da:
        da[ch] = 0
    da[ch] += 1
for ch in lb:
    if ch not in db:
        db[ch] = 0
    db[ch] += 1

for key in da:
    da[key] /= len(la)
for key in db:
    db[key] /= len(lb)

kl = 0
for key in da:
    kl += da[key] * math.log(da[key]/db[key], 2)
print('%.2f' % kl)