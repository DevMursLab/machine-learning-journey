# l=[i*i for  i in  range(6)]
# print(l)

# l=[i*i for i in range(6)  if i&1]
# print(l)
l=[1,2,3,4,5,6,-1]
l=[0 if i<0 else i for i in range(6)]
print(l)
 
words=["hello","python","apna college"]
words=[val.upper() for val in  words]
print(words)