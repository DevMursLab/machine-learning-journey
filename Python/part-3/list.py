marks=[1,23,4,5,6]
print(marks)
marks.insert(2,5)
idx=0
for val in marks:
    if val==23:
        print(f"23 found in {idx}")
        break
    idx+=1