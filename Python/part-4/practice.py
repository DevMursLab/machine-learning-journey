class Product:
    count=0
    
    def __init__(self,name,price):
        self.name=name
        self.pribe=price
    def get_info(self):
        print(f"prce of {self.name} is Rs.{self.price} ")
    @classmethod
    def get_count(cls):
        print(f"total products count is ={cls.count}")
    
    @staticmethod
    def calc_discount(price,discount):
        print(f"discounted price={price-(price*discount/100)}")

p1=Product("phone",10_000)

Product.calc_discount(40_000,19)