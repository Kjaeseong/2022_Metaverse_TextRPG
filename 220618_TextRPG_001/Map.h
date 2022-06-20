#pragma once
#include <iostream>

#include <iomanip>
#include "Player.h"
#include "Time.h"
using namespace std;


class Map : public Player, public Timer
{
public:
	void RandMap()
	{ 
		while (1)
		{
			if (pushHP() <= 0)
			{
				break;
			}
			switch (dice(1, 5))
			{
			case 1:
				stone();
				break;
			case 2:
				spear();
				break;
			case 3:
				lever();
				break;
			case 4:
				Quiz();
				break;
			case 5:
				battle();
				break;
			}

		}
	}

	void stone()
	{
		cout << "ū �����̰� �������� �ֽ��ϴ�.\n";
		cout << "1 ~ 3�� ����Ű�� ���� �ൿ�� �����ϼ���\n\n";
		cout << setw(15) << right << "1. ������ ���´�.\n";
		cout << setw(15) << right << "2. �������� ���´�.\n";
		cout << setw(15) << right << "3. ���ϴ� ���ִ´�.\n";
		
		switch (GetKey())
		{
		case '1':
			if (pushStatus(1) > 8)
			{
				cout << "���������� ���ҽ��ϴ�.\n";
			}
			else
			{
				cout << "���� ���� ���� ���ڶ� �������� �Ծ����ϴ�\n";
				Damage(3);
			}
			break;
		case '2':
			if (pushStatus(2) > 8)
			{
				cout << "���������� ���߽��ϴ�.\n";
			}
			else
			{
				cout << "�ൿ�� ���� ������ ���� ���߽��ϴ�.\n";
				Damage(3);
			}
			break;
		case '3':
			Damage(3);
			cout << "3 �������� �Ծ����ϴ�\n";
			break;
		}

		cout << "\n���� ������ �̵��մϴ�";
		Sleep(1000);
		system("cls");
	}

	void spear()
	{
		cout << "���� ������ ������ �ֽ��ϴ�. ��¾�� ȭ���� ���ƿ� �� �����ϴ�.\n";
		cout << "1 ~ 3�� ����Ű�� ���� �ൿ�� �����ϼ���\n\n";
		cout << setw(15) << right << "1. ����� �ɾ��.\n";
		cout << setw(15) << right << "2. ������ ���� �ɾ��.\n";
		cout << setw(15) << right << "3. ���� �ִ� ��Ʈ���г��� �����Ѵ�.\n";

		switch (GetKey())
		{
		case '1':
			Damage(3);
			cout << "3 �������� �Ծ����ϴ�\n";
			break;
			break;
		case '2':
			if (pushStatus(2) > 8)
			{
				cout << "���������� ���߽��ϴ�.\n";
			}
			else
			{
				cout << "��ø�� ���ڶ� ����� âó�� �Խ��ϴ�.\n";
				Damage(3);
			}
			break;
		case '3':
			if (pushStatus(3) > 8)
			{
				cout << "������ ���������� �����߽��ϴ�..\n";
			}
			else
			{
				cout << "��ø���� ���ڶ� ����� âó�� �Խ��ϴ�.\n";
				Damage(3);
			}
			break;
		}

		cout << "\n���� ������ �̵��մϴ�";
		Sleep(1000);
		system("cls");
	}

	void lever()
	{
		cout << "���� ���� �ֽ��ϴ�. ��� �� �ִ� ������ �ֽ��ϴ�.\n";
		cout << "1 ~ 3�� ����Ű�� ���� �ൿ�� �����ϼ���\n\n";
		cout << setw(15) << right << "1. ������ ��ܺ���.\n";
		cout << setw(15) << right << "2. õ�忡 ����� ���� ��� �����Ѵ�.\n";
		cout << setw(15) << right << "3. ���ù��� �ɾ��.\n";

		switch (GetKey())
		{
		case '1':
			if (pushStatus(1) > 8)
			{
				cout << "������ ������ �����ϴ�. ���� �����Ǿ� ������ �ǳԽ��ϴ�.\n";
			}
			else
			{
				cout << "���� ���ڶ��ϴ�. �ᱹ ���ù��� �ǳҴϴ�.\n";
				Damage(3);
			}
			break;
		case '2':
			if (pushStatus(2) > 8)
			{
				cout << "���������� �ǳԽ��ϴ�.\n";
			}
			else
			{
				cout << "����� ���̽��ϴ�. ���� ��� ���� ���� �߶��մϴ�.\n";
				Damage(3);
			}
			break;
		case '3':
				cout << "���� ü���ϰ� ���ù��� �ɾ�ϴ�.\n";
				Damage(3);
			break;
		}

		cout << "\n���� ������ �̵��մϴ�";
		Sleep(1000);
		system("cls");
	}

	void Quiz()
	{
		cout << "��� ���� ������ �����Ϳ� ���� ������ ���� �ֽ��ϴ�.\n";
		cout << "1 ~ 3�� ����Ű�� ���� �ൿ�� �����ϼ���\n\n";
		cout << setw(15) << right << "1. �ν�������.\n";
		cout << setw(15) << right << "2. ������ ���� ��������.\n";
		cout << setw(15) << right << "3. Computational Thinking.\n";

		switch (GetKey())
		{
		case '1':
			cout << "��� �ε�� �½��ϴ�.\n";
			Damage(3);
			break;
		case '2':
			cout << "�߰��Ǿ����ϴ�. ��� �ε�� �½��ϴ�.\n";
			Damage(3);
			break;
		case '3':
			if (pushStatus(3) > 8)
			{
				cout << "������ ���������� Ǯ�����ϴ�..\n";
			}
			else
			{
				cout << "����� ������ �����������ϴ�. ������ Ǯ�� ���� ��� �ε�� �½��ϴ�.\n";
				Damage(3);
			}
			break;
		}

		cout << "\n���� ������ �̵��մϴ�";
		Sleep(1000);
		system("cls");
	}

	void battle()
	{
		_delta = 0;
		_hp = 10;
		int apcount = 0;
		bool attackcount;
		while (1)
		{
			if (pushHP() <= 0 || _hp <= 0)
			{
				break;
			}

			apcount++;
			if (apcount % 100 == 0)
			{
				Damage(_atk);
			}

			cout << "\n\n";
			cout << "\n";
			cout << setw(20) << left << " ���� ";
			cout << setw(20) << right << pushName() << "\n";

			cout << setw(20) << left << _hp;
			cout << setw(20) << right << pushHP() << "\n";

			cout << setw(40) << right << apSet(_delta) << "\n";

			


			if (apSet(apcount) % 300 > 290 && attackcount == true)
			{
				cout << setw(40) << right << "'1' Ű�� ���� ����";
				int inputKey1 = _getch();

				if (inputKey1 == '1')
				{
					_hp -= attack();
					attackcount = false;
				}
			}



			if ((apSet(apcount) % 300) / 30 == 1)
			{
				attackcount = true;
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 2)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 3)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 4)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 5)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 6)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 7)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 8)
			{
				cout << setw(40) << right << "�����������";
			}
			else if ((apSet(apcount) % 300) / 30 == 9)
			{
				cout << setw(40) << right << "�����������";
			}

			system("cls");


			
		}

	}




private:
	int _hp = 10;
	int _atk = 2;
	int _delta = 0;



};


