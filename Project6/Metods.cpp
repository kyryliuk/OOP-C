#include "Header.h"
//перегрузка
bool operator== (const Military & tmp, const Military & tmp_1)
{
	return tmp.part_number == tmp_1.part_number;
}
bool operator> (const Military & tmp, const Military & tmp_1)
{
	return tmp.part_number> tmp_1.part_number;
}
bool operator< (const Military & tmp, const Military & tmp_1)
{
	return tmp_1 > tmp;
}

ostream & operator<< (ostream & cout, Military * tmp)//херня працює неправильно
{
	cout << left << setw(20) <<"Name:-> "<<tmp-> get_Name() << endl ;
	cout << left << setw(20) <<"Corps:->"<<tmp->get_Ridviusk() << endl ;
	cout << left << setw(20) <<"Year:-> "<<tmp->get_Year() << endl ;
	cout << left << setw(20) <<"Number:->"<<tmp->get_Number() << endl ;
	cout << left << setw(20) <<"Military rank:->"<<tmp->military_rank[0] << endl ;
	return cout;
}

Military & Military::operator=(const Military & tmp)
{
	part_number = tmp.part_number;
	year = tmp.year;
	ridviusk = new char[strlen(tmp.ridviusk)+1];
	strcpy(ridviusk,tmp.ridviusk);
	name = new char[strlen(tmp.name)+1];
	strcpy(name,tmp.name);
	return *this;
}
Military::Military(int _number,int _year, char *upd_Name,  char *input_str, char *_str) : year(_year) ,part_number(_number)
	{
		name = new char[strlen(input_str)+1];strcpy(name, input_str); 
		ridviusk = new char[strlen(_str)+1];  strcpy(ridviusk, _str);
	}
Military::Military()
{ lifetime=0; year = 0;part_number=0;ridviusk=NULL; name = NULL; }
 void Military::inputMilitary()//вводить дані
	{
		char input_str[40];
		char input_str1[40];
		cout << "Name:-> " << endl;
		cin >> input_str;
		name = new char[strlen(input_str)+1];
		strcpy(name,input_str);
		cout << "Enter year:-> " << endl;
		cin >> year;
		cout<<"Enter number of part:-> "<<endl;
		cin>>part_number;
		cout << "Corps:-> " << endl;
		cin >> input_str1;
		ridviusk = new char[strlen(input_str1)+1];
		strcpy(ridviusk,input_str1);
		cout<<endl;
	}
 void Military:: Print()//друкує 
	{
		cout <<left << setw(20) <<"Name:-> "<< get_Name() << endl <<left << setw(20) <<"Corps:->"<<get_Ridviusk()<<endl<<left << setw(20) <<"Year:-> "<< year << endl<<left << setw(20) <<"Number:->"<<part_number<<endl<<left << setw(20) <<"Military rank:->"<< military_rank[0] <<endl ;
	
	}
 char* Military::get_Name()
	{
		return name;
	}
	char *Military::get_Ridviusk()
	{
		return ridviusk;
	}
	int Military::get_Number()
	{
		return part_number;
	}
	int Military:: get_Year()
	{
		return year;
	}
																									//перегрузка методів
	void Military::location_service(int _number)													//перевантажений метод
	{
		if(_number==part_number)
		{
			cout<<"The correct number, than corps:-> "<< get_Ridviusk()<<endl;
		}
		else
		{
		cout<<"Wrong number"<<endl;
		}
	}
void Military::location_service(char *_ridniusk)													//перевантажений метод
{
	char* temp = new char[strlen(_ridniusk)+1];
  int t=0;
 
   for(int i=0; i<strlen(ridviusk); i++)
   {
     while(get_Ridviusk()[i]==_ridniusk[t])
       temp[t++] = ridviusk[i++];
      temp[t] = '\0';
       t=0;
	   if(strcmp(temp,_ridniusk)==0) 
	   {
		  cout<<"Number:-> "<< get_Number();
	   }
	   else
		   cout<<"Wrong  ridniusk"<<endl;
   }
}
void Military:: location_service(int tmp, char* tmp_1)									//перевантажений метод
	{	
		delete[]ridviusk;
		ridviusk=NULL;
		part_number=tmp;
		ridviusk = new char[strlen(tmp_1)+1];
		strcpy(ridviusk,tmp_1);
		cout<<"Location Service new: "<<endl;
		cout<<"Corps:->"<<get_Ridviusk()<< endl<<"Number:->"<<get_Number()<<endl ;
	}


