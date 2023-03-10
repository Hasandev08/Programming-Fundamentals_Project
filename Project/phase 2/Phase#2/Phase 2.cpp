#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_BOOK_ID=13;
const int DATE_SIZE=11;
const int MAX_COPY_NUMBER=17;
const int MAX_BOOKS=200;
const int MAX_CATEGORIES=30;
const int MAX_BOOK_NAME=60;
const int MAX_CATEGORY_NAME=20;
const int MAX_CATEGORY_NUMBER=4;
const int MAX_STUDENT_NAME=60;
const int REGISTRATION_NUMBER=12;

struct Book
{
    char Id[MAX_BOOK_ID];
    char Name[MAX_BOOK_NAME];
    int Edition;
};

struct Catergory 
{	
	char Id[MAX_CATEGORY_NUMBER];
	char Name[MAX_CATEGORY_NAME];
};

struct Date
{
	int day;
	int month;
	int year;
};

struct BookCopy
{
 	char Id[MAX_COPY_NUMBER];
	Date PurchaseDate;
};

struct Student
{
	char RegistrationNo[REGISTRATION_NUMBER];
	char Name[MAX_STUDENT_NAME];
	int Session;
	Date AdmissionDate;
};

bool isValidBookName(char bookname[]){
int i=0;
	while(i!='\0' && i<60)
{ if ((bookname[i]<'A' || bookname[i]>'Z' ))
	{
		 if (bookname[i]!=':')
	 {
			 if(bookname[i]!='-')
			 		 {
				 if(bookname[i]!=',')
		      {if (bookname[i]!=' ')
	                   return true;

		   else if (bookname[i]==' '
		   				       ){if (bookname[i+1]==' ');
		           { return false;
			        }
									   }
				   }

		    else if(bookname[i]==',')
		    {    if(bookname[i+1]==',')

			   return false;
	}
}
		        else if(bookname[i]=='-')
	      {            if(bookname[i+1]=='-')
		                 return false;
		}
			}
                  else if(bookname[i]==';')
	                    {if (bookname[i+1]==',')
                           	{
							   return false;}
	}

	}
i++;

     }  return true;}
/*
BOOK ID VALID
*/
bool isValidBookId(char bookId[])

{
		for(int i =0;i<=2;i++){
			if(bookId[i]<'0' || bookId[i]>'9')
				return false;
		}
		if((bookId[3] != '-') || (bookId[4]<'A' || bookId[4]>'Z') || (bookId[5]<'A' || bookId[5]>'Z') || (bookId[6] != '-'))
			return false;
		for(int i =7;i<=11;i++){
			if(bookId[i]<'0' || bookId[i]>'9')
				return false;
		}
	return true;
	}
/*
Valid COPYNUMBER
*/
bool isValidCopyNumber(char bookCopy[])
{
		if(bookCopy[12] != '#')
			return false;


		for(int i=13;i<=15;i++){
			if((bookCopy[i]<'0')||(bookCopy[i]>'9'))
				return false;
		}

	return true;
		}
/*
Valid CATEGORY NUMBER
*/
bool isValidCategoryNumber(char bookCategory[])
{
    int i;
      while(bookCategory[i]!='\0' && i<4 )
	   {if(bookCategory[i]<'0' || bookCategory[i]>'9')
	       return false;
          else
          return true;
	  i++;		}
}
/*
VALID CATEGORY NAME
*/
bool isValidCategoryName(char bookCategory[])
{
	int i;
	while(bookCategory[i]!='\0' && i<20)
	{if(bookCategory[i]<'A' || bookCategory[i]>'z')
   return false;
     else
    return true;
    i++;
       }
}
/*
VALID STUDENT NAME
*/
bool isValidStudentName(char stdName[])
  {   int i;
       while(stdName[i]!='\0' && i<60)

     {
   if(stdName[i]<'A'|| stdName[i]>'Z')
      if(stdName[i]!=' ')

	    return false; }

		  return true;	}
