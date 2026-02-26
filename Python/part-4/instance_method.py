class Laptop:
    storage_type="ssd"
    def __init__(self,rame,stoarage):
        self.rame=rame
        self.storage=stoarage
    
    def get_info(self):
        print(f"laptop has {self.rame} ram & {self.storage} {self.storage_type}")



l1=Laptop("16gb","512gb")
l1.get_info()