#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<conio.h>
#include<iomanip>

using namespace std;

const int MAX_BOOK_ID = 13;
const int DATA_SIZE = 11;
const int MAX_COPY_NUMBER = 17;
const int MAX_BOOKS = 200;
const int MAX_CATEGORIES =30;
const int MAX_BOOK_NAME = 60;
const int MAX_CATEGORY_NAME = 20;
const int MAX_CATEGORY_NUMBER = 4;

bool isValidBookId(char bookId[])
{
	bool result;
	int i=0;
	
	if(int ((bookId[3])==45) && int (bookId[6]==45))
		result=true;
	
	else
		result=false;
	
	if(int ((bookId[4])>=65) && int ((bookId[4])<=90) &&  int ((bookId[5])>=65) && int ((bookId[5])<=90))
		result=true;
	
	else
		result=false;
	
	for(int i=0; i<3; i++)
	{
		if(int ((bookId[i])>=48) && int ((bookId[i])<=57))
			result=true;
			
		else
			result=false;	
	}
	

	for(int i=7; i<=12; i++)
	{
		if(int ((bookId[i])>=48) && int ((bookId[i])<=57))
			result=true;
			
		else
			result=false;	
	}
	
	return result;
}

bool isValidBookName(char bookName[])
{
	bool result;
	for(int i=0; i<=60; i++)
	{
		if(int ((bookName[i])>=65) && int ((bookName[i])<=90))
			result=true;
			
		else
			result=false;
	}
			
	for(int i=0; i<=60; i++)
	{		
		if(int ((bookName[i])>=97) && int ((bookName[i])<=122))
			result=true;	
			
		else
			result=false;
	}
			
	for(int i=0; i<=60; i++)
	{	
		if(int ((bookName[i])==44))
			result=true;
		
			else if(int ((bookName[i])==44) && int ((bookName[i+1])==44))
				result=false;
	}
				
	for(int i=0; i<=60; i++)
	{	
		if(int ((bookName[i])==32))
			result=true;
			
			else if(int ((bookName[i])==32) && int ((bookName[i+1])==32))
				result=false;
	}
		
	for(int i=0; i<=60; i++)
	{	
		if(int ((bookName[i])==58))
			result=true;
			
			else if(int ((bookName[i])==58) && int ((bookName[i+1])==58))
				result=false;							
	}
		
	return result;

}

bool isValidCopyNumber(char bookCopy[])
{
	bool result;
	
	if(int ((bookCopy[3])==45) && int ((bookCopy[6])==45))
		result=true;
	
	else
		result=false;
	
	if(int ((bookCopy[4])>=65) && int ((bookCopy[5])<=90))
		result=true;
	
	else
		result=false;
	
	for(int i=0; i<3; i++)
	{
		if(int ((bookCopy[i])>=48) && int ((bookCopy[i])<=57))
			result=true;
			
		else
			result=false;	
	}
	
	for(int i=7; i<=11; i++)
	{
		if(int ((bookCopy[i])>=48) && int ((bookCopy[i])<=57))
			result=true;
			
		else
			result=false;	
	}
	
	if(int (bookCopy[12])==35)
		result=true;
		
	else
		result=false;	
	
	for(int i=13; i<16; i++)
	{
		if(int ((bookCopy[13])==0) && int ((bookCopy[14])>=48) && int ((bookCopy[14])<=49) && int ((bookCopy[15])>=48) && int ((bookCopy[15])<=57))
			result=true;
			
		else
			result=false;
	}
	
	return result;
}

bool isValidCategoryName(char bookCategory[])
{
	bool result;
	
	if(int (bookCategory[16])>=65 && int (bookCategory[16])<=90)
		result=true;
		
	else
		result=false;
		
	if(int (bookCategory[16])>=97 && int (bookCategory[16]<=122))
		result=true;
		
	else
		result=false;
	
	return result;				
}

bool isValidCategoryNumber(char bookCategory[])
{
	bool result;
	
	for(int i=0; i<3; i++)
	{
		if(int (bookCategory[i])>=48 && int (bookCategory[i])<=57)
			result=true;
			
		else
			result=false;	
	}
	
	return result;
}