/*
VALID REGISTRATION
*/
bool isValidRegistrationNo(char regNo[])
   {
	if(regNo[7]!='-')
		return false;
	if(regNo[4]!='-')
		return false;
	if(regNo[5]<'A' || regNo[5]>'Z')
		return false;
	if(regNo[6]<'A' || regNo[6]>'Z')
		return false;
	for(int i =8;i<=12;i++){
		if(regNo[i] == '\0')
			break;
		if(regNo[i]<'0' ||regNo[i]>'9')
			return false;
		}
		return true;
	}
	bool isValidDate(Date date)	{
	   if( date.day>31)
	    return false;
	    if( date.month>12)
	    return false;
	    if( date.year>2021 )
		return false;
	    if(date.month==2)
		{if( date.day>29)
		  return false;	}

	return true;
	}

bool addCategory(Catergory arr[], int arraySize, Catergory newCatergory)
{ 
	for(int i=0;i<arraySize;i++)
	{
	  	if(arr[i].Id[0]=='\0')
  	 	{
		 	strcpy(arr[i].Id,newCatergory.Id);
  	  		strcpy(arr[i].Name,newCatergory.Name);
  	  		break;
		}
	}
  	 
	    return true;
}

bool isExist(Catergory arr[], int arraySize, char catId[])
{
    for(int i=0;i<arraySize;i++)
    { 
		if(strcmp(arr[i].Id,catId)==0)
             return true;
	}
		
		return false; 
		
}

bool editCategory(Catergory arr[],int arraySize,char catId[],Catergory newData)
{
	for (int i = 0; i<arraySize; i++)
	{
		if (strcmp(arr[i].Id,catId)==0)
		{
			strcpy (arr[i].Id, newData.Id);
			strcpy (arr[i].Name, newData.Name);
			return true;
			break;
		}
	}
	
	return false;
}

bool deleteCategory(Catergory arr[], int arraySize, char catId[])
{
	for(int i=0;i<arraySize;i++)
  	{
     	if(strcmp(arr[i].Id,catId)==0)
        {
		  	for(int j=0;j<MAX_BOOK_ID;j++)
	        {
				arr[i].Id[j]='\0';
	        }
			
			for(int j=0;j<MAX_BOOK_NAME;j++)
			{
			   arr[i].Name[j]='\0';
			    break; 
				
			}

	  }
	return true;
	}
}

void printCategories(Catergory arr[], int arraySize)
{
    cout<<setw(10)<<""<<"Category ID"<<setw(10)<<""<<"Name"<<endl;

		for(int i=0;i<arraySize;i++)
          { 
		  	if(arr[i].Id[0]!='\0')
            {
		     	cout<<setw(10)<<""<<arr[i].Id;
              	cout<<setw(18)<<""<<arr[i].Name;}
		      	cout<<endl;
		  	}
}

bool loadCategories(Catergory arr[], int arraySize)
{
  	ifstream catergory;
    catergory.open("CATERGORY.csv");

    Catergory newCatergory;
    while(catergory.good())
    {
	 	catergory.getline(newCatergory.Id,MAX_CATEGORY_NUMBER,',');
    	catergory.getline(newCatergory.Name,MAX_CATEGORY_NAME,'\n');

      	addCategory(arr,arraySize,newCatergory); 	
	}
}  

bool saveCategories(Catergory arr[], int arraySize)
{
   	ofstream catergory;
   	catergory.open("CATERGORY.csv");
   	Catergory newCatergory;
   	
	for(int i=0;i<arraySize;i++)
   	{ 
	   if(arr[i].Id[0]!='\0')
   	   {
		 catergory<<arr[i].Id<<",";
   	     catergory<<arr[i].Name;
		}
   	}
}

bool addBook(Book array[], int arraySize, Book newBook)
{    
	for(int i=0;i<arraySize;i++)
    {
	  	if(array[i].Id[0]=='\0'|| array[i].Name=='\0' )
  	 	{
			strcpy(array[i].Id,newBook.Id);
  	  		strcpy(array[i].Name,newBook.Name);
  	  		array[i].Edition=newBook.Edition;
  	  		break;
		}
	}
  	  return true;

}

bool editBook(Book array[], int arraySize, char bookId[], Book newData)
{
	for(int i = 0; i<arraySize; i++)
	{
		if (strcmp(array[i].Id,bookId)==0)
		{
			strcpy (array[i].Id, newData.Id);
			strcpy (array[i].Name, newData.Name);
			array[i].Edition = newData.Edition;
			return true;
			break;
		}
	}
	
	return false;
}
 
