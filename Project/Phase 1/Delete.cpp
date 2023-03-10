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
}
