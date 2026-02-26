from abc  import  ABC,abstractmethod

class Employee(ABC):
    @abstractmethod
    def calculate_salary(self):
        pass
class Intern(Employee):
    def __init__(self,month):
        self.month=month
    def calculate_salary(self):
        print(12000/self.month)
class Full_Time(Employee):
    def calculate_salary(self,month):
       print(120000/month)
class contract(Employee):
    def calculate_salary(self,month):
        print(1200000/month)


intern=Intern(3)

intern.calculate_salary()
    