bool deleteBook (Book array[], int arraySize, char bookId[])
{
   for (int i = 0; i<arraySize; i++)
   {
		if (strcmp(array[i].Id,bookId)==0)
		{
			for(int j=0;j<MAX_BOOK_ID;j++)
				array[i].Id[j] ='\0';
			
			for(int j=0;j<MAX_BOOK_NAME;j++)
			{
				array[i].Name[j] ='\0';
				array[i].Edition = 0;
				return true;
				break;
			}			
				
		}
	}
	
	return false;
}

bool isExist(Book array[], int arraySize, char bookId[])
{
	for(int i=0;i<arraySize;i++)
    { 
		if(strcmp(array[i].Id,bookId)==0)
        	return true;
	
		else
			return false;
	}
}
	
bool loadBooks(Book array[], int arraySize)
{
	ifstream books;
	books.open("BOOK.csv");

	Book newBook;

	while(books.good())
	{
		books.getline(newBook.Name,MAX_BOOK_NAME,',');
		books>>newBook.Edition;
		books.ignore(1,',');
		books.getline(newBook.Id,MAX_BOOK_ID,'\n');
		addBook(array,arraySize,newBook);	
	}
}

bool saveBooks(Book array[], int arraySize)
{
	ofstream book;
	book.open("BOOK.csv");
	Book newBook;
	for(int i=0;i<arraySize;i++)
	{
		if(array[i].Id[0]!='\0')
	 	{ 
		 	book<array[i].Name;
	 	  	book<<array[i].Edition;
	 	  	book<<array[i].Id;
		}
	 }
}
		
void printBooks(Book array[], int arraySize)
{
	cout<<setw(15)<<""<<"ID"<<setw(15)<<""<<"NAME"<<setw(15)<<""<<"EDITION"<<endl;
	
	for(int i=0;i<arraySize;i++)
	{
		if(array[i].Id[0] != '\0')
		{
			cout<<setw(9)<<""<<array[i].Id;
			cout<<setw(10)<<""<<array[i].Name;
			cout<<setw(10)<<""<<array[i].Edition;
		}
			
			cout<<endl;

	}
}
	
bool isExist(BookCopy arry[], int arraySize, char copyId[])
{
	for(int i=0;i<arraySize;i++)
    { 
		if(strcmp(arry[i].Id,copyId)==0);
            return true;
	}


		return false;
}

bool addBookCopy(BookCopy arry[], int arraySize, BookCopy newBookCopy)
{
 	for(int i=0;i<arraySize;i++)
    {
	  	if(arry[i].Id[0]=='\0' )
  	 	{
		 	strcpy(arry[i].Id,newBookCopy.Id);
        	arry[i].PurchaseDate=newBookCopy.PurchaseDate;
			break;
		}
	}
  	
	return true;

}

bool editBookCopy(BookCopy arry[], int arraySize, char bookCopyId[], BookCopy newData)
{  
	for(int i=0;i<arraySize;i++)
    {
		if(strcmp(arry[i].Id,bookCopyId)==0);
        {
            strcpy(arry[i].Id,newData.Id);

	    	arry[i].PurchaseDate=newData.PurchaseDate;
	        return true;
		}
  	
	  	break;
}

	return false;
}

bool deleteBookCopy(BookCopy arry[], int arraySize, char bookCopyId[])
{
  	for (int i = 0; i<arraySize; i++)
    {
		if (strcmp(arry[i].Id,bookCopyId)==0)
		{
			for(int j=0;j<MAX_COPY_NUMBER;j++)
			{
				arry[i].Id[j] ='\0';
				arry[i].PurchaseDate.day=0;
				arry[i].PurchaseDate.month=0;
				arry[i].PurchaseDate.year=0;
				return true;
				break;			
			}		
		}
	}
	
	return false;
}

void printBookCopies(BookCopy arry[], int arraySize, char bookId[])
{   
	cout<<setw(15)<<""<<"CopyId"<<setw(15)<<""<<"Date"<<endl;
        for(int i=0;i<arraySize;i++)
        {
            if(arry[i].Id[0]!='\0' && arry[i].Id[0]!='\0' )
            { 
				cout<<setw(10)<<""<<arry[i].Id;
			  	cout<<setw(11)<<""<<arry[i].PurchaseDate.day<<"-"<<arry[i].PurchaseDate.month<<"-"<<arry[i].PurchaseDate.year;
			}
		 
		cout<<endl;
		 
		}

}

