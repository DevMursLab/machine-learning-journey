class Employee:
    start_time="4pm"
    end_time="6pm0"
class AdminStaff(Employee):
    def __init__(self,role):
        self.role=role
class Accountant(AdminStaff):
    def __init__(self,salary, role):
        super().__init__(role)
        self.salary=salary

acc1=Accountant(25000,"CA")
print(acc1.salary,acc1.role)