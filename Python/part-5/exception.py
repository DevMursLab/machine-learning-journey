try:
    x=int(input("Enter vthe x: "))
    ans=10/x
except ZeroDivisionError:
    print(f"Division  by    0  is not allowed")
except ValueError:
    print("invalid Input")
else:
    print(f"ans={ans}")