bool saveBookCopies(BookCopy arry[], int arraySize)
{
	ofstream bookcopy;
	bookcopy.open("BOOKCOPY.csv");
	for(int i=0;i<arraySize;i++)
	{
		if(arry[i].Id[0]!='\0' && arry[i].Id[0]!= '\0' )
	  	{
			bookcopy<<arry[i].PurchaseDate.day<<",";
			bookcopy<<arry[i].PurchaseDate.month<<",";
			bookcopy<<arry[i].PurchaseDate.year<<",";
			bookcopy<<arry[i].Id<<endl;
		}
	}
}

bool loadBookCopies(BookCopy arry[], int arraySize)
{
    ifstream bookcopy;
    bookcopy.open("BOOKCOPY.csv");

    BookCopy newBookCopy;
    while(bookcopy.good())
	{
      	bookcopy>>newBookCopy.PurchaseDate.day;
		bookcopy.ignore(1,',');
		bookcopy>>newBookCopy.PurchaseDate.month;
		bookcopy.ignore(1,',');
		bookcopy>>newBookCopy.PurchaseDate.year;
		bookcopy.ignore(1,',');
		bookcopy.getline(newBookCopy.Id,MAX_COPY_NUMBER,'\n');

		addBookCopy(arry,arraySize,newBookCopy);
	}
}


bool isExist(Student ar[], int arraySize, char regNo[])
{
	for(int i=0;i<arraySize;i++)
    { 
		if(strcmp(ar[i].RegistrationNo,regNo)==0);
            return true; 
	}
}

bool addStudent(Student ar[], int arraySize, Student newStudent)
{
	for(int i=0;i<=arraySize;i++)
	{
		if(ar[i].RegistrationNo[0] == '\0' )
		{
			strcpy(ar[i].RegistrationNo, newStudent.RegistrationNo);
			strcpy(ar[i].Name, newStudent.Name);
			ar[i].Session = newStudent.Session;
			ar[i].AdmissionDate = newStudent.AdmissionDate;
			break;
			
				return true;
		}
		
		else
			return false;
	}
	
}

bool editStudent(Student ar[], int arraySize, char regNo[], Student newData)
{
	for(int i=0;i<arraySize;i++)
	{
		if(strcmp(ar[i].RegistrationNo,regNo)==0);
        {
            strcpy(ar[i].RegistrationNo,newData.RegistrationNo);
			ar[i].AdmissionDate=newData.AdmissionDate;
	       	return true;
		}
  		
		  break;
  	}
  
return false;

}

bool deleteStudent (Student ar[], int arraySize, char regNo[])
{
  	for (int i = 0; i<arraySize; i++)
   	{
		if (strcmp(ar[i].RegistrationNo,regNo)==0)
		{
			for(int j=0;j<REGISTRATION_NUMBER;j++)
			{
				ar[i].RegistrationNo[j] ='\0';
			
			 	for(int j=0;j<MAX_STUDENT_NAME;j++)
				{
			 		ar[i].Name[j]='\0';
					ar[i].AdmissionDate.day=0;
					ar[i].AdmissionDate.month=0;
					ar[i].AdmissionDate.year=0;
					break;	
				
				return true;
				
				}
			}	
		}
	}
	
	return false;
}

void printStudents(Student ar[], int arraySize)
{
	cout<<setw(5)<<""<<"Registration Number"<<setw(12)<<""<<"Name"<<setw(12)<<""<<"Session"<<setw(8)<<""<<"Admission Date"<<endl;

	 for(int i=0;i<arraySize;i++)
	 {
	 	if(ar[i].RegistrationNo[0]!='\0' &&  ar[i].RegistrationNo[0]!='\0')
	 	{
	 		cout<<setw(5)<<""<<ar[i].RegistrationNo;
	 		cout<<setw(12)<<""<<ar[i].Name;
	 		cout<<setw(12)<<""<<ar[i].Session;
	 		cout<<setw(8)<<""<<ar[i].AdmissionDate.day<<"-"<<ar[i].AdmissionDate.month<<"-"<<ar[i].AdmissionDate.year;
		 }
	 
	 cout<<endl;
	 
	}
}