bool AddCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], 
				int ArraySize, char newCategoryId[], char newCategoryName[])
{
	bool result;
	
	for(int i=0;i<=MAX_CATEGORIES;i++)
	{
		for(int j=0;j<=MAX_CATEGORY_NUMBER;j++)
		{
			if(CatergoryNo[i][j]=newCategoryId[j])
				result=true;		
		}
	}
	
	for(int i=0;i<MAX_CATEGORIES;i++)
	{
		for(int j=0;j<MAX_CATEGORY_NAME;j++)
		{
			if(	CatergoryName[i][j]	= newCategoryName[j])
				result=true;
		}
		
	}

return result;

}

bool UpdateCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], 
				int ArraySize, char prevCategoryId[], char newCategoryId[], char newCategoryName[])
{
	bool result;
				
	for ( int i = 0; i < ArraySize; i++)
	{
		if ( strcmp(newCategoryId,prevCategoryId))
		{
			strcpy ( prevCategoryId, newCategoryId);
		break;
		
		}
		
		result=true;
	
	}
	
	for(int i=0;i<DATA_SIZE;i++)
	{
		newCategoryId[i];
		if(isValidCategoryNumber(newCategoryId)==true)
			result=true;
	
		else
			result=false;
	}

return result;

}

bool DeleteCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char CategoryId[])
{
	bool result;

	for(int i=0;i<=ArraySize;i++)
	{	
		result=true;                                                                                                                                                                      
		
		for(int j=0;j<=MAX_BOOK_ID;j++)
		{
			if(isValidCategoryNumber(CategoryId)==false)
			{	
				result=false;
				break;
			}
		}
	
	}
		
return result;

}
		
bool AddBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char
			newBookId[], char newBookName[], int edition)
{
	bool result;
	
	for(int i =0;i<=ArraySize;i++)
	{
		if(BookId[i][0] == '-')
		{
			strcpy ( BookId[i], newBookId);
			strcpy ( CatergoryName[i], newBookName);
			Editions[i]=edition;
			break;
		}
		
		result=true;
	
	}	

return result;
		
}

bool SaveBooks(char BookId[][MAX_BOOK_ID],char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char filename[])
{
	bool result;
	
	for(int i=0;i<=ArraySize;i++)
	{
		for(int j=0;j<=MAX_BOOK_ID;j++)
		{
			cout<<BookId[i][j];
		}
			result=true;
	}

return result;

}

bool LoadBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char filename[])
{	
	int n;
	char id[MAX_BOOK_ID];
	char name[MAX_BOOK_NAME];
	int i=0;
			
	cout<<"Book ID";
	for(int i=1;i<=1;i++)
	{	
		
		for(int j=0;j<=MAX_BOOK_ID;j++)
		{
			cout<<BookId[i][j];
		}
	
	}
	
	cout<<"edition";
			cout<<(Editions[1]);
	
	cout<<"Book Name";	
	for(int i=1;i<=1;i++)
	{	
		for(int j=0;j<=MAX_BOOK_NAME;j++)
		{
			cout<<(CatergoryName[i][j]);
		
		}
		
		cout<<endl;
	}
	
}
	
void PrintBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize)
{
	cout<<setw(20)<<"Book Id"<<setw(20)<<"Book Name"<<setw(20)<<"Edition"<<endl;
		
		for(int i=0;i<=MAX_CATEGORIES;i++)
		{	
			for(int j=0;j<=MAX_BOOK_NAME;j++)
			{
				cout<<CatergoryName[i][j];
				
			}
		
		cout<<endl;
	}
		
	for(int i=0;i<=ArraySize;i++)
	{	
		if(CatergoryName[i][0] != '-')
		{
			cout<<setw(20)<<BookId[i];
			cout<<setw(20)<<CatergoryName[i];
			cout<<setw(20)<<Editions[i];
			
		}
			cout<<endl;
	}
	
	//Book ID
		cout<<setw(10);
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=MAX_BOOK_ID;j++)
			{
				cout<<BookId[i][j];
			}
		}
		
	//Book Name
		cout<<setw(10);
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=MAX_BOOK_NAME;j++)
			{
				cout<<CatergoryName[i][j];
			}
		}
		
	//Book Edition
		cout<<setw(10);
		for(int i=0;i<=1;i++)
		{
			if(Editions[i]!=0)
				cout<<Editions[i];
		}
				
		cout<<endl;

}

