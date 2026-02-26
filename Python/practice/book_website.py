class Book:
    
    def __init__(self,title,author):
        self.title=title
        self.author=author
        self.list_of_all_reviews=[]
  
    def Add_review(self,review):
       self.list_of_all_reviews.append(review)
    def count_review(self):
       print( len(self.list_of_all_reviews))
    def display_all_reviews(self):
        if not self.list_of_all_reviews:
            print("No  review Found")
        else:
            for i in self.list_of_all_reviews:
                print(f"review.{i}")

book1=Book("humaun ahmed","himu")
book1.Add_review("nice")
book1.Add_review("nice")
book1.Add_review("nice")
book1.Add_review("nice")
book1.display_all_reviews()