class Student:
    def __init__(self,age):
        self.__age=age
    @classmethod
    def from_birth_year(cls,year):
        return cls(2025-year)

p=Student(30)
print(p.__age)
print(p._Student__age)