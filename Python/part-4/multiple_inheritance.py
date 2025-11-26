class Teacher:
    def __init__(self,salary):
        self.salary=salary
class Student:
    def __init__(self,gpa):
        self.gpa=gpa
class TA(Teacher,Student):
    def __init__(self, salary,gpa,name):
        #super().__init__(salary)  only  akta  parent  er  jonno  super  call  kora  jabe 
        Student.__init__(self, gpa)
        Teacher.__init__(self, salary)

        self.name=name
ta1=TA(15_000,9.3,"Shraddha")
print(ta1.gpa,ta1.salary)