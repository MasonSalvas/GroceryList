// grocery list.cpp : Defines the entry point for the console application.
//

//CS217 Data Struct & Algo I
//Oct 31, 2013
//in-class lab
//test driver for linked list 


#include "stdafx.h"
#include <fstream>
#include "linkedlist.h"
#include <conio.h>	
#include <iomanip>

using namespace std;


int main()
{
	ifstream infile;			//will allow the input of a file  
	ofstream outfile;			//will allow it to output on the file 
	bool check;					//bool used for check 
	bool test = false;			//testing bool	
	ItemType temp;				//the temp itemtype that is used thourghtout
	ItemType ar[1];				//will create 
	gList my_list;
	ItemType noob_sauce;

	double total = 0;				//calculate the total
	double tax = 0;					//calculates the tax
	const double tax_rate = 0.15;	//the constant tax rate 
	double errythang = 0;			//is the total of both tax and total price

	noob_sauce.product_number = 0;
	noob_sauce.name = " ";
	noob_sauce.tax = false;
	noob_sauce.price = 0;

	int product_num = 1;	//specifiys the product
	int amount = 0;			//how many of tht product you are getting

	infile.open("Invent.in.txt");
	outfile.open("Rec.out.txt");
	
	if(infile.fail())
	{
		cout<<"Error! file could not input.";
		exit(1);
	}

	char tch;
	while(!infile.eof())
	{
		infile>>temp.product_number;
		infile>>temp.name;
		infile>>temp.price;
		infile>>tch;
		if(tch == 'N')
			temp.tax = false;
		else
			temp.tax = true;
		my_list.insertItem(temp);
		//cout<<my_list;
	}


	outfile<<"Receipt:"<<endl;
	outfile<<"You have orderd:"<<endl<<endl;
	while(product_num != 0)
	{
		cout<<"Enter the product number: ";
		cin>>product_num;
		cout<<endl;
		cout<<"Enter how much you want: ";
		cin>>amount;
		cout<<endl;
		check = cin.fail();
		cin.clear();

		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		if(product_num == 0)
		{
			break;
		}

		if(check || amount > 100 || amount < 0)
		{
			cout<<"This is not a valid input!"<<endl;
		}

		else if(my_list.retrieveItem(product_num))
		{
			
			noob_sauce = my_list.getItem(product_num, test);

			cout<<amount<<" Product number is "<<noob_sauce.product_number<<" description is "<< noob_sauce.name<<" cost "
				<<noob_sauce.price<<" taxable "<<noob_sauce.tax<<endl;
			
			outfile<<amount<<" items were bought with the Product number of "<<noob_sauce.product_number
				<<", description is "<<noob_sauce.name<<", cost $"
				<<noob_sauce.price<<", taxable "<<noob_sauce.tax<<endl;
			
			total += noob_sauce.price * amount;
			
			if(noob_sauce.tax)
			{
				tax += (noob_sauce.price * amount) * tax_rate;
			}
		}

		else
		{
			cout<<"This is not a valid option please enter again."<<endl;
			outfile<<product_num<<" was not a valid choice. "<<endl;
		}

	}
	outfile<<setprecision(2)<<std::fixed;
	errythang = tax + total;
	outfile<<"The amount before tax is: $"<<total<<endl;
	outfile<<"Tax: $"<<tax<<endl;
	outfile<<"The total: $"<<errythang<<endl;


	infile.close();
	outfile.close();
	return 0;
}

