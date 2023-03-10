#include<iostream>
using namespace std;

const int MAX_BOOK_ID=13;
const int DATE_SIZE=11;
const int MAX_COPY_NUMBER=17;
const int MAX_BOOKS=200;
const int MAX_CATEGORIES=30;
const int MAX_BOOK_NAME=60;
const int MAX_CATEGORY_NAME=20;
const int MAX_CATEGORY_NUMBER=4;

//Validations
bool isValidBookId(char bookId[])
{
	for(int j=0; j<12; j++)
	{
		for(int i=0; i<3; i++)
		{
			if(int (bookId[i]>=48) && int (bookId[i]<=57))
				return true;
				
			else
				return false;		
		}
		
		if(bookId[3]==45 && bookId[6]==45)
			return true;
			
		else
			return false;	
			
		for(int i=5; i<7; i++)
		{
			if(int (bookId[i]>=65) && int (bookId[i]<=90))
				return true;
				
			else
				return false;	
		}
		
		for(int i=7; i<12; i++)
		{
			if(int (bookId[i]>=48) && int (bookId[i]<=57))
				return true;
				
			else
				return false;	
		}	
	}
	
	return true;
}

bool isValidBookName(char bookName[])
{
	for(int i=0; i<60; i++)
	{
		if(int (bookName[i]>=65) && int (bookName[i]<=90))
			return true;
			
		else 
			return false;	
	}
	
	for(int i=0; i<60; i++)
	{
		if(int (bookName[i]>=97) && int (bookName[i]<=122))
			return true;
			
		else 
			return false;	
	}
	
	for(int i=0; i<60; i++)
	{
		if(int (bookName[i]==58) && int (bookName[i]==44) && int (bookName[i]==32))
			return true;
		
		else
			return false;	
	}
	
	return true;
}

bool isValidCopyNumber(char bookCopy[])
{
	for(int j=0; j<16; j++)
	{
		for(int i=0; i<3; i++)
		{
			if(int (bookCopy[i]>=48) && int (bookCopy[i]<=57))
				return true;
				
			else
				return false;		
		}
		
		if(bookCopy[3]==45 && bookCopy[6]==45)
			return true;
			
		else
			return false;	
			
		for(int i=5; i<7; i++)
		{
			if(int (bookCopy[i]>=65) && int (bookCopy[i]<=90))
				return true;
				
			else
				return false;	
		}
		
		for(int i=7; i<12; i++)
		{
			if(int (bookCopy[i]>=48) && int (bookCopy[i]<=57))
				return true;
				
			else
				return false;	
		}
	
		if(int (bookCopy[12]==35))
			return true;
			
		else
			return false;
			
		for(int i=13; i<16; i++)
		{
			if(int (bookCopy[i]>=48) && int (bookCopy[i]<=57))
				return true;
				
			else
				return false;	
		}			
	}
	
	return true;
}

bool isValidCategoryName(char bookCategory[])
{
	for(int i=0; i<=20; i++)
	{
		if(int (bookCategory[i]>=65) && int (bookCategory[i]<=90))
				return true;
				
			else
				return false;
	}
	
	for(int i=0; i<=20; i++)
	{
		if(int (bookCategory[i]>=97) && int (bookCategory[i]<=122))
			return true;
			
		else 
			return false;
	}
	
	return true;
}

bool isValidCategoryNumber(char bookCategory[])
{
	for(int i=0; i<3; i++)
	{
		if(int (bookCategory[i]>=48) && int (bookCategory[i]<=57))
			return true;
				
		else
			return false;
	}
	
	return true;
}

int main()
{
	char a[12], b[60], c[16], d[20], e[3];
	
	cout<<"Enter the Book Id "<<endl;
	cin>>a;
	
	cout<<isValidBookId(a);
	
	cout<<"Enter the Book Name "<<endl;
	cin>>b;
	
	cout<<isValidBookName(b);
	
	cout<<"Enter the Copy Number "<<endl;
	cin>>c;
	
	cout<<isValidCopyNumber(c);
	
	cout<<"Enter the Category Name "<<endl;
	cin>>d;
	
	cout<<isValidCategoryName(d);
	
	cout<<"Enter the Category Number "<<endl;
	cin>>e;
	cout<<isValidCategoryNumber(e);
	
	return 0;
}
