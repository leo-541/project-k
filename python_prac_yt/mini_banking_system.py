#mini banking sysytem in python
import sys
import json
import random
from datetime import datetime
from datetime import date

#creat bank accounts sata stores
with open("accounts.json","w") as file:
                json.dump({},file,indent=4)
#to read the data from the json file
def file_read():
         with open("accounts.json","r") as file:
                data=json.load(file)
                return data
         
#to write new data in json file
def file_write(data):
        with open("accounts.json","w") as file:
                json.dump(data,file,indent=4)

#creat bank account

def creat_account():
        tpe=input("choise your account type \n1.saving  2.fixed  3.current \n").strip( ).upper()
        if tpe in ["SAVING","CURRENT","FIXED"]:
          dob=input("enter you dob dd/mm/yy").strip()
          dob_d=datetime.strptime(dob,"%d-%m-%Y").date()
          age=date.today().year-dob_d.year
          acc={
                "acc_type":tpe,
                "name":input("Enter your name: ").strip( ),
                "phone":input("Enter your phone number: ").strip( ),
                "dob":dob,
                "age":age,
                "acc_no":random.randint(11111111111,99999999999),
                "bal":int(input("diposit a initial balance").strip( )),
                "pin":(input("set your 4 digit pin").strip( )),
                "history":[]
           }
          if(date.today().month,date.today().day)<(dob_d.month,dob_d.day):
                 acc["age"]-=1
          d=file_read()
          d[acc["acc_no"]]=acc
          file_write(d)
          print("your account no:",acc["acc_no"])
        else:
                print("invalid account type")


class bank_acc:
        def login(self):
              self.d=file_read()
              if acc_num in self.d:
                     self.user_d=self.d[acc_num]
                     print("you are succesfully login")
                     return True
              

       # to withdrawal
        def withdraw(self,amount):
               self.d[acc_num]["bal"]-=amount
               hst="withdraw "+str(amount)
               self.d[acc_num]["history"].append(hst)
               file_write(self.d)
               print("withdrawal successfull")

       # to deposit
        def deposit(self,amount):
               self.d[acc_num]["bal"]+=amount
               hst="diposite "+str(amount)
               self.d[acc_num]["history"].append(hst)
               file_write(self.d)
               print("diposite successfull")

       # to check balanch
        def check_bal(self):
               print("you currnt balanch :",self.d[acc_num]["bal"])

       # to transefer money 
        def transfer(self,reciver_acc,amount):
               if self.d[acc_num]["bal"]>=amount and self.d[acc_num]["bal"]>0:
                      if reciver_acc in self.d:
                             self.d[reciver_acc]["bal"]+=amount
                             self.d[acc_num]["bal"]-=amount
                             hst="transfer to"+self.d[reciver_acc]["name"]+ str( amount)
                             self.d[acc_num]["history"].append(hst)
                             print("transfer successfully done ") 
                             file_write(self.d)
                      else:
                            
                            self.d[acc_num]["bal"]-=amount
                            hst="transfer to"+reciver_acc+ str( amount)
                            self.d[acc_num]["history"].append(hst)
                            print("transfer successfully done ") 
                            file_write(self.d)
               else:
                      print("your account balanch low to transfer this amount")

       # to update phone aur pin no
        def update(self,lst):
               for i in lst:
                      self.d[acc_num][i]=input(f"enter new {i} number")
                      file_write(self.d)

       # to delete the account
        def remove_acc(self):
               del self.d[acc_num]
               file_write(self.d)
               sys.exit()

       # for show the history of transection
        def history(self):
               if self.d[acc_num]["history"] != []:
                      print("history\nempty")
               else:
                     print("history")
                     for i in self.d[acc_num]["history"]:
                            print(i)

while True:       
 c=input("\n1.creat new account\n2.login\n3.exit\n").strip()
 if c=="creat new account" or c=="1":
       creat_account()
 elif c=="login" or c=="2":
       log=bank_acc()
       acc_num=input("enter your account no:")
       log_in=log.login()
       if log_in ==True:
              while True:
                     choice=input("type your choice\n1.withdrawal 2.deposit 3.check balanch 4.transfer 5.update 6.remove acc 7.history 8.exit\n").strip()
                     match choice:
                            case "withdrawal":
                                   amount=int(input("enter the amount you want to withdraw").strip( ))
                                   log.withdraw(amount)
                            case "deposit":
                                   amount=int(input("enter the amount you want to depost").strip( ))
                                   log.deposit(amount)
                            case "check balanch":
                                   log.check_bal()
                            case "transfer":
                                   reciver=input("enter the reciver acc no").strip()
                                   amount=int(input("enter the amount to transfer").strip())
                                   log.transfer(reciver,amount)
                            case "update":
                                   lst=input("choice update\n1.phone 2.pin you also update both type phone,pin").strip( ).split( )
                                   log.update(lst)
                            case "remove acc":
                                   log.remove_acc()
                            case "history":
                                   log.history()
                            case "exit":
                                   break
                            case _:
                                   print("invalid choice")

       else:
              print("wrong acc no or pin")
 elif c=="exit" or c=="3":
        break                  
 else:
       print("invalid enter ")
