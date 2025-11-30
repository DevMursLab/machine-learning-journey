#f1=open("new.txt","x")
# f1.write("hello  I  am  a  new  file")
# f1=open("new.txt","r+")
# #print(f1.read())
# f1.write("New vaia  new")


# f1=open("new.txt","w+")
# #print(f1.read())
# f1.write("New vaia  new")

#append
f1=open("new.txt","a+")
#print(f1.read())
f1.write("\nNew vaia  new\n")
print(f1)  #  nothing  to be  printed  beacuse  pointer  is  end  of the file
