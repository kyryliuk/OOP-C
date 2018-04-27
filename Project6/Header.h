#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <vector>
#include<algorithm>
using namespace std;

class Military
{
private:
	int lifetime;																					//строк служби
	int year;																						//вік військового
	int part_number;																				//номер частини
	char* ridviusk;																					//рід військ							
protected:     vector<string>military_rank;															//воєне звання					
public:
	char* name;																						//імя
	friend bool operator> (const Military & tmp, const Military & tmp_1);							//перегрузка
	friend bool operator== (const Military & tmp, const Military & tmp_1);
	friend bool operator< (const Military & tmp, const Military & tmp_1);
	friend ostream & operator<< (ostream & cout, Military * tmp);
	Military & Military::operator=(const Military & tmp);
	Military();
	Military(int _number,int _year, char *upd_Name,  char *input_str, char *_str) ;
	virtual	~Military() {}
	
	char* get_Name();
	char *get_Ridviusk();
	int get_Number();
	int get_Year();
	virtual void inputMilitary();
	virtual void Print();
		void location_service(int _number)	;													//перевантажений метод
		void location_service(char *_ridniusk)	;												//перевантажений метод
		void location_service(int tmp, char* tmp_1)		;										//перевантажений метод
	};
class Subaltern : virtual public Military														//Молодший офіцерський склад
{
private:
	int salary_subaltern;
public:
	Subaltern();
	Subaltern(int _salary) ;
	~Subaltern();
	void inputMilitary();
	void Print();																				//перевизначена функ
};
class Senior_officers : virtual public Military													//старші офіцери
{
private:
	int sub_units;																				//кількість підпорядкованих загонів
public:
	Senior_officers();
	Senior_officers(int _sub_units);
	~Senior_officers() ;
	void inputMilitary();
	void Print();																				//перевизначена функ
};
class Higher_officers : virtual public Military													//Вищі офіцери
{
private:
	int service_experience;																		//стаж служби
	bool availability_pensions;																	//наявність пенсії
public:
	Higher_officers(int _service_experience) ;
	Higher_officers();
	~Higher_officers();
	void inputMilitary();
	void Print();																				//перевизначена функ
};
