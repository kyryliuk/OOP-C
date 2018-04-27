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
	int lifetime;																					//����� ������
	int year;																						//�� ����������
	int part_number;																				//����� �������
	char* ridviusk;																					//�� �����							
protected:     vector<string>military_rank;															//���� ������					
public:
	char* name;																						//���
	friend bool operator> (const Military & tmp, const Military & tmp_1);							//����������
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
		void location_service(int _number)	;													//�������������� �����
		void location_service(char *_ridniusk)	;												//�������������� �����
		void location_service(int tmp, char* tmp_1)		;										//�������������� �����
	};
class Subaltern : virtual public Military														//�������� ����������� �����
{
private:
	int salary_subaltern;
public:
	Subaltern();
	Subaltern(int _salary) ;
	~Subaltern();
	void inputMilitary();
	void Print();																				//������������� ����
};
class Senior_officers : virtual public Military													//������ �������
{
private:
	int sub_units;																				//������� �������������� ������
public:
	Senior_officers();
	Senior_officers(int _sub_units);
	~Senior_officers() ;
	void inputMilitary();
	void Print();																				//������������� ����
};
class Higher_officers : virtual public Military													//���� �������
{
private:
	int service_experience;																		//���� ������
	bool availability_pensions;																	//�������� ����
public:
	Higher_officers(int _service_experience) ;
	Higher_officers();
	~Higher_officers();
	void inputMilitary();
	void Print();																				//������������� ����
};
