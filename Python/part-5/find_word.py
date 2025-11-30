
# f1 = open("file.txt", "r")
# for i in f1:
#     if "hello" in i:
#         print("Exist")

# f1 = open("file.txt","r")
# for line in f1:  # iterate  per  line
#     for word in line.split(): #  per  line  er  word  khujte
#         print(word)

data=True
line=1
word="hello"
with open("file.txt","r") as f:
    while data:
        data=f.readline()
        if(word in data):
            print(f"{word} found in line:{line}")
            break
        line+=1