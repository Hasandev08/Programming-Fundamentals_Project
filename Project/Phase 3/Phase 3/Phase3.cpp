#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
using namespace std;


	const int MAX_BOOK_ID = 13;
	const int DATE_SIZE = 11;
	const int MAX_COPY_NUMBER = 17;
	const int MAX_BOOKS = 200;
	const int MAX_CATEGORIES =30;
	const int MAX_BOOK_NAME = 60;
	const int MAX_CATEGORY_NAME = 20;
	const int MAX_CATEGORY_NUMBER = 4;
	const int MAX_STUDENTS = 100;
	const int MAX_REGISTRATION_NUMBER=12;
	const int MAX_STUDENT_NAME = 60;
	
	
	enum Month{
		January=1,
		February=2,
		March=3,
		April=4,
		May=5,
		June=6, 
		July=7,
		August=8,
		September=9,
		October=10,
		November=11,
		December=12		
	};
	enum BookStatus{
		Issued=0,
		Returned,
	};	
	
	struct Book{
		char Id[MAX_BOOK_ID];
		char Name[MAX_BOOK_NAME];
		int Edition;	
	};
	struct Category{
		char Id[MAX_CATEGORY_NUMBER];
		char Name[MAX_CATEGORY_NAME];
	};
	struct Date{
		int Day;
		Month month;
		int Year;
		
	};
	struct BookCopy {
		char Id[MAX_COPY_NUMBER];
		Date PurchaseDate;
	};
	struct Student{
		char RegistrationNo[MAX_REGISTRATION_NUMBER];
		char Name[MAX_STUDENT_NAME];
		int Session;
		Date AdmissionDate;
	};
	struct User{
		char UserName[30];
		char password[30];
	};
	struct BookIssue{
		char regNo[MAX_REGISTRATION_NUMBER];
		char bookCopyId[MAX_COPY_NUMBER];
		BookStatus status;
		Date issueDate;
	};
	bool isExist(BookCopy arr[], int arraySize, char copyId[]);
	void inputmonth(int x, Month& month);
	bool isValidRegistrationNo(char regNo[]);
	bool isValidCopyNumber(char bookCopy[])	;

	
	bool isValidemailId(char emailid[]){
		bool atherateexist = false;
		for(int i=0;i<30;i++){
			if(emailid[i] == '@')
				atherateexist = true;
		}
		
		if(atherateexist = false)
			return false;
	}
	
	bool issueBook(BookIssue arr[], int size, BookIssue toIssue){
	
	cout<<"enter the details(studentRegNo bookCopyId)";
	cin>>toIssue.regNo>>toIssue.bookCopyId;
	if(isValidCopyNumber(toIssue.bookCopyId)==true && isValidRegistrationNo(toIssue.regNo)){
		for(int i=0;i<size;i++){
			if(arr[i].regNo[0]=='*' && arr[i].bookCopyId[0]=='*'){
				arr[i] = toIssue;
				arr[i].status = Issued;
			}
		}
	}
	else{
		cout<<"Wrong Copy Id or Registration Number";
	}
	
}

	int returnBook(BookIssue arr[], int size, char copyIdtoReturn[]){
		int numberOfExtraDays;
		for(int i=0;i<size;i++){
			if(strcmp(arr[i].bookCopyId,copyIdtoReturn)==0){
				arr[i].status = Returned;
				break;
			}
			
		}	
	}

	void loadUser(User arr[],int size){

		ifstream users;
		users.open("Users.csv");
			
		User newUser;
	
		while(!users.eof())
		{
			users.getline(newUser.UserName,30,',');
			users.getline(newUser.password,30,'\n');		
			
			for(int i=0;i<size;i++){	
				if(arr[i].UserName[0] == '*'){
					strcpy(arr[i].UserName, newUser.UserName);				
					strcpy(arr[i].password, newUser.password);
					break;
				}
			}
		}	
}
	
	bool findUser(User arr[], int size, User toFind){
	
	
	for(int i=0;i<size;i++){
		if(strcmp(arr[i].UserName,toFind.UserName)==0 && strcmp(arr[i].password,toFind.password)==0)	
			return true;		
	}
	return false;
}
	
	void studentCurrentBook(BookIssue arr[], int size, char regNo[]){
		

		bool bookissued = false;
		for(int i=0;i<size;i++){
			if(strcmp(arr[i].regNo,regNo)==0){
				if(arr[i].status = Issued)	
					bookissued = true;
			}
		}
		
		cout<<endl<<endl;
		if(bookissued =true){
			cout<<setw(20)<<"Copy Id"<<setw(20)<<"Issue Date"<<endl;
			for(int i=0;i<size;i++){
				if(strcmp(arr[i].regNo,regNo)==0){
					if(arr[i].status = Issued)
					cout<<"hello";
					cout<<setw(20)<<arr[i].bookCopyId<<arr[i].issueDate.Day<<"-"<<arr[i].issueDate.month<<"-"<<arr[i].issueDate.Year;
						
				}
			}
		}
		
		cout<<endl<<endl;
	}
	
	void checkBookStatus(BookIssue bookissuearr[], BookCopy bookcopyarr[], int issueSize, int bookCopySize, char copyId[]){
		

			for(int i=0;i<issueSize;i++){
				if(strcmp(bookissuearr[i].bookCopyId,copyId)==0){
					if(bookissuearr[i].status = Issued)
						cout<<"The book is currently issued to the student "<<bookissuearr[i].regNo;
					else
						cout<<"The Book is available";
				}		
			}			
		
		
		cout<<endl<<endl;
	}
	
	void loadBookIssue(BookIssue arr[], int size){
		
		ifstream bookhistory;
		bookhistory.open("bookhistory.csv");
		int x,y;	
		BookIssue newBookIssue;
	
		while(bookhistory.good())
		{
			
			
			bookhistory>>newBookIssue.issueDate.Day;
			bookhistory.ignore(1,',');
			bookhistory>>x;
			inputmonth(x,newBookIssue.issueDate.month);
			bookhistory.ignore(1,',');
			bookhistory>>newBookIssue.issueDate.Year;
			bookhistory.ignore(1,',');
			
			bookhistory>>y;
				if(y==0)
					newBookIssue.status = Issued;
				if(y==1)	
					newBookIssue.status = Returned;
			
			bookhistory.ignore(1,',');
			bookhistory.getline(newBookIssue.bookCopyId,MAX_COPY_NUMBER,',');
			bookhistory.getline(newBookIssue.regNo,MAX_REGISTRATION_NUMBER,'\n');
			
			for(int i=0;i<size;i++){	
				if(arr[i].regNo[0] == '*'){
					strcpy(arr[i].bookCopyId,newBookIssue.bookCopyId);				
					strcpy(arr[i].regNo,newBookIssue.regNo);
					arr[i].issueDate = newBookIssue.issueDate;
					arr[i].status = newBookIssue.status;
					break;
				}
			}
			
	}
}
	
	void saveBookIssue(BookIssue arr[], int size){
		
			ofstream bookhistory;
			bookhistory.open("Bookhistory.csv");
			
			for(int i=0;i<size;i++){
				if(arr[i].regNo[0]!='*' && arr[i].regNo[0]!= '\0'){
					bookhistory<<arr[i].issueDate.Day<<",";
					bookhistory<<arr[i].issueDate.month<<",";
					bookhistory<<arr[i].issueDate.Year<<",";
					bookhistory<<arr[i].status<<",";
					bookhistory<<arr[i].bookCopyId<<",";
					bookhistory<<arr[i].regNo<<endl;
					break;	
				}
			
			}
		
	}
	
	void PrintMenu(){
	cout<<"** Welcome to University Library Management System **"<<endl;
	cout<<"Choose the following option"<<endl;
	cout<<setw(5)<<left<<"1"<<"Category Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"2"<<"Books Management(A,E,L,D"<<endl;
	cout<<setw(5)<<"3"<<"Book Copies Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"4"<<"Student Management(A,E,L,D)"<<endl;
	cout<<setw(5)<<"5"<<"Book Issue Management(I,R,S,B)"<<endl;
	cout<<setw(5)<<"9"<<"Logout (9L"<<endl;
	cout<<setw(5)<<"0"<<"Exit Program(0E)"<<endl;
	cout<<endl<<"Choose the option:";
}

	bool isValidBookId(char bookId[]){
		
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
	
	bool isValidCopyNumber(char bookCopy[]){
 
		if(bookCopy[12] != '#')
			return false;
		
		for(int i=13;i<=15;i++){
			if((bookCopy[i]<'0')||(bookCopy[i]>'9'))
				return false;	
		}	
		
	return true;	
		}
	
	bool isValidBookName(char BookName[]){
		int i =0;
		while(BookName[i] != '\0' && i<60 ){
			if(BookName[i]<'A' || BookName[i]>'Z'){
				if(BookName[i]<'a' || BookName[i]>'z'){
					if(BookName[i] != ':'){
						if(BookName[i] != ','){
							if(BookName[i] != ' ')
								return false;
							else if(BookName[i]== ' '){
								if(BookName[i+1]==' ')
									return false;
							}
						}
						else if(BookName[i]==','){
							if(BookName[i+1]==','){
								return false;
							}
						}
					}	
					else if(BookName[i] == ':'){
						if(BookName[i+1] == ':')
							return false; 	
					}
				}
			}
			i++;
			
		}
	
		return true;		
}

	bool isValidCategoryName(char bookCategory[]){
		int i;
		while(bookCategory[i]!='\0'){
			if(bookCategory[i]<'A' || bookCategory[i]>'Z'){
				if(bookCategory[i]<'a' || bookCategory[i]>'z')
					return false;
			}			
			i++;
		}
		return true;
	}	
		
	bool isValidCategoryNumber(char bookCategory[]){
		int i;
		while(bookCategory[i] != '\0' && i<20){
			if(bookCategory[i]<'0' || bookCategory[i] > '9')
				return false;
			else
				return true;
		i++;
		}
	}
	
	bool isValidRegistrationNo(char regNo[]){
		
		if(regNo[4]!='-')
			return false;
		if(regNo[7]!='-')
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
	
	bool isValidStudentName(char stdName[]){
		int i;
		while(stdName[i]!='\0'){
			if(stdName[i]<'A' || stdName[i]>'z'){
				return false;
			}			
			i++;
		}
		return true;
	
	}	
		
	bool isValidDate(Date date){
		
		if(date.Day>31)
			return false;
		if(date.Year>2020 || date.Year<2010)
			return false;
		if(date.month==February){
			if(date.Day>29)
				return false;
		}
		return true;
	}
	
	void inputmonth(int x, Month& month){
		if(x=3){
			month = March;}
		if(x=2){
			month = February;}
		if(x=1){
			month = January;}
		if(x=4)
			month = April;
		if(x=5)
			month = May;
		if(x=6)
			month = June;
		if(x=7)
			month = July;
		if(x=8)
			month = August;
		if(x=9)
			month = September;
		if(x=10)
			month = October;
		if(x=11)
			month = November;
		if(x=12)
			month = December;
	}
	
	int outputmonth(Month month){
		if(month=January);
			
	}
	
bool AddCategory(Category arr[],int arraySize, Category newCategory){
				
				for(int i=0;i<=arraySize;i++){	
					if(arr[i].Id[0] == '*'){
						
						strcpy(arr[i].Id, newCategory.Id);				
						strcpy(arr[i].Name, newCategory.Name);
					break;
					}
				}
				return true;	
}	

bool SaveCategory(Category arr[],int arraySize){
	ofstream categories;
	categories.open("Categories.csv");
	
	for(int i=0;i<arraySize;i++){	
		if(arr[i].Id[0]!='*' && arr[i].Id[0]!='\0'){
			categories<<arr[i].Id<<",";
			categories<<arr[i].Name<<endl;	
		}
			
	}
}

bool loadCategories(Category arr[], int arraySize){
	ifstream categories;
	categories.open("Categories.csv");
		
	Category newCategory;
	

	while(categories.good())
	{
		
		categories.getline(newCategory.Id,MAX_CATEGORY_NUMBER,',');
		categories.getline(newCategory.Name,MAX_CATEGORY_NAME,'\n');

		AddCategory(arr,arraySize,newCategory);			
		
	}
	
	
}

void printCategories(Category arr[], int arraySize){

	
	cout<<setw(20)<<"Category Id"<<setw(20)<<"Name"<<endl;
	
	for(int i=0;i<=arraySize;i++){	
		
			if(arr[i].Id[0] != '*'){
				cout<<setw(20)<<arr[i].Id;
				cout<<setw(20)<<arr[i].Name;
			}
			
			else{
				break;
			}
			cout<<endl;
		}
	
}

bool isExist(Category arr[],int arraySize, char catId[]){
	
	for(int i = 0;i<arraySize;i++){
		if (strcmp(arr[i].Id,catId)==0){
			return true;
		}
	}
	
	return false;
}

bool editCategory(Category arr[],int arraySize,char catId[],Category newData){
		for (int i = 0; i<arraySize; i++){			
			if (strcmp(arr[i].Id,catId)==0){
				strcpy (arr[i].Id, newData.Id);
				strcpy (arr[i].Name, newData.Name);
				return true;
				break;
			}
		}
	return false;
}

bool deleteCategory(Category arr[], int arraySize, char catId[]){
	for (int i = 0; i<arraySize; i++){			
			if (strcmp(arr[i].Id,catId)==0){
				for(int j=0;j<MAX_CATEGORY_NUMBER;j++)
					arr[i].Id[j] ='*';
				for(int j=0;j<MAX_CATEGORY_NAME;j++)
					arr[i].Name[j] ='*';
				return true;	
				break;
			}
		}
	return false;
}

void readInCategory(Category& category){
	cout<<"Enter Category Id :";
	cin>>category.Id;
	cout<<"Enter Category Name :";
	cin>>category.Name;
}

bool isExist(Book arr[], int arraySize, char bookId[]){
	
	for(int i = 0;i<arraySize;i++){
		if (strcmp(arr[i].Id,bookId)==0){
			return true;
		}
	}
	
	return false;
	
}

bool addBook(Book arr[], int arraySize, Book newBook){
	
				
				for(int i=0;i<=arraySize;i++){	
				
					if(arr[i].Id[0] == '*' || arr[i].Name[0]=='\0'){						
						strcpy(arr[i].Id, newBook.Id);				
						strcpy(arr[i].Name, newBook.Name);
						arr[i].Edition=newBook.Edition;
					break;
					}
				}
				return true;
}

bool deleteBook (Book arr[], int arraySize, char bookId[]){
	for (int i = 0; i<arraySize; i++){			
			if (strcmp(arr[i].Id,bookId)==0){
				
				for(int j=0;j<MAX_BOOK_ID;j++)
					arr[i].Id[j] ='*';
				for(int j=0;j<MAX_BOOK_NAME;j++)
					arr[i].Name[j] ='*';					
				arr[i].Edition = 0;
				return true;	
				break;
			}
		}
	return false;
}

void printBooks(Book arr[], int arraySize){
	
	cout<<setw(20)<<"Book Id"<<setw(20)<<"Name"<<setw(20)<<"Edition"<<setw(20)<<"Category"<<endl;

	
	for(int i=0;i<arraySize;i++){	
		
			if(arr[i].Id[0] != '*' && arr[i].Id[0]!='\0'){
				cout<<setw(20)<<arr[i].Id;
				cout<<setw(20)<<arr[i].Name;
				cout<<setw(20)<<arr[i].Edition;
				
			}
			else{
				break;
			}
			cout<<endl;

	}
}

bool saveBooks(Book arr[], int arraySize){
	ofstream books;
	books.open("Books.csv");
	
	for(int i=0;i<arraySize;i++){
		
		if(arr[i].Id[0]!='*' && arr[i].Id[0]!= '\0'){
			books<<arr[i].Name<<",";
			books<<arr[i].Edition<<",";
			books<<arr[i].Id<<endl;
				
		}
			
	}
}

bool loadBooks(Book arr[], int arraySize){
	
	
	ifstream books;
	books.open("Books.csv");
		
	Book newBook;

	while(books.good())
	{
		books.getline(newBook.Name,MAX_BOOK_NAME,',');
		books>>newBook.Edition;
		books.ignore(1,',');
		books.getline(newBook.Id,MAX_BOOK_ID,'\n');
	
		addBook(arr,arraySize,newBook);			
		
	}	
}

bool editBook(Book arr[], int arraySize, char bookId[], Book newData){
	
	

	for (int i = 0; i<arraySize; i++){
				
			if (strcmp(arr[i].Id,bookId)==0){
				strcpy (arr[i].Id, newData.Id);
				strcpy (arr[i].Name, newData.Name);
				arr[i].Edition = newData.Edition;
				return true;
				break;
			}
		}
	return false;
	
}
void readInBook(Book& book){
	cout<<"Enter New Book Id :";
	cin>>book.Id;
	cout<<"Enter New Book Name :";
	cin>>book.Name;
	cout<<"Enter New Book Edition :";
	cin>>book.Edition;
}

bool isExist(BookCopy arr[], int arraySize, char copyId[]){
		for(int i = 0;i<arraySize;i++){
		if (strcmp(arr[i].Id,copyId)==0){
			return true;
		}
	}
	
	return false;
	
}

bool addBookCopy(BookCopy arr[], int arraySize, BookCopy newBookCopy){
		
				for(int i=0;i<=arraySize;i++){	
					if(arr[i].Id[0] == '*' ){						
						strcpy(arr[i].Id, newBookCopy.Id);					
						arr[i].PurchaseDate=newBookCopy.PurchaseDate; 
					
					break;
					}
				}
				return true;
}

void readInBookCopy(BookCopy &bookCopy){
	int x;
	cout<<"Enter Book Copy Id :";
	cin>>bookCopy.Id;
	cout<<"Enter Book copy Purchase Day:";
	cin>>bookCopy.PurchaseDate.Day;
	cout<<"Enter Book copy Purchase Month:";
	cin>>x;
	inputmonth(x,bookCopy.PurchaseDate.month);
	
	cout<<"Enter Book copy Purchase Year:";
	cin>>bookCopy.PurchaseDate.Year;
}

void printBookCopies(BookCopy arr[], int arraySize, char bookId[]){
	
		cout<<right<<setw(20)<<"Book Id"<<setw(20)<<"Date"<<endl;
	
		for(int i=0;i<arraySize;i++){	
		
				if(arr[i].Id[0] != '*' && arr[i].Id[0]!='\0'){
					cout<<right<<setw(20)<<arr[i].Id;
					cout<<setw(20);
					cout<<arr[i].PurchaseDate.Day<<"-"<<arr[i].PurchaseDate.month<<"-"<<arr[i].PurchaseDate.Year;
				}
				else{
					break;
					}
			
				cout<<endl;
			}
}

bool loadBookCopies(BookCopy arr[], int arraySize){
	
	ifstream bookcopy;
	bookcopy.open("BookCopy.csv");
		
	BookCopy newBookCopy;

	while(bookcopy.good())
	{
		int x;	
			
		bookcopy>>newBookCopy.PurchaseDate.Day;
		bookcopy.ignore(1,',');
		bookcopy>>x;
		inputmonth(x,newBookCopy.PurchaseDate.month);
		bookcopy.ignore(1,',');
		bookcopy>>newBookCopy.PurchaseDate.Year;
		bookcopy.ignore(1,',');
		bookcopy.getline(newBookCopy.Id,MAX_COPY_NUMBER,'\n');
	
		cout<<endl;
		
		addBookCopy(arr,arraySize,newBookCopy);			
		
	}	
}

bool saveBookCopies(BookCopy arr[], int arraySize){

	ofstream bookcopy;
	bookcopy.open("BookCopy.csv");
	
	for(int i=0;i<arraySize;i++){
		if(arr[i].Id[0]!='*' && arr[i].Id[0]!= '\0'){
			bookcopy<<arr[i].PurchaseDate.Day<<",";
			bookcopy<<arr[i].PurchaseDate.month<<",";
			bookcopy<<arr[i].PurchaseDate.Year<<",";
			bookcopy<<arr[i].Id<<endl;
				
		}
			
	}
	
}

bool editBookCopy(BookCopy arr[], int arraySize, char bookCopyId[], BookCopy newData){
	
	for (int i = 0; i<arraySize; i++){			
			if (strcmp(arr[i].Id,bookCopyId)==0){
				strcpy (arr[i].Id, newData.Id);
				arr[i].PurchaseDate = newData.PurchaseDate;
				return true;
				break;
			}
		}
	return false;

}

bool deleteBookCopy(BookCopy arr[], int arraySize, char bookCopyId[]){
	for (int i = 0; i<arraySize; i++){			
			if (strcmp(arr[i].Id,bookCopyId)==0){
				for(int j=0;j<MAX_COPY_NUMBER;j++)
					arr[i].Id[j] ='*';
					
				arr[i].PurchaseDate.Day =0;					
				arr[i].PurchaseDate.Year =0;
				return true;	
				break;
			}
		}
	return false;
}

bool isExist(Student arr[],int arraySize, char regNo[]){
	for(int i = 0;i<arraySize;i++){
		if (strcmp(arr[i].RegistrationNo,regNo)==0){
			return true;
		}
	}
	
	return false;
}

bool addStudent(Student arr[],int arraySize, Student newStudent){
	
				for(int i=0;i<=arraySize;i++){	
					if(arr[i].RegistrationNo[0] == '*' ){						
						strcpy(arr[i].RegistrationNo, newStudent.RegistrationNo);
						strcpy(arr[i].Name, newStudent.Name);				
						arr[i].Session = newStudent.Session;
						arr[i].AdmissionDate = newStudent.AdmissionDate;
					break;
					}
				}
				return true;
}

bool editStudent(Student arr[],int arraySize,char regNo[], Student newData){	

	for (int i = 0; i<arraySize; i++){	
			
			if (strcmp(arr[i].RegistrationNo,regNo)==0){
				strcpy (arr[i].RegistrationNo, newData.RegistrationNo);
				strcpy(arr[i].Name, newData.Name);				
				arr[i].Session = newData.Session;
				arr[i].AdmissionDate = newData.AdmissionDate;
				return true;
				break;
			}
		}
	return false;
}

bool deleteStudent(Student arr[], int arraySize, char regNo[]){
	for (int i = 0; i<arraySize; i++){			
			if (strcmp(arr[i].RegistrationNo,regNo)==0){
				for(int j=0;j<MAX_REGISTRATION_NUMBER;j++)
					arr[i].RegistrationNo[j] ='*';
				for(int j=0;j<MAX_STUDENT_NAME;j++)
					arr[i].Name[j] ='*';
					
					arr[i].Session = 0;
					arr[i].AdmissionDate.Day =0;					
					
					arr[i].AdmissionDate.Year =0;
				return true;	
				break;
			}
		}
	return false;
}

void printStudents(Student arr[], int arraySize){
	
		
	cout<<setw(20)<<"Registration No"<<setw(20)<<"Name"<<setw(20)<<"Session"<<endl;
	
	for(int i=0;i<arraySize;i++){	
		
			if(arr[i].RegistrationNo[0] != '*' && arr[i].RegistrationNo[0]!='\0'){
				cout<<setw(20)<<arr[i].RegistrationNo;
				cout<<setw(20)<<arr[i].Name;
				cout<<setw(20)<<arr[i].Session;
				cout<<arr[i].AdmissionDate.Day<<"-"<<arr[i].AdmissionDate.month<<"-"<<arr[i].AdmissionDate.Year;
			}
			else{
				break;
			}
			cout<<endl;
		}
	
}

bool loadStudents(Student arr[], int arraySize){
	
		ifstream students;
		students.open("Students.csv");
			
		Student newStudent;
	
		while(students.good())
		{
			int x;
			
			students>>newStudent.AdmissionDate.Day;
			students.ignore(1,',');
			students>>x;
			inputmonth(x, newStudent.AdmissionDate.month);
			students.ignore(1,',');
			students>>newStudent.AdmissionDate.Year;
			students.ignore(1,',');
			students>>newStudent.Session;
			students.ignore(1,',');
			students.getline(newStudent.Name,MAX_STUDENT_NAME,',');
			students.getline(newStudent.RegistrationNo,MAX_REGISTRATION_NUMBER,'\n');
		
			cout<<endl;
			
			addStudent(arr,arraySize,newStudent);	
		}
}

bool saveStudents(Student arr[], int arraySize){
	ofstream students;
	students.open("Students.csv");
	
	for(int i=0;i<arraySize;i++){
		
		if(arr[i].RegistrationNo[0]!='*' && arr[i].RegistrationNo[0]!= '\0'){
			students<<arr[i].AdmissionDate.Day<<",";
			students<<arr[i].AdmissionDate.month<<",";
			students<<arr[i].AdmissionDate.Year<<",";
			students<<arr[i].Session<<",";
			students<<arr[i].Name<<",";
			students<<arr[i].RegistrationNo<<endl;
			
		}
			
	}
}

void readInStudent(Student &student){
	int x;
	cout<<"Enter Student Registraion No :";
	cin>>student.RegistrationNo;
	cout<<"Enter Student Name :";
	cin>>student.Name;
	cout<<"Enter Student Session :";
	cin>>student.Session;
	cout<<"Enter Student Admission Day:";
	cin>>student.AdmissionDate.Day;
	cout<<"Enter Student Admission Month:";
	cin>>x;
	inputmonth(x,student.AdmissionDate.month);
	cout<<"Enter Book copy Purchase Year:";
	cin>>student.AdmissionDate.Year;
}


int main()
{

	int arraysize=100;
	
	BookIssue bookissuearr[30];
	BookIssue newBookissue;
	User userarr[20];
	User
	
	
	 newuser;
	
	int mainOption;
	char subOption;
	
	Category newCategory;
	Category arr[MAX_CATEGORIES];
	char catid[MAX_CATEGORY_NUMBER];
	
	Book newBook;
	Book Bookarr[100];
	char bookid[MAX_BOOK_ID];
	
	BookCopy newBookCopy;
	BookCopy Bookcopyarr[100];
	char bookcopyid[MAX_COPY_NUMBER];
	
	Student studentarr[MAX_STUDENTS];
	Student newStudent;
	char studentregno[MAX_REGISTRATION_NUMBER];
	
	
	
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			userarr[i].UserName[j]='*';
			userarr[i].password[j]='*';
		}
	}
	
	
login:	while(1){
		system("CLS");
		loadUser(userarr,20);
		cout<<"Username = Hasan"<<endl;
		cout<<"Password = 123"<<endl;
		cout<<"Enter User name :";
		cin>>newuser.UserName;
		cout<<"Enter Password :";
		cin>>(newuser.password);
		
		if(isValidemailId(newuser.UserName)==false){
			cout<<"Not Vaild email Id !";
		}
		
		if(findUser(userarr,20,newuser)==true)
			break;
		else
			cout<<"Wrong UserName and password"<<endl;
	}
	
			do{
				
				for(int i=0;i<MAX_CATEGORIES;i++){
					for(int j=0;j<MAX_CATEGORY_NUMBER;j++){
						arr[i].Id[j]='*';
					}
				}
					
				for(int i=0;i<MAX_CATEGORIES;i++)
					for(int j=0;j<=MAX_CATEGORY_NAME;j++)
						arr[i].Name[j]='*';
				
				for(int i=0;i<arraysize;i++){
					for(int j=0;j<=MAX_BOOK_ID;j++){
						Bookarr[i].Id[j]='*';
					}
				}
				
				for(int i=0;i<MAX_BOOKS;i++)
					for(int j=0;j<=MAX_BOOK_NAME;j++)
						Bookarr[i].Name[j]='*';
						
				for(int i=0;i<MAX_BOOKS;i++){
					Bookarr[i].Edition=0;
				}		
					
				for(int i=0;i<arraysize;i++){
					for(int j=0;j<=MAX_CATEGORY_NAME;j++)
						Bookcopyarr[i].Id[j]='*';
				}
			
				for(int i=0;i<arraysize;i++){
					Bookcopyarr[i].PurchaseDate.Day=0;
					Bookcopyarr[i].PurchaseDate.Year=0;
				}
				
				for(int i=0;i<MAX_STUDENTS;i++){
					for(int j=0;j<=MAX_REGISTRATION_NUMBER;j++)
						studentarr[i].RegistrationNo[j]='*';
						
					for(int j=0;j<=MAX_STUDENT_NAME;j++)
						studentarr[i].Name[j]='*';
					
					studentarr[i].AdmissionDate.Day=0;
					studentarr[i].AdmissionDate.Year=0;
					
				}
				for(int i=0;i<30;i++){
					for(int j=0;j<=MAX_REGISTRATION_NUMBER;j++)
						bookissuearr[i].regNo[j] ='*';
				}
				
				PrintMenu();
			
				loadCategories(arr,arraysize);
				loadBooks(Bookarr,arraysize);
				loadBookCopies(Bookcopyarr,arraysize);
				loadStudents(studentarr,MAX_STUDENTS);
				loadBookIssue(bookissuearr,30);
			
				cin>>mainOption>>subOption;
				
				switch(mainOption){
					case 1:	
							if(subOption=='A'){	
							
							readInCategory(newCategory);
								
								if((isValidCategoryNumber(newCategory.Id)==false) || (isValidCategoryName(newCategory.Name)==false))
									cout<<"Not Valid Category Name or Number";
								
								else{
								
									AddCategory(arr,MAX_CATEGORIES,newCategory);
									cout<<"Category Added Successfully";						
								}
							}				
							if(subOption=='L'){
								
								printCategories(arr,MAX_CATEGORIES);
							}
							if(subOption=='E'){
								cout<<"Enter Category Id to Edit : "<<endl;
								cin>>catid;
								if(isExist(arr,MAX_CATEGORIES,catid)==true){
									
									readInCategory(newCategory);
									editCategory(arr,MAX_CATEGORIES,catid,newCategory);
								}
								else{
									cout<<"Category does not exist";
								}					
							}
							if(subOption=='D'){
								
								cout<<"Enter Category Id to Delete : "<<endl;
								cin>>catid;
								
								if(isExist(arr,MAX_CATEGORIES,catid)==true){
									
									deleteCategory(arr,MAX_CATEGORIES,catid);
									cout<<"Category deleted Successfully";
								}
							}
							break;
					case 2:
							if(subOption=='A'){		
								readInBook(newBook);
									
									if((isValidBookId(newBook.Id)==false) || (isValidBookName(newBook.Name)==false)){
									
										cout<<"Not Valid Book Name or Id";
										break;
									}
									else if(isExist(Bookarr,MAX_BOOKS,newBook.Id)==true){
										cout<<"Book already exist.";
										break;
									}
									
									else{
									
										addBook(Bookarr,MAX_BOOKS,newBook);
										cout<<"Book has been successfully added";						
									}
								}
							if(subOption=='E'){
								cout<<"Enter Book Id to Update : "<<endl;
								cin>>bookid;
								if(isExist(Bookarr,MAX_BOOKS,bookid)==true){
									
									readInBook(newBook);
									editBook(Bookarr,MAX_BOOKS,bookid,newBook);
									cout<<"Book Updated Successfully";
								}
								else{
									cout<<"Book Id does not exist";
								}					
							}
							if(subOption=='L'){
								printBooks(Bookarr,MAX_BOOKS);
							}
							if(subOption=='D'){
								cout<<"Enter Book Id to Delete : "<<endl;
								cin>>bookid;
								
								if(isExist(Bookarr,MAX_BOOKS,bookid)==true){
									cout<<"Book deleted Successfully";
									deleteBook(Bookarr,MAX_BOOKS,bookid);
									
								}
								else{
									cout<<"Book cannot be deleted id was not found";
								}
							}	
							break;
						
					case 3:
							if(subOption=='A'){
			
								readInBookCopy(newBookCopy);
								
								if(isValidCopyNumber(newBookCopy.Id)==false) 
									cout<<"wrong id";
								else if(isValidDate(newBookCopy.PurchaseDate)==false)
									cout<<"Not Valid Book copy Date";
								
								else{
								
									addBookCopy(Bookcopyarr,arraysize,newBookCopy);
									cout<<"Book Copy Added Successfully";						
								}
							}
							if(subOption=='L')
								printBookCopies(Bookcopyarr,arraysize,bookcopyid);
							if(subOption=='E'){
								cout<<"Enter Book Copy Id to Update : "<<endl;
								cin>>bookcopyid;
								if(isExist(Bookcopyarr,arraysize,bookcopyid)==true){
									readInBookCopy(newBookCopy);
									editBookCopy(Bookcopyarr,arraysize,bookcopyid,newBookCopy);
									cout<<"Book Copy Updated Successfully";
								}
								else{
									cout<<"Book Copy does not exist";
								}					
							}
							if(subOption=='D'){
								cout<<"Enter Book Copy Id to Delete : "<<endl;
								cin>>bookcopyid;
								
								if(isExist(Bookcopyarr,arraysize,bookcopyid)==true){
									cout<<"Book Copy deleted Successfully";
									deleteBookCopy(Bookcopyarr,arraysize,bookcopyid);
									
								}
								else{
									cout<<"Book Copy cannot be deleted it was not found";
								}
							}
							break;		
					case 4:
							if(subOption=='A'){	
							
							readInStudent(newStudent);
								
								if(isValidRegistrationNo(newStudent.RegistrationNo)==false)
									cout<<"Not Valid Student Registration No";
								else if(isValidStudentName(newStudent.Name)==false){
									cout<<"Not Valid Student Name";
								}
								else if((isExist(studentarr,MAX_STUDENTS,newStudent.RegistrationNo)==true)){
									cout<<"Student Registraion No already Exist";
								}
								else{
								
									addStudent(studentarr,MAX_STUDENTS,newStudent);
									cout<<"Student Added Successfully";						
								}
							}
							if(subOption=='E'){
								cout<<"Enter Student Reg No to Update : "<<endl;
								cin>>studentregno;
								if(isExist(Bookarr,MAX_STUDENTS,bookid)==true){
									
									readInStudent(newStudent);
									editStudent(studentarr,MAX_STUDENTS,studentregno,newStudent);
									cout<<"Student Record Updated Successfully";
								}
								else{
									cout<<"Student reg no does not exist";
								}					
							}
							if(subOption=='L'){
							printStudents(studentarr,MAX_STUDENTS);
						}
							if(subOption=='D'){
								cout<<"Enter Student Reg No to Delete : "<<endl;
								cin>>studentregno;
								
								if(isExist(studentarr,MAX_STUDENTS,studentregno)==true){
									cout<<"Student Record deleted Successfully";
									deleteStudent(studentarr,MAX_STUDENTS,studentregno);
									
								}
								else{
									cout<<"Student Record cannot be deleted it was not found";
								}
							}
						break;
					case 5:
							if(subOption=='I')
								issueBook(bookissuearr,30, newBookissue);
							if(subOption=='R'){
							cout<<"Enter the copy id to return:";
							cin>>bookcopyid;
							if(isValidCopyNumber(bookcopyid)==true)
								returnBook(bookissuearr,30, bookcopyid);
							else
								cout<<"Not Valid Copy number";
						}
							if(subOption=='B'){
							cout<<"Enter the Copy Id of the book:";
							cin>>bookcopyid;
							if(isValidCopyNumber(bookcopyid)==true)
								checkBookStatus(bookissuearr,Bookcopyarr, 30, arraysize, bookcopyid);
							else
								cout<<"Not Valid Copy number";
								
						}
							if(subOption=='S'){
							cout<<"Enter the registration Number of student: ";
							cin>>studentregno;
							if(isValidRegistrationNo(studentregno)==true)
								studentCurrentBook(bookissuearr,30,studentregno);
							else{
								cout<<"Wrong Registration Number";
							}
						}
				}
				 
					SaveCategory(arr,MAX_CATEGORIES);
					saveBooks(Bookarr,MAX_BOOKS);
					saveBookCopies(Bookcopyarr,arraysize);
					saveStudents(studentarr,MAX_STUDENTS);
					saveBookIssue(bookissuearr,30);
					
					cout<<endl;
					
					if(mainOption == 9 && subOption == 'L' )
						goto login;
			}while(mainOption!=0 && subOption!='E');
		
		
	return 0;
		
}
	

