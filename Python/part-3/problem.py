info=[
    ("Alice","Math"),
    ("Bob","Science"),
    ("Alice","Science"),
    ("Charlie","Math"),
    
]
course_set=set()
english=set()
for tup in info:
    course_set.add(tup[1])

#print(course_set)
# for tup in info:
#     if tup[1]=="Math":
#         english.add(tup[0])
# print(english)

for name,course in info:
    if course=="Math":
        english.add(name)

#print(english)

dic={}
for name,course in info:
    if dic.get(name)==None:
        dic.update({name:set()})
        dic[name].add(course)
print(dic)