int main()
{
	char book[9] = {'B','o','o','k','s','.','t','x','t'};
	char category[12] = {'c','a','t','e','g','o','r','y','.','t','x','t'};
	
	int ArraySize =50;
	char BookId[ArraySize][MAX_BOOK_ID];
	char BookName[ArraySize][MAX_BOOK_NAME];
	int Editions[ArraySize];
	char newBookId[MAX_BOOK_ID];
	char newBookName[MAX_BOOK_NAME];
	int edition;
	char prevBookId[MAX_BOOK_ID];
	
	for(int i=0;i<=50;i++)
	{
		for(int j=0;j<=MAX_BOOK_ID;j++)
		{
			BookId[i][j] = '-';
		}
	}
	for(int i=0;i<=50;i++)
	{
		for(int j=0;j<=MAX_BOOK_NAME;j++)
		{
			BookName[i][j] = '-';
		}
	}
	
	for(int i=0;i<=50;i++)
	{
			Editions[i] = 0;
	}
	
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=MAX_BOOK_ID;j++)
		{
			cout<<BookId[i][j];
		
		}
	}
	
	char option[2];
	cout<<"** Welcome to University Library Management System **"<<endl;
	cout<<"Choose the following option"<<endl;
	cout<<setw(5)<<left<<"1"<<"Category Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"2"<<"Books Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"3"<<"Book Copies Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"0"<<"Exit Program(0E)"<<endl;
	cout<<endl<<"Choose the option:";
	
	cin>>option;
	
	switch(option[0])
	{
		case '1':
			if(option[1]='A')
			{
				cout<<"Enter the details of category(Id Name) :";
				
			}
			break;
		case '2':
			if(option[1]=='A')
			{
				cout<<"Enter the details of the book(Id Edition Name) :";
				cin>>newBookId;
				cin>>edition;
				cin>>newBookName;
				
				cout<<"Book id :"<<newBookId<<endl;
				cout<<"Book Edition : "<<edition<<endl;
				cout<<"New Book Name :"<<newBookName<<endl;
				
				if(isValidBookId(newBookId)==false)
					cout<<" Not valid book id"<<endl;
				
				
				if(isValidBookName(newBookName)==false)
					cout<<"Not valid book name :"<<endl;

			}
			
			break;
	}
			LoadBooks(BookId,BookName,Editions,ArraySize,book);
	
	
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=MAX_BOOK_ID;j++)
		{
			cout<<BookId[i][j];
			
		}
	}
	
	cout<<"** Welcome to University Library Management System **"<<endl;
	cout<<"Choose the following option"<<endl;
	cout<<setw(5)<<left<<"1"<<"Category Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"2"<<"Books Management(A,E,L,D"<<endl;
	cout<<setw(5)<<"3"<<"Book Copies Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"0"<<"Exit Program(0E)"<<endl;
	cout<<endl<<"Choose the option:";
	
	cin>>option;
	
	switch(option[0])
	{
		case '1':
			
			break;
		case '2':
			
			if(option[1]=='A')
			{
				
				cout<<"Enter the details of the book(Id Edition Name) :";
				cin>>newBookId;
				cin>>edition;
				cin>>newBookName;
				
				
				cout<<"Book id :"<<newBookId<<endl;
				cout<<"Book Edition : "<<edition<<endl;
				cout<<"New Book Name :"<<newBookName<<endl;
				if(isValidBookId(newBookId)==false)
				{
				
					cout<<" Not valid book id"<<endl;
				
				}
				
				if(isValidBookName(newBookName)==false)
				{
					cout<<"Not valid book name :"<<endl;
				}
				
				bool check = AddBook(BookId,BookName,Editions,ArraySize,newBookId,newBookName,edition);
				
				if(check)
					cout<<"Book Has been added successfully  ";
				else 
					cout<<"Book cannot be added"<<endl;
					
				
			}
			
			if(option[1]=='E')
			{
				cout<<"Enter the Book Id to Edit :";
				cin>>prevBookId;
				
				cout<<"Enter the new details of the Book";
				cin>>newBookId;
				cin>>edition;
				cin>>newBookName;
				
				if(isValidBookId(newBookId)==false)
					cout<<" Not valid book id"<<endl;
				
				if(isValidBookName(newBookName)==false)
					cout<<"Not valid book name"<<endl;
				
				if(isValidBookName(newBookName)==true && isValidBookId(newBookId)==true)
					cout<<"Book Has been updated successfully  ";
				else 
					cout<<"Book cannot be added";
				
			}
			
			if(option[1]=='L')
			{
				PrintBooks(BookId,BookName,Editions,ArraySize);	
			}
			
			break;
		case '3':
			
			break;
		
		case '0':
			
			break;
	
	}
	
	SaveBooks(BookId,BookName,Editions,ArraySize,book);
	
	return 0;
	
}
	