void Subaltern:: inputMilitary()
	{
		Military::inputMilitary();
		cout << "Enter salary of subaltern:-> " << endl;
		cin >> salary_subaltern;
		cout<<"Choise subaltern military rank: \n1->Junior Lieutenant\n2->Lieutenant\n3->Senior Lieutenant\n4->Captain"<<endl;
		int l;
		cin>>l;
		switch (l)
		{
		case 1:
			{
				military_rank.push_back("Junior Lieutenant");
				break;
			}
		case 2:
			{
				military_rank.push_back("Lieutenant");
				break;
			}
		case 3:
			{
				military_rank.push_back("Senior Lieutenant");
				break;
			}
		case 4:
			{
				military_rank.push_back("Captain");
				break;
			}
		default:
			break;
		}
	}
void Subaltern:: Print()//перевизначена функ
	{
		Military::Print();
		cout <<left << setw(20) <<"Salary:-> "<< salary_subaltern<< endl<<endl;
	}
Subaltern:: Subaltern() { salary_subaltern=0; }
Subaltern:: Subaltern(int _salary) { salary_subaltern=_salary; }
Subaltern::~Subaltern() {  }

Senior_officers:: Senior_officers() { sub_units=0; }
Senior_officers:: Senior_officers(int _sub_units)
	{
		sub_units=_sub_units;
	}
Senior_officers:: ~Senior_officers() { }
void Senior_officers:: inputMilitary()
	{
	//	if(typeid(this)!=typeid(Senior_officers))
		Military::inputMilitary();
		cout << "Enter sub-units" << endl;
		cin >> sub_units;
		cout<<"Choise Senior officers military rank: \n1->Major\n2->Lieutenant colonel\n3->Colonel"<<endl;
		int l;
		cin>>l;
		switch (l)
		{
		case 1:
			{
				military_rank.push_back("Major");
				break;
			}
		case 2:
			{
				military_rank.push_back("Lieutenant colonel");
				break;
			}
		case 3:
			{
				military_rank.push_back("Colonel");
				break;
			}
		default:
			break;
		}
	}
void Senior_officers:: Print()//перевизначена функ
	{
	//	if (typeid(this) != typeid(Senior_officers))
		Military::Print();
		cout <<left << setw(20) <<"Sub-units:-> "<< sub_units << endl;
		cout<<endl;
	}


Higher_officers:: Higher_officers(int _service_experience) { service_experience = _service_experience; } 
Higher_officers:: Higher_officers() {}
Higher_officers::~Higher_officers() {}
void Higher_officers:: inputMilitary()
	{
	//	if(typeid(this)!=typeid(Senior_officers))
		Military::inputMilitary();
		cout << "Enter service experience" << endl;
		cin >> service_experience;
		cout<<"Enter availability pensions "<<endl;
		cin>>availability_pensions;
		cout<<"Choise subaltern military rank: \n1->Major General\n2->Lieutenant General\n3->General Colonel\n4->Army General of Ukraine"<<endl;
		int l;
		cin>>l;
		switch (l)
		{
		case 1:
			{
				military_rank.push_back("Major General");
				break;
			}
		case 2:
			{
				military_rank.push_back("Lieutenant General");
				break;
			}
		case 3:
			{
				military_rank.push_back("General Colonel");
				break;
			}
		case 4:
			{
				military_rank.push_back("Army General of Ukraine");
				break;
			}
		default:
			break;
		}
	}
void Higher_officers:: Print()//перевизначена функ
	{
	//	if (typeid(this) != typeid(Senior_officers))
		Military::Print();
		cout <<left << setw(20) << "Service experience:-> " << service_experience<<endl;
		cout<<left << setw(20) <<"Availability pensions :-> "<<availability_pensions<<endl<<endl;
	}