class Operation:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def execute(self):
        pass  # Abstract method, child class override করবে

class Add(Operation):
    def execute(self):
        print(self.a + self.b)

class Concate(Operation):
    def execute(self):
        print(str(self.a) + str(self.b))  # string হিসেবে যোগ

# Testing
op1 = Add(5, 10)
op2 = Concate("Hello", "World")

# Polymorphism: একই interface
for op in [op1, op2]:
    op.execute()
