#include "Header.h"

void main()
{
	Military **P ;
	P= new Military*;
	int s = 0;
	int k;
	int t;
cout << "			W . E . L . C . O . M . E"<<endl << endl << endl << endl;
	while(1)
	{
	cout << "Enter Military  :1-yes ; 0-no" << endl;
	cin >> t;
	system("cls");
	switch (t)
	{
	case 1:
		cout << "Enter choise : 1->Subaltern	2->Senior officers	3->Higher officers " << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			Military **tmpP = P;
			P = new Military*[s + 1];
			P[s] = new Subaltern;
			P[s]->inputMilitary();
			for (int i = 0;i < s;i++)
			{
				P[i] = tmpP[i];
			}
			s++;
			break;
		}
		case 2:
		{
			Military **tmpP = P;
			P = new Military*[s + 1];
			P[s] = new Senior_officers;
			P[s]->inputMilitary();
			for (int i = 0;i < s;i++)
			{
				P[i] = tmpP[i];
			}
			s++;
			break;
		}
		case 3:
		{
			Military **tmpP = P;
			P = new Military*[s + 1];
			P[s] = new Higher_officers;
			P[s]->inputMilitary();
			for (int i = 0;i < s;i++)
			{
				P[i] = tmpP[i];
			}
			s++;
			break;
		}
		default:
			break;
		}
		//tmpP= P;
		
	case 0:
		break;

	}
	if (!t)
		break;
	}
	system("cls");
	for (int i = 0;i < s;i++)
	{
		P[i]->Print();
	}
	int x;
	cout<<"If you want to search:\n1->part-number	\n2->Corps(rid_viusk)		\n3->If you want to install a new location service\n4->Exit"<<endl;
	cin>>x;
	switch (x)
	{
	case 1:
		{
		cout<<"Enter number of part"<<endl;
		int temp;
		cin>>temp;
		for (int i = 0;i < s;i++)
	{
		P[i]->location_service(temp);
	}
		break;
		}
	case 2:
		{
			char str[20];
		cout<<"Enter corps: "<<endl;
		cin>>str;
		for (int i = 0;i < s;i++)
	{
		P[i]->location_service(str);
	}
			break;
		}
	case 3:
		{
			int choise;
			int newint;
			char newchar[20];
			cout<<"Enter number of part"<<endl;
			cin>>newint;
			cout<<"Enter corps: "<<endl;
			cin>>newchar;
			cout<<"Choose the military who want to install a new location service:"<<endl;
			cin>>choise;
			P[choise]->location_service(newint,newchar);
			break;
		}
	case 4:
		{
		system("pause");
		exit(0);
		break;
		}
	default:
		break;
	}
	
	system("pause");
}