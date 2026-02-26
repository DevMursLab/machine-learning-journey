class Laptop:
    storage_type="ssd"
    def __init__(self,rame,stoarage):
        self.rame=rame
        self.storage=stoarage
    @classmethod
    def get_storage_type(cls):
       print(f"storage type =  {cls.storage_type}")
       



l1=Laptop("16gb","512gb")
l1.get_storage_type()