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

bool AddCategory(char CategoryNo[][MAX_CATEGORY_NUMBER],char CategoryName[][MAX_CATEGORY_NAME], 
					int ArraySize, char newCategoryId[], char newCategoryName[])
{
	for(int i=0; i<=ArraySize; i++)
	{
		for(int j=0; j<=MAX_CATEGORY_NUMBER; j++)
		{
			CategoryNo[i][MAX_CATEGORY_NUMBER]=newCategoryId[j];	
		}
		
		for(int k=0; k<=MAX_CATEGORY_NAME; k++)
		{
			CategoryName[i][MAX_CATEGORY_NAME]=newCategoryName[k];
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
