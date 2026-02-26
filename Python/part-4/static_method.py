class Laptop:
    storage_type="ssd"
    def __init__(self,rame,stoarage):
        self.rame=rame
        self.storage=stoarage
    
    def get_info(self):
        print(f"laptop has {self.rame} ram & {self.storage} {self.storage_type}")
    @staticmethod
    def calculate_discount(price,discount):
        final_price=price-(discount*price/100)
        print(f"discounted price ={final_price}")





l1=Laptop("16gb","512gb")
# l1.get_info()
l1.calculate_discount(40_000,10)
