class Student:
    def __init__(self, name, cgpa):
        self.name = name
        self.__cgpa = cgpa   # private

    def get_gpa(self):
        return self.__cgpa

    def set_gpa(self, cgpa):
        if cgpa < 0 or cgpa > 4:
            print("Invalid CGPA!")
            return
        self.__cgpa = cgpa


stu1 = Student("Rahul", 3.67)
stu2 = Student("Mursalin", 3.00)

#stu1.cgpa   # ❌ private, direct access not allowed

stu2.set_gpa(3.9)        # valid
#print(stu2.get_gpa())    # ✅ 3.9

stu2.set_gpa(5)          # invalid
print(stu2.get_gpa())    # still 3.9
