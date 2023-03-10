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

bool AddCategory(char CategoryNo[][MAX_CATEGORY_NUMBER],char CategoryName[][MAX_CATEGORY_NAME], 
					int ArraySize, char newCategoryId[], char newCategoryName[])
{
	
	for(int i=0; i<=ArraySize; i++)
	{
		for(int j=0; j<=MAX_CATEGORY_NUMBER; j++)
		{
			CategoryNo[i][MAX_CATEGORY_NUMBER]=newCategoryId[i];
		}
		
		for(int k=0; k<=MAX_CATEGORY_NAME; k++)
		{
			CategoryName[i][MAX_CATEGORY_NAME]=newCategoryName[i];	
		}	

	}
	
	return true;
}

bool DeleteCategory(char CategoryNo[][MAX_CATEGORY_NUMBER],char CategoryName[][MAX_CATEGORY_NAME], 
					int ArraySize, char CategoryId[])
{
	for(int i=0; i<=ArraySize; i++)
	{
		for(int j=0; j<=MAX_CATEGORY_NUMBER; j++)
		{
			if(CategoryNo[i][MAX_CATEGORY_NUMBER]==CategoryId[j])
				CategoryNo[i][MAX_CATEGORY_NUMBER]='\0';
				break;	
		}
		
		for(int k=0; k<=MAX_CATEGORY_NAME; k++)
		{
			if(CategoryNo[i][MAX_CATEGORY_NAME]==CategoryId[k])
				CategoryNo[i][MAX_CATEGORY_NAME]='\0';
				break;	
		}
	}
	
	return true;
}

bool AddBook(char BookId[][MAX_BOOK_ID],char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, 
			char newBookId[], char newBookName[], int edition)
{
	for(int i=0; i<ArraySize; i++)
	{
		for(int j=0; j<MAX_BOOK_ID; j++)
		{
			BookId[i][MAX_BOOK_ID]=newBookId[j];
		}
		
		for(int k=0; k<MAX_BOOK_NAME; k++)
		{
			CategoryName[i][MAX_BOOK_NAME]=newBookName[k];
		}
	}
	
	return true;
}

bool DeleteBook(char BookId[][MAX_BOOK_ID],char CategoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char newBookId[])
{
	for(int i=0; i<=ArraySize; i++)
	{
		for(int j=0; j<=MAX_BOOK_ID; j++)
		{
			if(BookId[i][MAX_BOOK_ID]==newBookId[j])
				BookId[i][MAX_BOOK_ID]='\0';
				break;
	 	}
		
		for(int k=0; k<=MAX_BOOK_NAME; k++)
		{
			if(CategoryName[i][MAX_BOOK_NAME]==newBookId[k])
				CategoryName[i][MAX_BOOK_NAME]='\0';
				break;
		}
	}
	
	return true;
}

bool AddBookSample (char CopyId[][MAX_COPY_NUMBER],char PublishedDates[][DATE_SIZE], int ArraySize, 
					char newCopyId[], char newPublishDate[])
{
	for(int i=0; i<ArraySize; i++)
	{
		for(int j=0; j<MAX_COPY_NUMBER; j++)
		{
			CopyId[i][MAX_COPY_NUMBER]=newCopyId[j];
		}
		
		for(int k=0; k<DATE_SIZE; k++)
		{
			PublishedDates[i][DATE_SIZE]=newPublishDate[k];
		}
	}
	
	return true;					
}

bool DeleteBookSample (char CopyId[][MAX_COPY_NUMBER],char PublishedDates[][DATE_SIZE], int ArraySize, char newCopyId[])
{
	for(int i=0; i<=ArraySize; i++)
	{
		for(int j=0; j<=MAX_COPY_NUMBER;j++)
		{
			if(CopyId[i][MAX_COPY_NUMBER]==newCopyId[j])
				CopyId[i][MAX_COPY_NUMBER]='\0';
				break;
		}
		
		for(int k=0; k<=DATE_SIZE; k++)
		{
			if(PublishedDates[i][DATE_SIZE]==newCopyId[k])
				PublishedDates[i][DATE_SIZE]='\0';
				break;
		}
	}
	
	return true;
}

int main()
{
	int arraySize =50;
	char categoryNumber[arraySize][MAX_CATEGORY_NUMBER];
	char categoryName[arraySize][MAX_CATEGORY_NAME];
	int Editions[arraySize];
	char newCategoryId[MAX_CATEGORY_NUMBER];
	char newCategoryName[MAX_CATEGORY_NAME];
	int edition;
	char prevBookId[MAX_BOOK_ID];
	char ch;
	char option;
	 
	start: 
	cout<<"** Welcome to University Library Management System ** "<<endl;
	cout<<"Choose the following option "<<endl;
	cout<<"1	Category Management(A,E,L,D) "<<endl;
	cout<<"2	Books Management(A,E,L,D) "<<endl;
	cout<<"3	Book Copies Management(A,E,L,D) "<<endl;
	cout<<"4	Exit Program(0E) "<<endl;
	
	cout<<"\n\nChoose the option "<<endl;
	cin>>ch;
	
	switch(ch)
	{
		case '1':
			cin>>option;
			
			if(option=='A')
			{
				cout<<"Enter the details of the category(Id Name) "<<endl;
				
				isValidCategoryNumber(newCategoryId);
				isValidCategoryName(newCategoryName);
				AddCategory(categoryNumber, categoryName, arraySize, newCategoryId, newCategoryName);
				
				cin>>newCategoryId;
				cin>>newCategoryName;
				
				if(isValidCategoryNumber(newCategoryId)==true && isValidCategoryName(newCategoryName)==true && AddCategory(categoryNumber, categoryName, arraySize, newCategoryId, newCategoryName)==true)
				{
					cout<<newCategoryId<<" "<<newCategoryName<<endl;
					cout<<"Category has been added successfully "<<endl;
					goto start;
				}	
					
			}
			
			if(option=='D')
			{
				cout<<"Enter the category Id to delete "<<endl;
				cin>>newCategoryId;
				cin>>newCategoryName;
				
				isValidCategoryNumber(newCategoryId);
				isValidCategoryName(newCategoryName);
				DeleteCategory(categoryNumber, categoryName, arraySize, newCategoryId);
				
				if(isValidCategoryNumber(newCategoryId)==true && isValidCategoryName(newCategoryName)==true && DeleteCategory(categoryNumber, categoryName, arraySize, newCategoryId)==true) 
				{
					cout<<"Category has been deleted successfully "<<endl;
					goto start;
				}			
			}
	}
}
