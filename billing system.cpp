#include<iostream>
#include<fstream>
#include<iomanip>
#include<process.h>
using namespace std;

class shopping
{
	
	private:
		int pcode;
        float price;
		float dis;
		string pname;
		
		public:
		 void menu();
		 void administrator();
		 void buy_product();
		 void add();
		 void edit();
		 void list();
		 void receipt();
		 void rem();
		 
};

void shopping :: menu()
{
	m:
	int choice;
	string email;  
	string password;
    
    cout<<"\t\t\t\t________________________________\n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t    Supermarket  Main  Menu     \n";
    cout<<"\t\t\t\t                                \n";
    cout<<"\t\t\t\t_________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t|  1)     Administrator            |\n";
    cout<<"\t\t\t\t|                                 |\n";
    //cout<<"\t\t\t\t|  2)  Buyer                      |\n";
    cout<<"\t\t\t\t|                                 |\n";
    cout<<"\t\t\t\t|  2)  Exit                       |\n"; 
    cout<<"\t\t\t\t|                                 |\n"; 
    cout<<"\n\t\t\t   please select! ";
    cin>>choice;

	switch(choice)
	{
	    case 1:
    	    cout<<"\t\t\t Please login \n ";	
			cout<<"\t\t\t enter Email  :";
            cin>>email;          cout<<"\n";
    	    cout<<"\t\t\t enter Password : ";
    	    cin>>password;
    	    
    	    if(email=="vikash@gmail.com" && password=="vikash@123")
    	    {
    	      administrator();	
			}
    	    else 
    	    {
    	       	cout<<"invalid email/password";
			}
			break;
		
	
	
    	
	case 2:
		{
			exit(0);
			
		}
	
	default:
		{
			cout<<"please select from the given options";
			
		}
}
	
	goto m;
	
}
	
	