bool saveStudents(Student ar[], int arraySize)
{
  	ofstream student;
  	student.open("STUDENTDATA.csv");
  		
	for(int i=0;i<arraySize;i++)
  	{
  		if(ar[i].RegistrationNo[0]!='\0')
  		{
  			student<<ar[i].RegistrationNo<<",";
  			student<<ar[i].Name<<",";
  			student<<ar[i].Session<<",";
  			student<<ar[i].AdmissionDate.day<<",";
			student<<ar[i].AdmissionDate.month<<",";
			student<<ar[i].AdmissionDate.year;
		}
	}
}

bool loadStudents(Student ar[], int arraySize)
{
	ifstream student;
	student.open("STUDENTDATA.csv");

	Student newStudent;
	
	while(student.good())
	{
		student.getline(newStudent.RegistrationNo,REGISTRATION_NUMBER,',');
		student.getline(newStudent.Name,MAX_STUDENT_NAME,',');
		student>>newStudent.Session;
		student.ignore(1,',');
		student>>newStudent.AdmissionDate.day;
		student.ignore(1,',');
		student>>newStudent.AdmissionDate.month;
		student.ignore(1,',');
		student>>newStudent.AdmissionDate.year;
		student.ignore(1,'\n');
		
		addStudent(ar,arraySize,newStudent);
	}
}
	 	
void printmenu()
{ 
	cout<<"\n";
	cout<<setw(20)<<""<< "******* Welcome To University Library Management System *******"<<endl;;
    cout<<"\n";
    cout<<"Sr.No"<<setw(5)<<""<<"Management Function:"<<endl ;
    cout<<"\n";
	cout<<"1:"<<setw(3)<<""<<"Category Management(A,E,L,D)"<<endl;
    cout<<"2:"<<setw(3)<<""<<"Books Management(A,E,L,D)"<<endl;
    cout<<"3:"<<setw(3)<<""<<"Book Copies Management(A,E,L,D)"<<endl;
    cout<<"4:"<<setw(3)<<""<<"Student Management(A,E,L,D)"<<endl;
    cout<<"0:"<<setw(3)<<""<<"Exit Program(0E)"<<endl;
	cout<<"\n";
	cout<<"Hint:First Select Serial Number And Then select the function you want to perform, Like this:(1A)"<<endl;
	cout<<"\n";

    cout<<"***A is for Addition"<<setw(3)<<""<<",E is for Edit"<<setw(3)<<""<<",L is for Print"<<setw(3)<<""<<",D is for Delete***"<<endl;
	cout<<"\n";
	cout<<setw(20)<<""<<"********Selection of the options what you want to do******** ";
	cout<<"\n";
}

void TakeMenuInput(char option[])
{
	
}

void readInCatergory(Catergory& catergory)
{
	cin>>catergory.Id;
	cin>>catergory.Name;
}
 
void readInBook(Book& book)
{ 
	cin>>book.Id;
  	cin>>book.Edition;
   	cin>>book.Name;
}

void readInBookCopy(BookCopy &bookCopy)
{ 
	cout<<"Enter the id of bookcopy;";
	cin>>bookCopy.Id;
	 
	cout<<"Enter month:";
	cin>>bookCopy.PurchaseDate.month;
	
	cout<<"Enter day:";
	cin>>bookCopy.PurchaseDate.day;

    cout<<"Enter year:";
	cin>>bookCopy.PurchaseDate.year;
}

void readInStudent(Student& student)
{   
	cout<<"Enter the registration number :";
	cin>>student.RegistrationNo;

	cout<<"Enter the student name:";
	cin>>student.Name;

	cout<<"Enter the Session:";
	cin>>student.Session;

	cout<<"Enter Student Admission day:";
	cin>>student.AdmissionDate.day;

	cout<<"Enter Student Admission month:";
	cin>>student.AdmissionDate.month;

	cout<<"Enter Book copy Purchase year:";
	cin>>student.AdmissionDate.year;						   }

int main()

