class Student:
    college_name = "abc college"  # class attribute
    pi = 3.1

    def __init__(self, name, gpa, pi): 
        self.name = name  # instance attribute
        self.gpa = gpa
        self.pi = pi

stu1 = Student("Rahul", 9, 3.99)
print(stu1.pi)  # Output: 3.99
print(Student.pi)  # Output: 3.1
