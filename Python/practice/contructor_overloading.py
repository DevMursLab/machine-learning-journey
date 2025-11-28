class Person:
    def __init__(self,name=None,age=None,address=None):
        self.name=name
        self.address=address
        self.age=age
    def get_name(self):return self.name
    def get_age(self):return self.age
    def get_address(self):return self.address

person1=Person("rahim",25,"Netrokona")
print(person1.get_name(),person1.get_age(),person1.get_address())
        