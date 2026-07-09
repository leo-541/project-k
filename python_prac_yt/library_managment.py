# library management
import random

library=[]
record_issue_book=[]
def addbook():
    dict={
        "book_ID":random.randint(1000,9999),
        "name":input("enter the name of the book").strip( ),
        "author":input("enter the author name").strip( ),
        "quantity":int(input("enter no of books").strip( ))
    }
    library.append(dict)
    print("add  successfull")

# to display the books
def veiwbook():
    print("the available books are:")
    if library!=None:
          for i in library:
                print(i)
    else:
         print("0 there was no any books available")

#for search particular book by its name
def searchbook(name):
    found=False
    for i in library:
         if(i["name"]==name):
               print("the book is found",i)
               print("book is available ")
               found=True
    if found!=True:
         print("\nbook is not available in our library") 

 #for issue book 
def issuebook(st_book):
     for i in library:
          if(i["name"]==st_book["book_name"]):
               if i["quantity"]<=0:
                    print("book is not available")
                    
               else:
                    i["quantity"]-=1
                    print("issue successfull")

     record_issue_book.append(st_book)
 

#return book

def rtrn(returnbook):
    for i in library :
         if(returnbook["book_name"]==i["name"]):
              i["quantity"]+=1
              print("return successfull")
              break
    else:
         print("book is not available in our library")
    for i in record_issue_book:
         if(i["student"]==return_book["student"] and i["book_name"]==return_book["book_name"]):
            record_issue_book.remove(i)
            break
    else: 
         print("book is not available")   

#delete book
def deletebook(b_name):
     for i in library:
          if(i["name"]==b_name):
               library.remove(i)
               print("remove successfull")
               break
     else:
         print("book is not available")


#update book
def update(book_n):
     u=input("enter what to update name/author name/quantity ").strip( )
     new=input("enter new name or value").strip( )
     for i in library:
          if(i["name"]==book_n):
               if u!="quantity":
                    i[u]=new
                    print("update successfull")
                    break
               else:
                    i[u]=int(new)
                    print("update successfull")
                    break
     else: 
         print("book is not available") 
         

#main menu

while True:
        choich=input("------menu---------\n1.addbook  2.veiwbook 3.search book 4.delete book 5.update book details 6.issue book 7.return book 8.exit\n").strip( )
        match choich:
            case "addbook":
                addbook()
            case "veiwbook":
                    veiwbook()
            case "search book":
                    bn=input("enter book name to search").strip( )
                    searchbook(bn)
            case "delete book":
                    del_book=input("enter the name of the book which want to delte").strip( )
                    deletebook(del_book)
            case "update book details":
                    bn=input("enter book name to search").strip( )
                    update(bn)

            case "issue book":
                    issue_book={
                        "student":input("enter your name").strip( ),
                        "book_name":input("enter book name which you want").strip( )
                    } 
                    issuebook(issue_book) 

            case "return book":
                    return_book={
                        "student":input("enter your name"),
                    "book_name":input("enter book name ")
                } 
                    rtrn(return_book)
            case "exit":
                break
            case _:
                print("invalid enter")
        
    
