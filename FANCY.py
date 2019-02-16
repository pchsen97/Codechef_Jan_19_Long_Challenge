for i in range (0,int(input())):
    s=str(input())
    if((" not " in s) or(s[0:4]=="not ") or (s[-4:-1]+s[-1]==" not")):
        print("Real Fancy")
    elif(len(s)==3 and s=="not"):
        print("Real Fancy")
    else:
        print("regularly fancy")