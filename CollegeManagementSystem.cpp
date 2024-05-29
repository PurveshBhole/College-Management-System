#include<iostream>
#include<vector> // vector-- dynamic arrays 
#include<stdio.h> 
#include<cstring> // cstring--> string manupulation
#include<fstream> // fsstring --> file handling 
using namespace std;

class student 
{
	public:
		long int reg;  // roll no
		char name[80],branch[50];
		void input()
		{
			cout<<"\n Enter name: ";
			gets(name);  //stdio headder file
			cout<<"\n Enter roll no: ";
			cin>>reg;
			fflush(stdin);
			cout<<"\n Enter Branch: ";
			gets(branch);
		}
		void display()
		{
			system("CLS");
			cout<<"\t\tDisplay Records";
			cout<<"\n";
			cout<<"\n Name - "<<name;
			cout<<"\n Reg no. - "<<reg;
			cout<<"\n Branch - "<<branch;
			cout<<"\n";
			system("PAUSE"); 
			system("CLS");
		}
	
};

vector <student>v;

int search_reg(long int reg,int &i);
void get_file()
{
	student x;
	int i=0;
	ifstream f("College.txt");
	if(f.is_open())
	{
		while(f.read((char *)&x,sizeof(class student)))  
		{
			v.push_back(x);
		}
		f.close();
	} 
	else
		cout<<"error opening the file:"; 
}

void bubblesort()
{
	int i,j;
	student x;
	for(i=0;i<v.size();i++)
		for(j=0;j<v.size()-i-1;j++)
			if(v[j].reg>v[j+1].reg)
			{
				x=v[j];
				v[j]=v[j+1];
				v[j+1]=x;
			}
				
}
void insert_new()
{
	char ch='y';
	int ta;
	while(ch=='y')
	{
		fflush(stdin); // CLEARS ALL CHARACTERS IN INPU
		student x; // OBJECT X
		x.input();
		if(search_reg(x.reg,ta)==0)
			v.push_back(x); // if ta=0 then only insert values in v;
		else
			cout<<"\nTHE REGISTRATION NO. ALREADY EXIST!!!\nCANNOT ADD";
		cout<<"\n Press [Y] to enter more: ";

		// press y to enter more
		cin>>ch;
		if(ch != 'y') break;
		fflush(stdin);
	}
}
void write_file()
{
	bubblesort(); // arranges all the data in ascending order of roll no using bubble sort algorithm
	ofstream f("College.txt");  // write mode offstream
	if(f.is_open()) 
	{
		for(int i=0;i<v.size();i++)
		{ 
			student x=v[i];
			f.write((char *) &x,sizeof(class student)); // syntax for writting file
		}
		f.close();
	} 
	else
	{
		cout<<"error opening the file: ";
	}
} 

int search_reg(long int reg,int &i) 
{ 
	// linear search
	int ta=0;
	for(i=0;i<v.size();i++)
		if(v[i].reg==reg)
		{
			ta=1;
			break;
		}
	return ta;
}
int search_name(char name[],vector<int> &vi)
{ 
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].name,name)==0)
		{
			ta=1;
			vi.push_back(i);
		}
	return ta;
}
int search_branch(char branch[],vector<int> &vj)
{ 
	int i,ta=0;
	for(i=0;i<v.size();i++)
		if(strcmp(v[i].branch,branch)==0)
		{
			ta=1;
			vj.push_back(i);
		}
	return ta;
}
void search_and_show()
{
	int ch,i,ta=0;
	char name[80],branch[50];
	vector <int>vi; 
	vector <int>vj;
	long int reg;

	poi: //point of installatioN

	cout<<"\n1.Press to search reg no."
	<<"\n2.Press to search name"
	<<"\n3.Press to search branch";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\nEnter reg no.: ";
			cin>>reg;
			if(search_reg(reg,i)==1)
				v[i].display();
			else
				cout<<"\nRecord NOT FOUND!!!";
			break;
		case 2:
			cout<<"\nEnter name: "; // v[i] for name
			fflush(stdin);
			gets(name);
			if(search_name(name,vi)==1)
			{
				for(int j=0;j<vi.size();j++)
					v[vi[j]].display();
			}
			else
				cout<<"\nRecord NOT FOUND!!!";
			break;
		case 3:
			cout<<"\nEnter branch: ";
			fflush(stdin);
			gets(branch);
			if(search_branch(branch,vj)==1) // v[j] branch
			{
				for(int j=0;j<vj.size();j++)
					v[vj[j]].display();
			}
			else
				cout<<"\nRecord NOT FOUND!!!";
			break;
		default:
			cout<<"\nWrong CHOICE!!!";
			goto poi;
	}
}
void show()
{
	int i;
	for(i=0;i<v.size();i++)
		v[i].display();
}

void delete_data()
{
	int i,j;
	long int reg;
	vector <student>::iterator p=v.begin(); // value of vector v at index 0
	cout<<"\nEnter Reg. no.: ";
	cin>>reg;
	if(search_reg(reg,i)==1)
	{
		student x=v[i]; // object x = v[i]
		
		cout<<"\nThe following data is being deleted";
		x.display();
		p+=i;
		v.erase(p,p+1);
	}
}
void edit_data()

{
	int i,j;
	long int reg;
	vector <student>vi;
	cout<<"\nEnter Reg. no.: ";
	cin>>reg;
	if(search_reg(reg,i)==1)
	{
		cout<<"\nEnter new data:";
		fflush(stdin);
		v[i].input();
	}
}

int main() 
{
	int i=1;
	get_file();
	while(i)  // always execute
	{
		system("CLS"); // screen clear
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\t\t\t     Simple College Management System\n";
		cout<<"\t\t\t-----------------------------------------\n";
		cout<<"\n\t\t\tEnter <1> to Add new student"
			<<"\n\t\t\tEnter <2> to Display all student"
			<<"\n\t\t\tEnter <3> to Remove student"
			<<"\n\t\t\tEnter <4> to Edit student"
			<<"\n\t\t\tEnter <5> to Search student"
			<<"\n\t\t\tEnter <0> to Exit\n";
		cout<<"\n\n\t\t\tEnter Your Choice:";	
		cin>>i;
		switch(i)
		{
			case 1 :
				insert_new();
				break;
			case 2 :
				show();
				break;
			case 3 :
				delete_data();
				break;
			case 4 :
				edit_data();
				break;
			case 5 :
				search_and_show();
				break;
			case 0 :
				write_file();
				break;
				
			default :
				cout<<"\nWRONG CHOICE!!!\nTRY AGAIN";
		}
	}
	return 0;
}