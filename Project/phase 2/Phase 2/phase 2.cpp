#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
	
int const MAX_BOOK_ID=13;														
int const DATE_SIZE=11;
int const MAX_COPY_NUMBER=17;
int const MAX_BOOKS=200; 
int const MAX_CATEGORIES=30;
int const MAX_STUDENTS=100;
int const MAX_BOOK_NAME=60;
int const MAX_CATEGORY_NAME=20;
int const MAX_STUDENT_NAME=60;
int const MAX_REGISTRATION_NUMBER=12;
int const MAX_CATEGORY_NUMBER=4;

struct Book
{
	char Id[];
	char Name[];
	int Edition;
};

struct Category
{
	char Id[];
	char Name[];
};

struct Date		
{
	int day;
	int month;
	int year;
};

struct BookCopy
{
	char Id[];
	Date PurchaseDate;
};

struct Student
{
	char ResgistrationNo[];
	char Name[];
	int Session;
	Date AdmissionDate;
};

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

bool isValidCategoryName(char catNo[])
{
	bool result;
	
	if(int (catNo[16])>=65 && int (catNo[16])<=90)
		result=true;
		
	else
		result=false;
		
	if(int (catNo[16])>=97 && int (catNo[16]<=122))
		result=true;
		
	else
		result=false;
	
	return result;				
}

bool isValidCategoryNumber(char catNumber[])
{
	bool result;
	
	for(int i=0; i<3; i++)
	{
		if(int (catNumber[i])>=48 && int (catNumber[i])<=57)
			result=true;
			
		else
			result=false;	
	}
	
	return result;
}

bool isValidDate(Date date)
{
	bool result;
	
	if(date.month>0 && date.month<13)
		result=true;
		
	else
		result=false;
		
	if(date.day>0 && date.day<31)
		result=true;
	
	else 
		result=false;
			
	if(date.month==2 && date.day>0 && date.day<30)
		result=true;
		
	else
		result=false;	

	return result;				
}

