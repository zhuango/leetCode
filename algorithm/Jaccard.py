def jaccard(da, db, spliter=" "):
    aset = set()
    bset = set()

    for word in da.split(spliter):
        aset.add(word)
    for word in db.split(spliter):
        bset.add(word)
    
    unitSet = aset.union(bset)
    intSet = aset.intersection(bset)
    
    return len(intSet) / len(unitSet)

if __name__ == "__main__":
    da = "what a beautiful day"
    db = "a beautiful day"
    dc = "a day day up"

    print(jaccard(da, db))
    print(jaccard(db, dc))