class Student:
    def __init__(self):
        print("check")#singel constructor
    def __init__(self,name,cgpa):#parameterized constructor
        self.name=name
        self.__cgpa=cgpa
    def get_gpa(self):
        return self.__cgpa
    def set_gpa(self,cgpa):
        if cgpa <0 and cgpa>4:
            print("invalid")
        self__cgpa=cgpa

stu1=Student("Rahul",3.67)
stu2=Student("Mursalin",3.00)
#print(stu1.cgpa)
stu2.set_gpa(3.9)
#print(stu2.get_gpa())
print(stu2.get_gpa)