{ 
	printmenu();

  	while(true)
    {
		cout<<endl;cout<<"choose option;";
		
		int arraySize=50;
        int MAX_STUDENTS=100;
        
		Student ar[MAX_STUDENTS];Student newStudent;
        
		char  regNo[REGISTRATION_NUMBER];
		BookCopy arry[arraySize],newBookCopy;
        char bookCopyId[MAX_COPY_NUMBER];

        int maxbook=200;
		char bookId[MAX_BOOK_ID];
        Book newBook,array[maxbook];
        Catergory newData;
        char catId[MAX_CATEGORY_NUMBER];
        int maxcatergory=30;
        Catergory newCatergory;
		Catergory arr[maxcatergory];

	for(int i=0;i<maxcatergory;i++)
	{
		for(int j=0;j<MAX_CATEGORY_NUMBER;j++)
		{ 
			arr[i].Id[j]='\0';
		}
	}
		     
		for(int i=0;i<maxcatergory;i++)
		{
		   	for(int j=0;j<MAX_CATEGORY_NAME;j++)
		   	{ 
			   arr[i].Name[j]='\0';
			}
		}

		for(int i=0;i<maxbook;i++)
		{
		   	for(int j=0;j<MAX_BOOK_ID;j++)
		   	{ 
			   array[i].Id[j]='\0';
			}
		}
		     
		for(int i=0;i<maxbook;i++)
		{
		   	for(int j=0;j<MAX_BOOK_NAME;j++)
		   	{ 
				 array[i].Name[j]='\0';
			}
		}
			
		for(int i=0;i<50;i++)
		{
			array[i].Edition='\0';
		}
				
		for(int i=0;i<arraySize;i++)
		{
			for(int j=0;j<MAX_COPY_NUMBER;j++)
			arry[i].Id[j]='\0';

			for(int i=0;i<50;i++ )
			{   
				arry[i].PurchaseDate.day=0;
	    		arry[i].PurchaseDate.month=0;
	    		arry[i].PurchaseDate.year=0;
			}
		}
		
		for(int i=0;i<MAX_STUDENTS;i++)
		{
			for( int j=0;j<MAX_STUDENT_NAME;j++)
			{
		  		ar[i].Name[j]='\0';
		  		ar[i].AdmissionDate.day=0;
		  		ar[i].AdmissionDate.month=0;
		  		ar[i].AdmissionDate.year=0;

			}
		}
			
		for(int i=0;i<50;i++)
		{

			for(int j=0;j<REGISTRATION_NUMBER;j++)
			{
				ar[i].RegistrationNo[j]='\0';
			}
		}
        
		loadCategories(arr,arraySize);
        loadBooks(array,arraySize);
        loadStudents(ar,arraySize);
        loadBookCopies(arry,arraySize);

		char option[2];
		cin>>option;
		TakeMenuInput(option);

		if(option[0]=='1' && option[1]=='A')
	    { 
		 	cout<<"Enter the details of the category (Id Name): ";
            	readInCatergory(newCatergory);

		if((isValidCategoryName(newCatergory.Name)==true) && (isValidCategoryNumber(newCatergory.Id)==true))
	    {
		    addCategory(arr,maxcatergory,newCatergory);
 			cout<<"Catergory is now successsfully added!";

		}
				
		else
			cout<<"Catergory is not added!";

		if(option[0]=='1' && option[1]=='E')
		{  
			cout<<"Enter the Category Id to edit:";
			cin>>catId;

			if(isExist(arr,arraySize,catId)==true)
			{   
				cout<<"Enter the new detials of Catergory :";
				readInCatergory(newCatergory);
				
				if((isValidCategoryName(newCatergory.Name)==true) && (isValidCategoryNumber(newCatergory.Id)==true))
				{
					editCategory(arr,maxcatergory,catId,newCatergory);
					cout<<"Category has been edited successfully";

				} 
				
			else
			cout<<"Book is not present ";

			}
		}

	if(option[0]=='1'&& option[1]=='D')
	{ 
		 cout<<"Enter the category Id to delete:";
		cin>>catId;
		
		if(isExist(arr,maxcatergory,catId)==true)
		{
			deleteCategory(arr,arraySize,catId);
			cout<<"Category has been deleted successfully";

		}
		
		else
			cout<<"Book  is not present";
			
	}

	if(option[0]=='1'&& option[1]=='L')
		printCategories(arr,maxcatergory);

	if(option[0]=='2' && option[1]=='A')
	{ 
		cout<<"Enter the book id ;";
		cin>>bookId;
			
		if(isExist(array,arraySize,bookId)==true)
			cout<<"Enter the details of the book(Id Edition Name) : ";
			readInBook(newBook);

		if((isValidBookId(newBook.Id)==true) || (isValidBookName(newBook.Name)==true))
		{
			addBook(array,arraySize,newBook);
			cout<<"Book has been added successfully in category "<<catId;

		}  
		
		else
			cout<<"Book is already prenest";}
	
	}				
	
	if(option[0]=='2' && option[1]=='E')
	{  
		cout<<"Enter the Book Id to edit:";
        cin>>bookId;

    	if(isExist(array,maxbook,bookId)==true)
		{   
			cout<<"Enter the new detials of book :";
			readInBook(newBook);
						   
			if((isValidBookName(newBook.Name)==true) && (isValidBookId(newBook.Id)==true))
			{
				editBook(array,maxbook,bookId,newBook);
				cout<<"Book has been edited successfully";

			}
		
		else
			cout<<"Book is not present ";

		}
	
	}


	if(option[0]=='2' && option[1]=='D')
	{
		cout<<"Enter the books you want to delete :";
		cin>>bookId;
		
		if(isExist(array,maxbook,bookId))
		{ 
			readInBook(newBook);
			deleteBook(array,maxbook,bookId);
			cout<<"Your book has been delete ";
		} 
		
		else
			cout<<"Book is not present in library";
	}

	if(option[0]=='2' && option[1]=='L' )
	{
		printBooks(array,maxbook);
	}

	if(option[0]=='3' && option[1]=='A')
	{ 
		cout<<"Enter the details of the sample(Id Date-of-Purchase):"<<endl;
		readInBookCopy(newBookCopy);

		if((isValidCopyNumber(newBookCopy.Id)==true) && (isValidDate(newBookCopy.PurchaseDate)==true))
		{
			addBookCopy(arry,arraySize,newBookCopy);
			cout<<"Book copy has been added successfully";
		}
	}
						  
	if(option[0]=='3' && option[1]=='E')
	{
		cout<<"Enter the Book copy to edit:";
		cin>>bookCopyId;
						  
		if(isExist(arry,arraySize,bookCopyId)==true)
		{
			cout<<"Enter the new details of the book copy:"<<endl;;
			readInBookCopy(newBookCopy);
			BookCopy newData;
			editBookCopy(arry,arraySize,bookCopyId,newData);
			cout<<"Book copy has been edited successfully";
		}

	}
				  	
	if(option[0]=='3' && option[1]=='D')
	{
		cout<<"Enter the category Id to delete:";
		cin>>bookCopyId;
			  	  	  
		if(isExist(arry,arraySize,bookCopyId)==true)
		{
			deleteBookCopy(arry,arraySize,bookCopyId);
			cout<<"Book copy has been deleted successfully";

		}
	}
				       
	if(option[0]=='3' && option[1]=='L')
	{
		printBookCopies(arry,arraySize,bookId);
		
	}

	if(option[0]=='4' && option[1]=='A')
	{
		cout<<"Enter the details of the student (RegNo. Name Session AdmissionDate):";
		readInStudent(newStudent);
		
		if(isValidRegistrationNo(newStudent.RegistrationNo)==true && ( isValidDate(newStudent.AdmissionDate)==true))
		{
			addStudent(ar,MAX_STUDENTS,newStudent);
			cout<<"Student has been added successfully";

		}
	}

	if(option[0]=='4' && option[1]=='L')
	{
		printStudents(ar,MAX_STUDENTS);

	}

	if(option[0]=='4' && option[1]=='D')
	{
		cout<<"Enter the student registration No. to delete: ";
		cin>> regNo;
						 	 
		if(isExist(ar,MAX_STUDENTS,regNo)==true)
		{
			deleteStudent (ar, arraySize,regNo);

			cout<<"Student has been deleted successfully";
		}

	else
		cout<<"student is not present ";
	}
						
	if (option[0]=='4' && option[1]=='E')
	{   
		cout<<"Enter the student registration No to edit:";
		cin>>regNo;

		if(isExist(ar,MAX_STUDENTS,regNo)==true)
		{  	
			cout<<"Enter the new details of the student:";

			readInStudent(newStudent);
			editStudent(ar,arraySize,regNo,newStudent);

			cout<<"Student has been edited successfully!";
		}

	else
		cout<<"Student is not present!";
	}
	
    if(option[0]=='0'&& option[1]=='E')
    {
        saveBookCopies(arry,arraySize);
        saveCategories(arr,arraySize);
        saveBooks(array, arraySize);
        saveStudents(ar,arraySize);		 
	}
    
	}

	return 0;
} 							  
