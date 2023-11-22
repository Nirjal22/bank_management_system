 #include<iostream>
 #include<conio.h>
 //<conio.h> is used to use the getch() which helps us to get or input only one character
 #include<windows.h>
 // <windows.h> is used to use the function cls which will clear the screen
 #include<fstream>
 //File handling
 using namespace std;
 int count=0;
  struct person{
	    	string name,ID,address; // Name, account number and address
	    	int contact,cash; // contact details and the total amount of money of the specific account holder
		}person[20];
class Bank{
	private:
	    int total; //  Total numbers of bank accounts in that bank
	    string id;
	public:
		Bank(){
			total=0;        // total account in bank
		}
		void choice();
		void perData();
		void show();  //Member functions
		void update();
		void search();
		void transactions();
		void del();
		void storeData(){
		ofstream fout;
		fout.open("myfile.dat",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		}
		void viewAllData(){
		ifstream fin;
		fin.open("myfile.dat",ios::in|ios::binary);
		if(!fin)
            cout<<"\n Can't found the data";
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){fin.read((char*)this,sizeof(*this));
            }
        }
		}
};
class hp{
	private:
	    int total; //  Total numbers of bank accounts in that bank
	    string id;
	public:
		hp(){
			total=0;        // total account in bank
		}
		void forms();
		void per();
		void see();  //Member functions
		void post();
		void find();
		void withdraw();
		void remove();
		void store(){
		ofstream fout;
		fout.open("myfile.txt",ios::app|ios::binary);
		fout.write((char*)this,sizeof(*this));
		fout.close();
		}
		void view(){
		ifstream fin;
		fin.open("myfile.txt",ios::in|ios::binary);
		if(!fin)
            cout<<"\n Can't found the data";
        else{
            fin.read((char*)this,sizeof(*this));
            while(!fin.eof()){fin.read((char*)this,sizeof(*this));
            }
        }
		}
};


int main(){
    char choice;
    cout<<" 1. For saving account: "<<endl;
    cout<< " 2. For current account:"<<endl;
    choice = getch();
    Bank b;//object of class bank
    b.storeData();
    b.viewAllData();
    hp h; //object of class hp
    h.store();
    h.view();
    system("CLS"); //to clear the screen
    switch(choice){
          case '1':
            h.forms();
            break;
          case '2':
            b.choice();
            break;
    }
    return 0;}