bool isValidRegistrationNumber(char regNo[])
{
	bool result;

	if(regNo[0]=='2')
	{
		if(regNo[1]=='0')
		{
			if(regNo[2]=='1')
			{
				if(regNo[3]>=48 && regNo[3]<=57)
				{
					if(regNo[4]=='-')
					{
						if(regNo[5]>='A'&& regNo[5]<='Z')
						{
							if(regNo[6]>='A'&& regNo[6]<='Z')
							{
								if(regNo[7]=='-')									
								{
									if(regNo[8]>='0' && regNo[8]<='9')
									{
										if(regNo[9]>='0' && regNo[9]<='9')
										{
											if(regNo[10]>='0' && regNo[10]<='9')
											{
												result=true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
		
else
	result=false;
}

bool isValidStudentName(char stdName[])
{
	bool result;
	
		for(int j=0; j<60 ;j++)
		{
			if(int (stdName[j])>=65 && int (stdName[j])<=90 && int (stdName[j])>=97 && int (stdName[j])<=122)
				result=true;
			
			else
			{
				result=false;
				break;
			}
				
		}
	
	return result;
}

bool addCategory(Category arr[], int arraySize, Category newCategory)
{
	arr[arraySize].Id[arraySize]=newCategory.Id[arraySize];
	arr[arraySize].Name[arraySize]=newCategory.Name[arraySize];
	arraySize++;
}

bool editCategory(Category arr[], int arraySize, char catId[], Category newData)
{
	bool result;
	
	for(int i=0; i<arraySize; i++)
	{
		if(arr[i].Id==catId)
		{
			strcpy(arr[i].Id, newData.Id);
			strcpy(arr[i].Name, newData.Name);
			break;
			
			result=true;
		}
		
		else
			result=false;
	}

	return result;
}

bool deleteCategory(Category arr[], int arraySize, char catId[])
{
	bool result;
	
	for(int i=0;i<arraySize;i++)
	{
		if(arr[i].Id==catId)
		{
			arr[i].Id[i]='\0';
			arr[i].Name[i]='\0';
			
			for(int j=i; j<arraySize;j++)
			{
				arr[j].Id[j]=arr[j+1].Id[j+1];
				arr[j].Name[j]=arr[j+1].Name[j+1];
			}
			
			break;
		
			result=true;
		}
		
		else
			result=false;
	}

	return result;
}

void printCategories(Category arr[], int arraySize)
{
	for(int i=0; i<arraySize; i++)
	{
		cout<<"ID= "<<arr[i].Id;
		cout<<"\t Name= "<<arr[i].Name;
		cout<<endl;
	}
}

bool saveCategories(Category arr[], int arraySize)
{
	ofstream data;
	
	data.open("Categories.csv");
	{
		if(data.is_open())
		{
			data<<arr[arraySize].Id<<","<<arr[arraySize].Name;
		}
		
		else
		{
			cout<<"File doesn't exists ";
		}	
	}
	
	return true;
}

bool loadCategories(Category arr[], int arraySize)
{
	ifstream data;
	string str='\0';
	string Id='\0';
	string Name='\0';
	
	data.open("Categories.csv");
	{
		if(data.is_open())
		{
			for(int i=0; i<2; i++)
			{
				getline(data,str);
				
				for(int j=0; str[j]!=','; j++)
				{
					Id=Id+str[j];
				}
				
				for(int k=0; str[k]!='\0'; k++)
				{
					Name=Name+str[k];

				}
				
			}
		
		}	
	}

	return true;
}

void readInCategory(Category& category)
{
	string Id, Name;
	
	cout<<"Enter the Id "<<endl;
	cin>>Id;
	
	cout<<"Enter the Name "<<endl;
	cin>>Name;
	
	Category.Id=Id;
	Category.Name=Name;
}

bool addBook(Book arr[], int arraySize, Book newBook)
{
	arr[arraySize].Id[arraySize]=newBook.Id[arraySize];
	arr[arraySize].Name[arraySize]=newBook.Name[arraySize];
	arr[arraySize].Edition=newBook.Edition;
	arraySize++;
}

bool editBook(Book arr[], int arraySize, char bookId[], Book newData)
{
	bool result;
	
	for(int i=0; i<arraySize; i++)
	{
		if(arr[i].Id==bookId)
		{
			strcpy(arr[i].Id, newData.Id);
			strcpy(arr[i].Name, newData.Name);
			break;
			
			result=true;
		}
		
		else
			result=false;
	}

	return result;
}

bool deleteBook (Book arr[], int arraySize, char bookId[])
{
	bool result;
	
	for(int i=0;i<arraySize;i++)
	{
		if(arr[i].Id==bookId)
		{
			arr[i].Id[i]='\0';
			arr[i].Name[i]='\0';
			
			for(int j=i; j<arraySize;j++)
			{
				arr[j].Id[j]=arr[j+1].Id[j+1];
				arr[j].Name[j]=arr[j+1].Name[j+1];
			}
			
			break;
		
			result=true;
		}
		
		else
			result=false;
	}

	return result;
}

void printBooks(Book arr[], int arraySize)
{
	for(int i=0; i<arraySize; i++)
	{
		cout<<"ID= "<<arr[i].Id;
		cout<<"\t Name= "<<arr[i].Name;
		cout<<endl;
	}
}

bool saveBooks(Book arr[], int arraySize)
{
	ofstream data;
	
	data.open("Categories.csv");
	{
		if(data.is_open())
		{
			data<<arr[arraySize].Id<<","<<arr[arraySize].Name<<","<<arr[arraySize].Edition;
		}
		
		else
		{
			cout<<"File doesn't exists ";
		}
	}
	
	return true;
}

bool loadBooks(Book arr[], int arraySize)
{
	ifstream data;
	string str='\0';
	string Id='\0';
	string Name='\0';
	string Edition='\0';
	
	data.open("Categories.csv");
	{
		if(data.is_open())
		{
			for(int i=0; i<2; i++)
			{
				getline(data,str);
				
				for(int j=0; str[j]!=','; j++)
				{
					Id=Id+str[j];
				}
				
				for(int k=0; str[k]!='\0'; k++)
				{
					Name=Name+str[k];

				}
				
				for(int l=0; str[l]!='\0';l++)
				{
					Edition=Edition+str[l];
				}
				
			}
		
		}	
	}

	return true;
}

bool addBookCopy(BookCopy arr[], int arraySize, BookCopy newBookCopy)
{
	arr[arraySize].Id[arraySize]=newBookCopy.Id[arraySize];
	arr[arraySize].PurchaseDate=newBookCopy.PurchaseDate;
	arraySize++;
} 

bool editBookCopy(BookCopy arr[], int arraySize, char bookCopyId[], BookCopy newData)
{
		bool result;
	
	for(int i=0; i<arraySize; i++)
	{
		if(arr[i].Id==bookCopyId)
		{
			strcpy(arr[i].Id, newData.Id);
			strcpy(arr[i].PurchaseDate, newData.PurchaseDate)
			break;
			
			result=true;
		}
		
		else
			result=false;
	}

	return result;

}

bool deleteBookCopy(BookCopy arr[], int arraySize, char bookCopyId[])
{
	bool result;
	
	for(int i=0;i<arraySize;i++)
	{
		if(arr[i].Id==bookCopyId)
		{
			arr[i].Id[i]='\0';
			arr[i].PurchaseDate='\0';
			
			for(int j=i; j<arraySize;j++)
			{
				arr[j].Id[j]=arr[j+1].Id[j+1];
				arr[j].PurchaseDate=arr[j+1].PurchaseDate;
			}
			
			break;
		
			result=true;
		}
		
		else
			result=false;
	}

	return result;

}

bool addStudent(Student arr[], int arraySize, Student newStudent)
{
	arr[arraySize].Name[arraySize]=newStudent.Name[arraySize];
	arr[arraySize].ResgistrationNo[arraySize]=newStudent.ResgistrationNo[arraySize];
	arr[arraySize].Session=newStudent.Session;
	arr[arraySize].AdmissionDate=newStudent.AdmissionDate;
	arraySize++;
}


int main()
{
	char a,b;
	Date std;
	
	cout<<"Enter the month ";
	cin>>std.month;
	
	cout<<"Enter the day ";
	cin>>std.day;
	
	cout<<"Enter the year ";
	cin>>std.year;
	
	cout<<isValidDate;
	
	cout<<"Enter the registration number" ;
	cin>>a;
	
	cout<<isValidRegistrationNumber;
	
	
		cout<<"Enter the name of student ";
		if(cin.fail())
	{
		cin.clear();
		cin.ignore(500, '\n');
	}
	if(cin.peek ()!= '\n')
	{
		cin.clear();
		cin.ignore(500, '\n');
	}
		cin>>b;
	
	cout<<isValidStudentName;
	
	return 0;
}
