class Employe:
    start_time="10am"
    end_time="11pm"
class Teacher(Employe):
    def __init__(self,subject):
        self.subject=subject

t1=Teacher("Math")
print(t1.subject,t1.start_time)
        