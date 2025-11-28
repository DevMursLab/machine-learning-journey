class Stdent:
    def __init__(self, name, roll, marks):
        # Constructor-এও চেক করা যায়
        if name == "":
            print("Name cannot be empty, setting default name")
            name = "Unknown"
        if roll < 1 or roll > 100:
            print("Roll number must be between 1 & 100, setting default roll=1")
            roll = 1
        if marks < 0:
            print("Marks must be positive, setting default marks=0")
            marks = 0

        self.__name = name
        self.__roll = roll
        self.__marks = marks

    def get_all_data(self):
        print(f"Name: {self.__name}   Roll: {self.__roll}   Marks: {self.__marks}")

    def set_marks(self, marks):
        if marks < 0:
            print("Marks must be positive")
        else:
            self.__marks = marks

    def set_roll(self, roll):
        if roll < 1 or roll > 100:
            print("Roll number must be between 1 & 100")
        else:
            self.__roll = roll

    def set_name(self, name):
        if name == "":
            print("Name cannot be empty")
        else:
            self.__name = name

# Object তৈরি
student1 = Stdent("", 150, -20)  # ভুল ইনপুট দিলে constructor চেক করবে
student1.get_all_data()

# Setter ব্যবহার
student1.set_name("Mursalin")
student1.set_roll(16)
student1.set_marks(60)
student1.get_all_data()