void Bank::choice(){
	char ch;
	while(1){
	cout<<"\n\nPRESS..!!"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. View customers list"<<endl;
	cout<<"3. Update information of existing account"<<endl;
	cout<<"4. Check the details of an existing account"<<endl;
	cout<<"5. For transactions"<<endl;
	cout<<"6. Remove existing account"<<endl;
	cout<<"7. Exit"<<endl;
	ch=getch(); // to get only one input
	system("CLS"); // To clear the screen
	switch(ch){
		case '1':
			Bank::perData();
			break;
		case '2':
			if(total==0){
				cout<<"No data is entered"<<endl;
			}else{
			Bank::show();
		   }
			break;
		case '3':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			Bank::update();
			break;
		case '4':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			Bank::search();
			break;
		case '5':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			Bank::transactions();
			break;
		case '6':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			Bank::del();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout<<"Invalid input"<<endl;
			break;
	}
    }
}
void Bank::perData(){
	cout<<"Enter data of person "<<total+1<<endl;
	cout<<"Enter name: ";
	cin>>person[total].name;
	cout<<"ID: ";
	cin>>person[total].ID;
	cout<<"Address: ";
	cin>>person[total].address;
	cout<<"Contact: ";
	cin>>person[total].contact;
	cout<<"Total Cash: ";
	cin>>person[total].cash;
	total++;
}
void Bank::show(){
	for(int i=0;i<total;i++){
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
	}
}
void Bank::update(){
	cout<<"Enter id of account those data you want to update"<<endl;
	cin>>id;
	for(int i=0;i<total;i++){
		if(id==person[i].ID){
		cout<<"Previous data"<<endl;
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		cout<<"\nEnter new data"<<endl;
		cout<<"Enter name: ";
	cin>>person[i].name;
	cout<<"ID: ";
	cin>>person[i].ID;
	cout<<"Address: ";
	cin>>person[i].address;
	cout<<"Contact: ";
	cin>>person[i].contact;
	cout<<"Total Cash: ";
	cin>>person[i].cash;
	break;
		}
		if(i==total-1){
			cout<<"No such record found"<<endl;
		}
	}
}
void Bank::search(){
cout<<"Enter id of student those data you want to search"<<endl;
cin>>id;
for(int i=0;i<total;i++){
	if(id==person[i].ID){
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		break;
	}
	if(i==total-1){
		cout<<"No such record found"<<endl;
	}
}
}
void Bank::transactions(){
	int cash;
    bool valid_transaction = true;
	char ch;
	cout<<"Enter id of student those data you want to transaction"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
     	if(id==person[i].ID){
     		cout<<"Name: "<<person[i].name<<endl;
     	     cout<<"Address: "<<person[i].address<<endl;
		     cout<<"Contact: "<<person[i].contact<<endl;
		     cout<<"\nExisting Cash "<<person[i].cash<<endl;
		     cout<<"Press 1 to deposit"<<endl;
		     cout<<"Press 2 to withdraw"<<endl;
		     ch=getch();
		     switch(ch){
		     	case '1':
		     		cout<<"How much cash you want to deposit??"<<endl;
		     		cin>>cash;
		     		person[i].cash += cash;
		     		cout<<"Your new cash is "<<person[i].cash<<endl;
		     		break;
		     	case '2':
		     		do{
                        cout<<"How much cash you want to withdraw??"<<endl;
                        cin>>cash;
                        if(cash>person[i].cash){
                            valid_transaction = false;
                            cout<<"Your existing cash is just "<<person[i].cash<<endl;
                            Sleep(3000);
                         }
                        else valid_transaction;
		     		}while(!valid_transaction);
                     person[i].cash-=cash;
                     cout<<"Your new cash is "<<person[i].cash<<endl;
					 break;
				default:
					cout<<"Invalid input"<<endl;
					break;
			 }
			 break;
		 }
		 if(i==total-1){
		 	cout<<"No such record found"<<endl;
		 }
	 }
}
void Bank::del(){
	char ch;
	cout<<"Press 1 to remove specific record"<<endl;
	cout<<"Press 2 to remove full record"<<endl;
	ch=getch();
	switch(ch){
		case '1':
	cout<<"Enter id of student those data you want to remove"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
     	if(id==person[i].ID){
     		for(int j=i;j<total;j++){
     		person[j].name=person[j+1].name;
     		person[j].ID=person[j+1].ID;
     		person[j].address=person[j+1].address;
     		person[j].contact=person[j+1].contact;
     		person[j].cash=person[j+1].cash;
     		total--;
     		cout<<"Your required data is deleted"<<endl;
     		break;
			 }
		 }
		 if(i=total-1){
		cout<<"No such record found"<<endl;
		 }
	 }
	 break;
	 case '2':
	 	total=0;
	 	cout<<"All record is deleted"<<endl;
	 	break;
	default:
		cout<<"Invalid Input"<<endl;
		break;
	}
}
void hp::forms(){
	char ch;
	while(1){
	cout<<"\n\nPRESS..!!"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. View customers list"<<endl;
	cout<<"3. Update information of existing account"<<endl;
	cout<<"4. Check the details of an existing account"<<endl;
	cout<<"5. For transactions"<<endl;
	cout<<"6. Remove existing account"<<endl;
	cout<<"7. Exit"<<endl;
	ch=getch(); // to get only one input
	system("CLS"); // To clear the screen
	switch(ch){
		case '1':
			hp::per();
			break;
		case '2':
			if(total==0){
				cout<<"No data is entered"<<endl;
			}else{
			hp::see();
		   }
			break;
		case '3':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			hp::post();
			break;
		case '4':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			hp::find();
			break;
		case '5':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			hp::withdraw();
			break;
		case '6':
			if(total==0)
			cout<<"No data is entered"<<endl;
			else
			hp::remove();
			break;
		case '7':
			exit(0);
			break;
		default:
			cout<<"Invalid input"<<endl;
			break;
	}
    }
}
void hp::per(){
	cout<<"Enter data of person "<<total+1<<endl;
	cout<<"Enter name: ";
	cin>>person[total].name;
	cout<<"ID: ";
	cin>>person[total].ID;
	cout<<"Address: ";
	cin>>person[total].address;
	cout<<"Contact: ";
	cin>>person[total].contact;
	cout<<"Total Cash: ";
	cin>>person[total].cash;
	total++;
}
void hp::see(){
	for(int i=0;i<total;i++){
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
	}
}
void hp::post(){
	cout<<"Enter id of account those data you want to update"<<endl;
	cin>>id;
	for(int i=0;i<total;i++){
		if(id==person[i].ID){
		cout<<"Previous data"<<endl;
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		cout<<"\nEnter new data"<<endl;
		cout<<"Enter name: ";
	cin>>person[i].name;
	cout<<"ID: ";
	cin>>person[i].ID;
	cout<<"Address: ";
	cin>>person[i].address;
	cout<<"Contact: ";
	cin>>person[i].contact;
	cout<<"Total Cash: ";
	cin>>person[i].cash;
	break;
		}
		if(i==total-1){
			cout<<"No such record found"<<endl;
		}
	}
}
void hp::find(){
cout<<"Enter id of student those data you want to search"<<endl;
cin>>id;
for(int i=0;i<total;i++){
	if(id==person[i].ID){
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		break;
	}
	if(i==total-1){
		cout<<"No such record found"<<endl;
	}
}
}
void hp::withdraw(){
	int cash;
    bool valid_transaction = true;
	char ch;
	cout<<"Enter id of student those data you want to transaction"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
     	if(id==person[i].ID){
     		cout<<"Name: "<<person[i].name<<endl;
     	     cout<<"Address: "<<person[i].address<<endl;
		     cout<<"Contact: "<<person[i].contact<<endl;
		     cout<<"\nExisting Cash "<<person[i].cash<<endl;
		     cout<<"Press 1 to deposit"<<endl;
		     cout<<"Press 2 to withdraw"<<endl;
		     ch=getch();
		     switch(ch){
		     	case '1':
		     		cout<<"How much cash you want to deposit??"<<endl;
		     		cin>>cash;
		     		if (person[i].cash<=0){
                            person[i].cash = person[i].cash -15;
                    cout<<"Some amount deducted as a service charge"<<person[i].cash<<endl;
                     }
		     		person[i].cash += cash;
		     		cout<<"Your new cash is "<<person[i].cash<<endl;
		     		break;
		     	case '2':
		     	    if (person[i].cash>= 25){
                            cout<<"Active account"<<endl;
		     		do{
                        cout<<"How much cash you want to withdraw??"<<endl;
                        cin>>cash;
                        if(cash>person[i].cash){
                            valid_transaction = false;
                            cout<<"Your existing cash is just "<<person[i].cash<<endl;
                            Sleep(3000);
                         }
                        else valid_transaction;
		     		}while(!valid_transaction);
                     person[i].cash-=cash;
                     count++;
                     if(count>3){
                        person[i].cash=person[i].cash-1;
                     }
                     cout<<"Your new cash is "<<person[i].cash<<endl;}
                     if (person[i].cash<=0){
                            person[i].cash = person[i].cash -15;
                    cout<<"Some amount deducted as a service charge"<<person[i].cash<<endl;
                    cout<<"Please deposit the money"<<endl;
                    cout<<"Click-5 for deposit"<<endl;
                     }
                    else{ cout<<"Inactive account"<<endl;}
                    break;
				default:
					cout<<"Invalid input"<<endl;
					break;
			 }
			 break;
		 }
		 if(i==total-1){
		 	cout<<"No such record found"<<endl;
		 }
	 }
}
void hp::remove(){
	char ch;
	cout<<"Press 1 to remove specific record"<<endl;
	cout<<"Press 2 to remove full record"<<endl;
	ch=getch();
	switch(ch){
		case '1':
	cout<<"Enter id of student those data you want to remove"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
     	if(id==person[i].ID){
     		for(int j=i;j<total;j++){
     		person[j].name=person[j+1].name;
     		person[j].ID=person[j+1].ID;
     		person[j].address=person[j+1].address;
     		person[j].contact=person[j+1].contact;
     		person[j].cash=person[j+1].cash;
     		total--;
     		cout<<"Your required data is deleted"<<endl;
     		break;
			 }
		 }
		 if(i=total-1){
		cout<<"No such record found"<<endl;
		 }
	 }
	 break;
	 case '2':
	 	total=0;
	 	cout<<"All record is deleted"<<endl;
	 	break;
	default:
		cout<<"Invalid Input"<<endl;
		break;
	}
}

