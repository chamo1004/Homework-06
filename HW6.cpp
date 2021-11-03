#include <iostream>
using namespace std;

int main ()
{
	int productA=30, productB=25, productC=50, productD=40;//price of the product
	int r1=100, r2=100, r5=100, r10=100; // all reserves are pre=loaded with 100 coins
	int ofbr1=0, ofbr2=0, ofbr5=0, ofbr10=0;//number of coins in overflow bins
	int paymentr1=0, paymentr2=0, paymentr5=0, paymentr10=0;//variables which used for customer payment
	int q1,q2,q5,q10; //variables which used for number of coins
	int balancer1=0, balancer2=0, balancer5=0, balancer10=0;//variables which used for remainders
    int password=0;
    int price, selection, payment, lack, balance;
    
while ( r1!=0 || r2!=0 || r5!=0 || r10!=0){	

	cout << "Welcome, how may I help you? \n";
	cout << "............................ \n";
	cout << "\n";
	
	cout << "Product A : Enter 1 \n";
	cout << "Product B : Enter 2 \n";
	cout << "Product C : Enter 3 \n";
	cout << "Product D : Enter 4 \n";
	cout << "\n";
	
	cout << "Enter the desired Product Number :";
	cin >> selection;
	
	while (!(selection>=1 && selection<=4)){
	cout << "Invalid Product Number. Please enter a number again... \n";
	cin >> selection;
	}
	
	switch(selection)
	{
		case 1:
			cout << "Price of product A is Rs. 30 \n";
			price=productA;
			break; 
		case 2:
			cout << "Price of product B is Rs. 25 \n";
			price=productB;
			break; 
		case 3:
			cout << "Price of product C is Rs. 50 \n";
			price=productC;
			break;
		case 4:
			cout << "Price of product D is Rs. 40 \n";
			price=productD;
			break;
	}
	cout << "\n";

	
		cout << "Please enter the payment thruogh the slot (Coins Rs10, Rs5, Rs2, Rs1)... \n";
		cout << "Number of r1 coins :";
		cin >> paymentr1;
		cout << "Number of r2 coins :";
		cin >> paymentr2;
		cout << "Number of r5 coins :";
		cin >> paymentr5;
		cout << "Number of r10 coins :";
		cin >> paymentr10;
		
		payment=(paymentr1*1+paymentr2*2+paymentr5*5+paymentr10*10);
		cout << "Payment = Rs. " << payment << "\n";
		
		//number of coins in overflow bin
		ofbr1=paymentr1;
		ofbr2=paymentr2;
		ofbr5=paymentr5;
		ofbr10=paymentr10;
	
	char select;	
		if (payment<price){
		lack=price-payment;
		cout << "Lack amount = Rs. " << lack << "\n";
		cout << "If you have enough money enter Y, else N" << "\n";
		cin >> select;
		
			if (select =='N'){
				cout << "Get back your payment... \n";
				break;
			}
			
			if (select == 'Y'){
				cout << "Get back your payment and start again \n";
				cout << "..................................... \n";
			}
			
			while (!(select=='Y' || select== 'N')){
				cout << "Re-enter letter... \n";
				cin >> select;
			}
    	}
    
	    else if (payment>price){
		balance=payment-price;
		cout << "Your balance is (Rs.) :  "<< balance << "\n";
	
	    q10 = (balance/10);
		if (q10<r10){
		cout << "number of Rs.10   coins= " << q10 << "\n";
		}
	
    	balancer10 = (balance % 10);
    	q5 = (balancer10/5);
    	if (q5<r5){
		cout << "number of Rs.5    coins= " << q5 << "\n";
		}
	
    	balancer5 = (balancer10 % 5);
    	q2 = (balancer5/2);
    	if (q2<r2){
		cout << "number of Rs.2    coins= " << q2 << "\n";
		}
	
    	balancer2 = (balancer5 % 2);
		q1 = (balancer2/1);
		if (q10<r1){
		 cout << "number of Rs.1    coins= " << q1 << endl;
    	balancer1 = (balancer2 % 1);
		}
        cout << "\n";
    	
		bool canChange=1;//whether the balnce can be paid or not
        int balance2=0;
        balance2=q10*10+q5*5+q2*2+q1*1;
        
        if (balance==balance2){
        	cout << "Get your balance... \n";	
		}
    	else{
    		cout << "Out of change. Get back your payment \n";
		}
	      
        cout << "Thank You.. Come Again.. \n";
	}		
	
	
	//the coins will be deducted from the domination reserves
	r1-=q1;
	r2-=q2;
	r5-=q5;
	r10-=q10;
	
	//moves excess coins to the appropriate overflow bin
	    if (r1>100){
		ofbr1=r1-100;
	}
		if (r2>100){
		ofbr2=r2-100;
	}
		if (r5>100){
		ofbr5=r5-100;
	}
		if (r10>100){
		ofbr10=r10-100;
	}
	
	//reintialize variables with 0
	paymentr1=0, paymentr2=0, paymentr5=0, paymentr10=0;
	balancer1=0, balancer2=0, balancer5=0, balancer10=0;
	payment=0, lack=0, balance=0;
	
	password=0;//authorized password is 12345
	cout << "Enter password to terminate (Authorized people only) \n";
	cout << "If you are a customer please enter 0 as the password to continue \n";
	cout << "Enter the Password : \n";
	cin >> password;
	
	while (!(password==12345 || password==0)){
		cout << "Please re-enter the password.... \n" << "\n";
		cin >> password;
}
   	 if (password==12345){
		cout << "Program terminated by the owner... \n" << "\n";	
		cout << "Coins in each denomination reserve \n";
		cout << ".................................. \n";
		cout << "Number of coins in Rs.1 reserve : " << r1 << "\n";
		cout << "Number of coins in Rs.2 reserve : " << r2 << "\n";
		cout << "Number of coins in Rs.5 reserve : " << r5 << "\n";
		cout << "Number of coins in Rs.10 reserve : " << r10 << "\n" << "\n";
		
		cout << "Coins in each overflow bin \n";
		cout << ".................................. \n";
		cout << "Number of coins in Rs.1 overflow bin : " << ofbr1 << "\n";
		cout << "Number of coins in Rs.2 overflow bin : " << ofbr2 << "\n";
		cout << "Number of coins in Rs.5 overflow bin : " << ofbr5 << "\n";
		cout << "Number of coins in Rs.10 overflow bin : " << ofbr10 << "\n" << "\n";
		break;
    }
}
}