void shopping:: administrator()
{
	m:
      int choice;
      cout<<"\n\n\n\t\t\t  Administrator menu ";
      cout<<"\n\t\t\t______1) Add the product________|";
      cout<<"\n\t\t\t|                               |";
      cout<<"\n\t\t\t|_____2)Modify the product      |";
      cout<<"\n\t\t\t|                               |";
      cout<<"\n\t\t\t|_____3)delete the product______|";
      cout<<"\n\t\t\t|                               |";
       cout<<"\n\t\t\t|_____4)BUY PRODUCT      ______|";
      cout<<"\n\t\t\t|                               |";
      cout<<"\n\t\t\t|____5)Back to main menu________|";
      	
      	cout<<"\n\n\t please enter your choice";
      	cin>>choice;
    
      	switch(choice)
      	{
      		case 1:
      			add();
      			break;
      			 
      	    case 2:
      	    	edit();
      	    	break;
      	    	
      	    case 3:
			    rem();
				break;
				
			case 4:
            	buy_product();
	  		    break;
	  		    
			case 5:
			    menu();
				break;
					
		   	default :
			 cout<<"invalid choice!";
			 
		}
      	goto m;	
}

        void shopping:: buy_product()
 {
 	m:
    int choice;
	cout<<"\t\t\t       Product Buy         \n";
	cout<<"\t\t\t_______________\n " ;
	cout<<"                     \n  ";
	cout<<"\t\t\t 1)Buy product \n";		
	cout<<"\t\t\t 2) Go back \n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	
	switch(choice)
	{
	
	
	 case 1:
	     receipt();
	   	break;
	 case 2:
	     administrator();
	     break;
		 
     default :
     	
	   cout<<" invalid choice";
	 		   	
	
 }
 	goto m;


}		
	
	void shopping :: add()
	{
	 m:	
	 fstream data;
	 int c;
	 int token=0;
	 float p;
	 float d;
	 string n;
	 
	 cout<<"\n\n\t\t\t Add new product ";
	 cout<<"\n\n\t Product code of the product : " ;
	 cin>>pcode;
	 cout<<"\n\n\t Name of the product  ";
	 cin>>pname;
	 cout<<"\n\n\t Price of the product  ";
	 cin>>price;
	 cout<<"\n\n\t discount on product  ";
	 cin>>dis;

	 data.open("database.txt",ios::in);
	 
	 if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
		else 
		{
			data>>c>>n>>p>>d;
			
			while(!data.eof())
		{
			if(c ==pcode)
			{
				token++;
				
        	}
			
			data>>c>>n>>p>>d;
     	}
			
	     data.close();


	}
	 
	 if(token==1)
	 goto m;
	 else{
	 	data.open("database.txt",ios::app|ios::out);
	 	data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
	 	data.close();

	 }
	 		cout<<"\n\n\t\t Record inserted !";
}
	

	
	void shopping::edit()
	{
		fstream data,data1;
		int pkey;
		int token=0;
		int c;
		float p; 
		float d;
		string n;
		
		cout<<"\n\t\t\t Modify the record";
		cout<<"\n\t\t\t Product code : ";
		cin>>pkey;
		 
		 data.open("database.txt",ios::in);
		 if(!data)
		 {
		 	cout<<"\n\n File doesn't exist";
		 }
		else{
			data1.open("database1.txt", ios::app|ios::out);
			
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pkey==pcode)
	        	{
					
					cout<<"\n\t\t Product new code : ";
				cin>>c;
				cout<<"\n\t\t Name of the product : ";
				cin>>n;
				cout<<"\n\t\t price :";
				cin>>p;
				cout<<"\n\t\t discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
				
			}
			else
			{
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
		}
		data>>pcode>>pname>>price>>dis;
		}

		data.close();
		data1.close();
		
		remove("database.txt");
        rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!";
	}
	
		} 		
	}

	void shopping::rem()
	{
		
		fstream data,data1;
		int pkey;
		int token=0;
		cout<<"\n\n\t Delete product";
		cout<<"\n\n\t Product code  :  ";
		cin>>pkey;
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"file doesn't exist";
		}
		
		else{
			data1.open("database1.txt",ios::app|ios::out);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==pkey)
				{
					cout<<"\n\n\t Product deleted succesfully";
					token++;
				}
				else
				{
					data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
					
				}
				data>>pcode>>pname>>price>>dis;
	
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found";
			
		}
      }
				
 }
		
	void shopping:: list()
	{
		fstream data;
		data.open("database.txt",ios::in);
		cout<<"\n\n|_____________________________________________________\n";
		cout<<"proNo\t\tname\t\tPrice\n  ";
		cout<<"\n\n|______________________________________________________\n";
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
			
		}
		data.close();
	}
	
	void shopping::receipt()
	{
		fstream data, rec;
		
		int arrc[100];
		int arrq[100];
		char choice;
		int  c=0;
		float amount=0;
		float dis=0;
		float total=0;
		
		cout<<"\n\n\t\t\t\t RECEIPT ";
		data.open("database.txt",ios::in);
		rec.open("reciept.txt", ios::trunc|ios::out);
		if(!data)
		{
			cout<<"\n\n Empty database  ";
		}
		else 
		{
			 data.close();
			 
			 list();
			cout<<"\n_____________________________________________________\n";
			cout<<"\n|                                                     \n";
			cout<<"\n                 please place the order	          \n";
			cout<<"\n|                                                     \n";
			cout<<"\n______________________________________________________\n";
			do{
				m:
				cout<<"\n\nEnter Product code  : ";
				cin>>arrc[c];
				cout<<"\n\n Enter the Product quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c]==arrc[i])
					{
						cout<<"\n\n Duplicate product code.Please try again !";
						goto m;		
					}	
				}
                  c++;
				  cout<<"\n\n Do you want to buy another product? if yes then press y else n : ";
				  cin>>choice;	
			} 
			while(choice == 'y');
			
			cout<<"\n\n\t\t\t______________________RECEIPT________________________________\n";
			cout<<"\n Product No\t"<<"Name"<<setw(20)<<"\t Quantity"<<setw(20)<<"\tPrice\t"<<setw(20)<<"Amount\t"<<"Amount with discount\n";
			
			for(int i=0; i<c; i++)
			{
				data.open("database.txt", ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{   
					if(pcode==arrc[i])
					{
						
						amount=price*arrq[i];
						dis=amount-(amount*dis/100);
						total=total+dis;
						cout<<"\n"<<pcode<<setw(20)<<pname<<setw(20)<<arrq[i]<<setw(20)<<price<<setw(20)<<amount<<setw(20)<<dis;
						rec<<"\n"<<pcode<<setw(10)<<pname<<setw(20)<<arrq[i]<<setw(10)<<price<<setw(10)<<amount<<setw(10)<<dis<<"\n\n\t"<<setw(20); //<<"total amount : "<<total;
						
						
					}
				
					data>>pcode>>pname>>price>>dis;
				}
					{
						rec<<"total amount : "<<total;
					}	
				data.close();	
			}
			rec.close();
			system("notepad /p reciept.txt");
			
			
		}
			cout<<"\n\n____________________________________________";
			cout<<endl;
			cout<<"\n Total amount  -  :"<<total;
			cout<<endl;
			
	}
		int main()
		{
			shopping s;
			s.menu();
		}
		
    	
	
