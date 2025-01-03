#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;
//structure to read the date from file
struct read{
string id;
int password;
int balance;
};
//function to read the file
void Read_File(read* myRead){
    ifstream myfile("login.txt");
    read temp;
    int i=0;
    while(myfile>>temp.id>>temp.password>>temp.balance){
       myRead[i].id=temp.id;
       myRead[i].password=temp.password;
       myRead[i].balance=temp.balance;
       i++;
    }
myfile.close();
}
//function to determine size of records file
int size_function(){
ifstream myfile("login.txt");
int size=0;
read temp;
while(myfile>>temp.id>>temp.password>>temp.balance){
    size++;
}
myfile.close();
return size;
}
//structure for cash deposit
struct cashDeposit{
int balance;
int deposit;
};
//function to deposit money in account
void cash_deposit(string* name , read* myread){
    cout<<"\nEnter amount to Deposit : ";
    cashDeposit myProcess;
    read myRead;
    int i;
    for(i=0;i<size_function();i++){
        if(myread[i].id==*name){
            myProcess.balance=myread[i].balance;
            break;
        }
    }
    cin>>myProcess.deposit;

    cashDeposit temp;
    int currentBalance=  myProcess.balance  + myProcess.deposit;
    myread[i].balance=currentBalance;
    ifstream login("login.txt");
    ofstream tempFile("temp.txt",ios::app);
    while(login>>myRead.id>>myRead.password>>myRead.balance){
        if(myRead.id==*name){
            myRead.balance=currentBalance;
        }
        tempFile<<myRead.id<< " "<<myRead.password<< " "<<myRead.balance <<"\n";
    }
    cout<<"\nDEPOSIT SUCCESSFUL\nCurrent Balance is " <<currentBalance;
    tempFile.close();
    login.close();
    remove("login.txt");
    rename("temp.txt","login.txt");
}
//structure for loans
struct loan{
int months;
int amount;
float intrest;
float monthlyPayment;
};
//function for interest free loan
void interest_free_loan(){
cout<<"\nINTEREST FREE LOAN \n";
cout<<"\nfor interest free loan the months should be Less Than 12 months";
cout<<"\nEnter Required Amount ";
loan myLoan;
cin>>myLoan.amount;
cout<<"\nEnter Months ";
do{
    cin>>myLoan.months;
    if(myLoan.months>12){
        cout<<"Months Should Be Less Than 12. TRY AGAIN ";
    }
}while(myLoan.months>12);
myLoan.monthlyPayment=myLoan.amount/myLoan.months;
cout<<"\nAccording to Current Plan Your Monthly Payment Will be "<<myLoan.monthlyPayment;
cout<<"\nDo You Want To Proceed With The Current Plan(Y/N) ";
char choice;
do{
    cin>>choice;
    if(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' ){
        cout<<"\nInvalid Choice. TRY AGAIN \n";
    }
}while(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' );
if(choice=='y'||choice=='Y'){
    cout<<"\nCONGRATULATIONS Your Loan Application Has Been Approved \n";
    ofstream loanRecord("loan record.txt",ios::app);
    loanRecord << myLoan.amount<< " "<<myLoan.months<< " " <<myLoan.monthlyPayment<< "  NA" <<endl;
}
else if(choice=='N'  ||choice=='n' ){
    cout<<"\nSorry for Disappointing. Please Make a More Suitable Plan\n ";
}
}

//function to calculate interest
float interest_value(int months){
if (months<=12) {
    return 2.5;
}
else if(months>12 && months<=24){
    return 2.7;
}
else if(months>24){
    return 3.0;
}
}
//Function for normal loan
void normal_loan(){
cout<<"\nLOAN WITH INTEREST\n";
cout<<"\nEnter Required Amount ";
loan myLoan;
cin>>myLoan.amount;
cout<<"\nEnter Months ";
cin>>myLoan.months;
myLoan.intrest=interest_value(myLoan.months);
myLoan.monthlyPayment=(myLoan.amount*(1+myLoan.intrest/100))/myLoan.months;
cout<<"\nAccording to Your Current Plan Your Monthly Payment is "<<myLoan.monthlyPayment<<" at " <<myLoan.intrest << " intrest rate ";
cout<<"\nDo You Want To Proceed With The Current Plan(Y/N) ";
char choice;
do{
    cin>>choice;
    if(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' ){
        cout<<"\nInvalid Choice. TRY AGAIN \n";
    }
}while(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' );
if(choice=='y'||choice=='Y'){
    cout<<"\nCONGRATULATIONS Your Loan Application Has Been Approved \n";
     ofstream loanRecord("loan record.txt",ios::app);
    loanRecord << myLoan.amount<< " "<<myLoan.months<< " " <<myLoan.monthlyPayment<< "  INT" <<endl;

}
else if(choice=='N'  ||choice=='n' ){
    cout<<"\nSorry for Disappointing. Please Make a More Suitable Plan\n ";
}
}
//function for loan applications
void apply_loan(){
cout<<"\nWELCOME TO THE LOAN APPLICATION\n";
cout<<"\nPress 1 For Interest Free Loan ";
cout<<"\nPress 2 For Loan With Interest ";
cout<<"\nPress 3 to Exit \n";
int choice;
do{
cin>>choice;
if(choice!=1&& choice!=2 && choice!=3){
    cout<<"\nInvalid Choice. TRY AGAIN \n";
}
}while(choice!=1&& choice!=2 && choice!=3);
switch(choice){
case 1:
    interest_free_loan();
    break;
case 2:
    normal_loan();
    break;
case 3:
    break;
}
}

//structure for cash withdraw;
struct cashwithdraw{
int balance;
int withDraw;
};

//function to withdraw cash
void cash_withdraw(string*name , read* myread){
    cout<<"\nEnter amount to withdraw : ";
    cashwithdraw myProcess;
    read myRead;
    int i;
    for(i=0;i<size_function();i++){
        if(myread[i].id==*name){
            myProcess.balance=myread[i].balance;
            break;
        }
    }
    do{
    cin>>myProcess.withDraw;
    if(myProcess.withDraw>myProcess.balance){
        cout<<"\nInsufficient Funds ";
    cout<<"\nRemaining Balance "<< myProcess.balance ;}
    }while(myProcess.withDraw>myProcess.balance);
    cashwithdraw temp;
    int remainingBalance=  myProcess.balance  - myProcess.withDraw;
    myread[i].balance=remainingBalance;
    ifstream login("login.txt");
    ofstream tempFile("temp.txt");
    while(login>>myRead.id>>myRead.password>>myRead.balance){
        if(myRead.id==*name){
            myRead.balance=remainingBalance;
        }
        tempFile<<myRead.id<< " "<<myRead.password<< " "<<myRead.balance <<"\n";
    }
    cout<<"\nTRANSACTION SUCCESSFUL\nRemaining Balance is " <<remainingBalance;
    tempFile.close();
    login.close();
    remove("login.txt");
    rename("temp.txt","login.txt");
}
//structure for login
struct log_check{
string acc_ID;
int PIN;
};
//Login Check Function
bool login(string* name){
log_check myLogin, temp;
ifstream myfile("login.txt");
if(!myfile.is_open()){
    cout<<"\n FILE NOT FOUND\n";
    return false;
}
for(int i=1;i<=3;i++){

  cout<<"\nEnter Your Account ID\n";
  cin>>myLogin.acc_ID;
  cout<<"\nEnter Your Account PIN\n";
  cin>>myLogin.PIN;
  int balance;
  myfile.clear();
  myfile.seekg(0, ios::beg);
  while(myfile>>temp.acc_ID>>temp.PIN>>balance){
    if(temp.acc_ID==myLogin.acc_ID && temp.PIN==myLogin.PIN){
        *name=myLogin.acc_ID;
        return true;
    }
  }
   cout<<"\nincorrect ID or Password. TRY AGAIN \n";
}
myfile.close();
return false;
}
//structure for new account;
struct new_acc{
string name;
log_check myLogin;
long long int mobile_number;
};
//function to get in a new account
void create_account(read* myread){
    new_acc temp1;
cout <<"\nwelcome new user";
cout<<"\nEnter your name ";
cin.ignore();
getline (cin, temp1.name);
cout<<"\nEnter your mobile number ";
cin>>temp1.mobile_number;
bool unique_id=false;
do{
        unique_id=true;
cout<<"\nEnter your account ID ";
cin>>temp1.myLogin.acc_ID;
for(int i=0; i<size_function();i++){
     if(myread[i].id==temp1.myLogin.acc_ID){
        cout<<"\nUser Name Not Available. Try Again ";
        unique_id=false;
      break;
     }
}
}while(!unique_id);
cout<<"\nUser Name Authenticated ";

cout<<"\nEnter your PIN ";
cin>>temp1.myLogin.PIN;
ofstream myfile("login.txt", ios::app);
myfile<<"\n" <<temp1.myLogin.acc_ID<< " "<<temp1.myLogin.PIN<< " " << 0;
myfile.close();
cout<<"\nAccount Registered Successfully ";

}
int check_balance(read* myRead,string* name){
    for(int i=0; i<size_function();i++){
        if(myRead[i].id==*name){
            cout<<"\nYour Current Balance is " <<myRead[i].balance << "\n ";
            break;
        }
    }
}

//struct for home lease
struct houseLease{
int houseNumber;
string address;
int houseValue;
int month;
float monthlyLease;
};
//function for admin to view house leases
void house_lease_records(){
vector<string> houseNum;
ifstream houseRecs("house lease record.txt");
if(!houseRecs.is_open()){
    cout<<"\nFile Not Found ";
    return;
}
bool check=true;
houseLease temp;
string name;
string line;
char status;
int rejected=0,accepted=0;
cout<<"\n\t\tHouse Lease Records \n";
while(getline(houseRecs,line)){
    if(check){
      stringstream ss(line);
       ss>>name;
       getline(houseRecs,temp.address);
       check=false;
    }
    else{
        stringstream ss(line);
        ss>> temp.houseNumber>>temp.houseValue>>temp.month>>temp.monthlyLease>>status;
        check=true;
    cout<<"\nName : "<<name;
    cout<<"\nAddress : "<<temp.address;
    cout<<"\nHouse Number : "<<temp.houseNumber;
    cout<<"\nHouse Value : "<<temp.houseValue;
    cout<<"\nMonths : "<<temp.month;
    cout<<"\nMonthly Lease : "<<temp.monthlyLease;
    cout<<"\nApplication Status : "<<status;
    cout<<"\n\n\n";}
    if(status=='y'){
        accepted++;
    }else if(status=='n'){
    rejected++;
    }


}
cout<<"\nAccepted Applications : "<<accepted;
cout<<"\nRejected Applications : "<<rejected;
}
//function to lease a car
void house_lease_function(string* name){
cout<<"\nWELCOME TO HOUSE LEASE APPLICATION\n";
houseLease myHouseLease;
cout<<"\nEnter Your House Number ";
cin>>myHouseLease.houseNumber;
cout<<"\nEnter Your House Address ";
cin.ignore();
getline(cin, myHouseLease.address);
cout<<"\nEnter Value of The House ";
cin>>myHouseLease.houseValue;
cout<<"\nHow Many Months You Want to Lease ";
cin>>myHouseLease.month;
myHouseLease.monthlyLease=myHouseLease.houseValue/myHouseLease.month;
cout<<"\nYour Monthly Lease Will Be "<< myHouseLease.monthlyLease;
cout<<"\nDo You Want To Proceed(Y/N) ";
char choice;
do{
    cin>>choice;
    if(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' ){
        cout<<"\nInvalid Choice. TRY AGAIN \n";
    }
}while(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' );
if(choice=='y'||choice=='Y'){
    cout<<"\nCONGRATULATIONS! "<< *name <<" Your House Lease is Approved\n";

}
else if(choice=='N'  ||choice=='n' ){
    cout<<"\nSorry for Disappointing.\n ";
}
ofstream houseRecord("house lease record.txt", ios::app);
houseRecord<<*name<< "\n"<<myHouseLease.address<<"\n"<<myHouseLease.houseNumber<<" " <<myHouseLease.houseValue<<" "<<myHouseLease.month<<" "<<myHouseLease.monthlyLease<<" "<<choice<<endl;
houseRecord.close();
}

//struct for car lease
struct carLease{
int regNumber;
string model;
int productionYear;
int carValue;
int month;
float monthlyLease;
};
//admin function to check all car lease
void car_lease_records(){
cout<<"\nCar Lease Records \n ";
string name;
ifstream myfile("car lease record.txt");
if(!myfile.is_open()){
    cout<<"\nFile Not Found";
    return;
}
char status;
int approved=0,rejected=0;
carLease temp;
cout<<"Name"<<setw(15)<<"prodYear"<<setw(15)<<"model"<<setw(15)<<"regNum"<<setw(15)<<"Value"<<setw(15)<<"Month"<<setw(15)<<"Lease"<<setw(15)<<"status"<<endl;
while(myfile>>name>>temp.productionYear>>temp.model>>temp.regNumber>>temp.carValue>>temp.month>>temp.monthlyLease>>status){
    cout<< left << setw(15)<<name << setw(15) <<temp.productionYear<<setw(15) <<temp.model<<setw(15) << temp.regNumber<<setw(15)<<temp.carValue<<setw(15) <<temp.month<<setw(15)<<temp.monthlyLease<<setw(15) <<status <<endl;
if(status =='y'){
    approved++;
}
else if(status=='n'){
    rejected++;
}
}
cout<<"\nRejected Applications: "<<rejected;
cout<<"\nApproved Applications: "<<approved;
}
//function to lease a car
void car_lease_function(string* name){
cout<<"\nWELCOME TO CAR LEASE APPLICATION\n";
carLease myCarLease;
cout<<"\nEnter Your Car Registration Number ";
cin>>myCarLease.regNumber;
cout<<"\nEnter Your Car Model ";
cin.ignore();
getline(cin, myCarLease.model);
cout<<"\nEnter Production Year ";
cin>>myCarLease.productionYear;
cout<<"\nEnter Value of The Car ";
cin>>myCarLease.carValue;
cout<<"\nHow Many Months You Want to Lease ";
cin>>myCarLease.month;
myCarLease.monthlyLease=myCarLease.carValue/myCarLease.month;
cout<<"\nYour Monthly Lease Will Be "<< myCarLease.monthlyLease;
cout<<"\nDo You Want To Proceed(Y/N) ";
char choice;
do{
    cin>>choice;
    if(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' ){
        cout<<"\nInvalid Choice. TRY AGAIN \n";
    }
}while(choice!='y' &&choice!='Y' &&choice!='N' &&choice!='n' );
if(choice=='y'||choice=='Y'){
    cout<<"\nCONGRATULATIONS! "<< *name <<" Your Car Lease is Approved\n";

}
else if(choice=='N'  ||choice=='n' ){
    cout<<"\nSorry for Disappointing.\n ";
}
ofstream carLeaseRecord("car lease record.txt", ios::app);
carLeaseRecord<<*name<< " "<<myCarLease.productionYear<<" "<<myCarLease.model<<" "<<myCarLease.regNumber<<" " <<myCarLease.carValue<<" "<<myCarLease.month<<" "<<myCarLease.monthlyLease<<" "<<choice<<endl;
carLeaseRecord.close();
}

//function for menu
int menu(int *action){
int choice;
do{
cout<<"\n\nPress 1 to Withdraw Cash ";
cout<<"\nPress 2 to Deposit Cash ";
cout<<"\nPress 3 to Apply for Loan ";
cout<<"\nPress 4 to Apply for Car Lease ";
cout<<"\nPress 5 to Apply for Home Lease ";
cout<<"\nPress 6 to Check Balance ";
cout<<"\nPress 7 to Check Transactional History ";
cout<<"\nPress 8 to Apply For a Card ";
cout<<"\nPress 9 to Exit \n";
cin>>choice;
if(choice>9 && choice<1){
    cout<<"\nInvalid Choice. Try Again ";
}
}while( !choice<=9 && !choice>=1);
*action=choice;
return choice;
}
struct transaction{
string date;
int balance;
string type;
int amount;
};
void displaySevenDayHistory(int**data,string*name){
vector<transaction> trans;
for(int i=0; i<7;i++){
    transaction temp;
    temp.date= to_string(10+i)+"-1-2025";
    temp.amount=data[rand()%4][i];
    temp.balance=rand()/10;
    if(i%2==0){
    temp.type="Deposit\t";
    }else {
    temp.type="Withdraw";
    }
trans.push_back(temp);
}
cout<<"\nTransaction History For Last 7 Days \n";
for(int i=0;i<7;i++){
    cout<<"day"<<i+1<< "\t"<<trans[i].date<<"\t"<<trans[i].amount<<"\t"<<trans[i].type<<"\t"<<trans[i].balance<<"\n";
}
}
void displayMonthHistory(int**data){
    cout<<"\nPress 1 For Withdraw History ";
    cout<<"\nPress 2 For Deposit History ";
    int option;
     do{
        cin>>option;
        if(option!=1 && option!=2){
            cout<<"\nInvalid Choice. TRY AGAIN";
        }
    }while(option!=1 && option!=2);
    if(option ==1){
        cout<<"\n\t\tWithdraw History \n";
    }else{
        cout<<"\n\t\tDeposit History \n";
    }
    cout<<"history";
    for(int i=1;i<=7;i++){
        cout<<"\tDay"<<i;
    }
    cout<<endl;
    for(int i=0;i<4;i++){
            cout<<"week"<<i+1;
        for(int j=0;j<7;j++){
            cout<< "\t"<<data[i][j];
        }
    cout<<endl;
    }
}
void populateTransactions(int**data){
for(int i=0;i<4;i++){
    for(int j=0;j<7;j++){
        data[i][j]=rand()%100;
    }
}
}
//function for user to check transaction history
void transaction_history(string* name){
    cout<<"\nPress 1 For Last 7 Days ";
    cout<<"\nPress 2 For Last 30 Days ";
    int option;
    do{
        cin>>option;
        if(option!=1 && option!=2){
            cout<<"\nInvalid Choice. TRY AGAIN";
        }
    }while(option!=1 && option!=2);
    int days=7;
    int weeks=4;
    int** data= new int*[weeks];
    for(int i=0;i<weeks;i++){
        data[i]=new int[days];
    }
    populateTransactions(data);
    switch(option){
case 1:
    displaySevenDayHistory(data,name);
    break;
case 2:
    displayMonthHistory(data);
    break;
    }
for (int i = 0; i < weeks; i++) {
    delete[] data[i];
}
delete[] data;

}
//structure for admin login
struct admin_log_check{
string acc_ID;
int PIN;
};
//Admin Login Check Function
bool admin_login(string* name){
admin_log_check myLogin, temp;
ifstream myfile("admin login.txt");
if(!myfile.is_open()){
    cout<<"\n FILE NOT FOUND\n";
    return false;
}
for(int i=1;i<=3;i++){

  cout<<"\nEnter Your Account ID\n";
  cin>>myLogin.acc_ID;
  cout<<"\nEnter Your Account PIN\n";
  cin>>myLogin.PIN;
  myfile.clear();
  myfile.seekg(0, ios::beg);
  while(myfile>>temp.acc_ID>>temp.PIN){
    if(temp.acc_ID==myLogin.acc_ID && temp.PIN==myLogin.PIN){
        *name=myLogin.acc_ID;
        return true;
    }
  }
   cout<<"\nincorrect ID or Password. TRY AGAIN \n";
}
myfile.close();
return false;
}
//function that lets the admin to check total balance;
void check_total_balance(vector<int> &bankBalance){
ifstream myfile("login.txt");
if(!myfile.is_open()){
    cout<<"\nFile Not Found";
    return;
}
read temp;
while(myfile >> temp.id >>temp.password >> temp.balance){
    bankBalance.push_back(temp.balance);
}
int total=0;
int mySize=bankBalance.size();
for(int i=0;i<mySize;i++){
   total+=bankBalance[i];
}
cout<<"\nThe Total Balance in The Bank is "<<total;
}
struct adminLoan{
int total;
int months;
int monthlyPayment;
};
//function that lets admin view all the loans approved
void loan_records(){
    adminLoan temp;
    string status;
cout<<"\nLoan Report\n";
ifstream myfile("loan record.txt");
cout<<"Total\tMonths\tMonthlyPayment   status\n";
while(myfile>>temp.total>>temp.months>>temp.monthlyPayment >> status){
    cout<<"\n" <<temp.total<<"\t"<< temp.months<<"\t"<<temp.monthlyPayment<<"\t\t"<<status;
}
}
//check registered users
void registered_users(read* myRead){
    cout<<"\nRecord Of Registered Users\n";
    cout<<"Name"<<setw(15)<<"\tPassword\n";
    int i;
    for(i=0;i<size_function();i++){
        cout<<left<<setw(15)<<myRead[i].id<<setw(15)<<myRead[i].password<<endl;
    }cout<<"\nTotal Registered Users: "<<i;
}
//Admin menu function
int admin_menu(int* action){
    int choice;
cout<<"\n----------------------------------------------------------------------------\n";

cout<<"\nPress 1 To Check Balance in Bank ";
cout<<"\nPress 2 To Check Loan Records ";
cout<<"\nPress 3 To Check House Lease Records ";
cout<<"\nPress 4 To Check Car Lease Records ";
cout<<"\nPress 5 To Check All Registered Accounts ";
cout<<"\nPress 6 To Exit \n";
do{
    cin>>choice;
}while(!choice>6&&!choice<1);
*action=choice;
return choice;
}

struct card
{
	string name;
	long long cnic;
	long long phone_no;
	string adress;
};
//function to generate card number
void cardno() {
	long long int accno=0 ;
	srand(time(0));
	for (int i = 0; i < 12; i++) {


		int random = rand() % 1000 + 100;
		accno = accno * 10 + random;
	}
	cout <<"\n Your Card Number is: "<< accno;
}
//function to apply for a new card
void appforcard() {
	int choice;
		cout << " Enter the following informations to apply for card :\n";
		cout << "\n";
		struct card client1;
		cout << " enter your full name\n";
		cout << "\n";
		cin.ignore();
		getline(cin, client1.name);
		cout << " enter your cnic number\n";
		cout << "\n";
		cin >> client1.cnic;
		cout << " enter your mobile phone number\n";
		cout << "\n";
		cin >> client1.phone_no;
		cout << " enter your home adress\n ";
		cout << "\n";
		cin.ignore();
		getline(cin, client1.adress);
		cout << " Your data is received succesfully\n";
		cout << "\n";
		cout << " Which card do you want for your bank account\n";
		cout << "\n";
		cout << "1: visa card\n";
		cout << "2: master card\n";
		cout << "3: gold debit card\n";
		cout << "4: platinium debit card\n";
		cout << "5: silver debit card\n ";
		do {


			cin >> choice;
			switch (choice) {
			case 1:
				cout << " You have applied for visa card succesfully.\n";
				cout << "\n";
				cout << " you will receive your card at " << client1.adress << " within one monthe\n";
				cout << " thanks for trusting us :)\n";
				break;
			case 2:
				cout << " You have applied for master card succesfully.\n";
				cout << "\n";
				cout << " you will receive your card at " << client1.adress << " within one month\n";
				cout << " thanks for trusting us :)\n";
				break;
			case 3:
				cout << " You have applied for gold debit  card succesfully.\n";
				cout << "\n";
				cout << " you will receive your card at " << client1.adress << " within one month\n";
				cout << " thanks for trusting us :)\n";
				break;
			case 4:
				cout << " You have applied for platinium debit card succesfully.\n";
				cout << "\n";
				cout << " you will receive your card at " << client1.adress << " within one month\n";
				cout << " thanks for trusting us :)\n";
				break;
			case 5:
				cout << " You have applied for silver card succesfully.\n";
				cout << "\n";
				cout << " you will receive your card at " << client1.adress << " within one month\n";
				cout << " Thanks dear "<<client1.name<<" for  trusting us : )\n";
				break;

			}
			if (choice < 1 || choice >5)
				cout << " you enter invalid number choose number from 1-5 and try again\n";
			continue;
		}
		while (choice!=1 && choice !=2&& choice != 3 && choice != 4 && choice != 5 );
		ofstream myfile;
		myfile.open("cardinfo.txt",ios::app);
		myfile <<client1.name <<" " << client1.cnic <<" "<< client1.phone_no <<" "<<client1.adress<<endl;
        cardno();
		myfile.close();


}

//Main Function
int main(){
    srand(time(0));
cout<<"WELCOME TO THE BANK MANAGEMENT SYSTEM\n";
cout<<"Enter 1 To Login\n";
cout<<"Enter 2 To Create New Account\n";
cout<<"Enter 3 To Access Admin Account\n";
int* action=new int;
int choice;
vector<int> bankBalance;
  do{
  cin>>choice;
    if(choice!=1&&choice!=2 && choice!=3){
        cout<<"\nInvalid Choice Enter Again\n";
    }
   }while(choice!=1&& choice!=2&& choice!=3);
   string* name=new string;
   read* myRead=new read[size_function()];
   Read_File(myRead);

switch(choice){
case 1:
    if(login(name)){
        cout<<"\nWelcome "<<*name <<"\n";
        break;
    }
    else{
        cout<<"\nFailed to Login\nACOUNT SUSPENDED DUE TO SUSPICIOUS ACTIVITIES";
        return -1;
    }
case 2:
    create_account(myRead);
    break;
case 3:
    if(admin_login(name)){
         cout<<"\nAdmin "<<*name <<"\n";
         cout<<"\n\t\tWELCOME TO THE ADMIN ACCOUNT\n";
        break;
    }
     else{
        cout<<"\nFailed to Login\nACOUNT SUSPENDED DUE TO SUSPICIOUS ACTIVITIES";
        return -1;
   }
}
switch(choice){
case 1:
case 2:

do{
cout<<"\n----------------------------------------------------------------------------\n";

switch(menu(action)){
    case 1:
        cash_withdraw(name ,myRead);
        break;
    case 2:
         cash_deposit(name, myRead);
         break;
    case 3:
        apply_loan();
        break;
    case 4:
        car_lease_function(name);
        break;
    case 5:
        house_lease_function(name);
        break;
    case 6:
        check_balance(myRead,name);
        break;
    case 7:
        transaction_history(name);
        break;
    case 8:
        appforcard();
        break;
    case 9:
        break;
}

}while(*action!=9);
break;
    case 3:
do{
switch(admin_menu(action)){
  case 1:
    check_total_balance(bankBalance);
    break;
  case 2:
    loan_records();
     break;
  case 3:
      house_lease_records();
    break;
  case 4:
    car_lease_records();
    break;
  case 5:
    registered_users(myRead);
    break;

}
}while(*action!=6);
        break;
}
cout<<" \nTHANK YOU FOR USING OUR SYSTEM ";
delete[] myRead;
delete name;
delete action;
}

