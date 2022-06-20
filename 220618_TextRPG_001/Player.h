#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <random>
using namespace std;

static int _inven[25] = { 0 };

class Player
{
public:
	void Init()
	{
		cout << "�÷��̾� �̸��� �Է��ϼ���";
		cin >> _name;
		cout << "�÷��̾� �̸� �Է� �Ϸ�";
		Sleep(500);
		system("cls");

		while (1)
		{
			cout << "\n�÷��̾� �̸� : " << _name << "\n\n";
			cout << "�ɸ����� �ɷ�ġ�� �����մϴ�" << "\n";
			cout << "'2' Ű�� ���� �ɷ�ġ�� �����ϼ���" << "\n";
			
			if (GetKey() == '2')
			{

				while (_hp + _str + _dex + _int + _spd < 40)
				{
					int rand = dice(1, 5);

					if (rand == 1 && _hp <= 11)
					{
						_hp += 1;
					}
					if (rand == 2 && _str <= 11)
					{
						_str += 1;
					}
					if (rand == 3 && _dex <= 11)
					{
						_dex += 1;
					}
					if (rand == 4 && _int <= 11)
					{
						_int += 1;
					}
					if (rand == 5 && _spd <= 11)
					{
						_spd += 1;
					}
				}
			}

			cout << "ü��\t: " << _hp << "\n";
			cout << "��\t: " << _str << "\n";
			cout << "��ø\t: " << _dex << "\n";
			cout << "����\t: " << _int << "\n";
			cout << "�ӵ�\t: " << _spd << "\n";
			cout << "\n\n" << "�� �ɷ�ġ�� �����Ͻðڽ��ϱ�?\n";
			cout << "1 = ����\n";
			cout << "2 = �缳��\n";

			if (GetKey() == '2')
			{
				system("cls");
			}
			else
			{
				break;
			}
		}
		_maxhp = _hp;

		GetItem(3001);
		GetItem(4001);
		GetItem(5001);
		GetItem(2001);
		GetItem(2002);
		GetItem(1002);
		GetItem(1004);
		GetItem(1006);
		system("cls");
	}

	int dice(int min, int max)
	{
		random_device rd;		
		mt19937 gen(rd());		
		uniform_int_distribution<int> dis(min, max);		
		return dis(gen);
	}

	int UseItem(int num)
	{
		if (num > 2000)
		{
			int temp;
			temp = _inven[num - 1];
			_inven[num - 1] = 0;
			return temp;
		}
	}
	
	void GetItem(int num)
	{
		for (int i = 0; i < 25; i++)
		{
			if (_inven[i] == 0)
			{
				_inven[i] = num;
				break;
			}
		}
	}
	
	void equipment(int num)
	{
		int temp;
		for (int i = 0; i < 25; i++)
		{
			if (_inven[num])
			{
				if (_inven[num] / 1000 >= 3)
				{
					swap(_inven[num], _weapon);
					break;
				}
				if (_inven[num] / 1000 == 2)
				{
					swap(_inven[num], _armor);
					break;
				}
				if (_inven[num] / 1000 == 1)
				{
					_hp += _inven[num] % 10;
					_inven[num] = 0;
					break;
				}
			}
		}

	}



	int apSet(int apcount)
	{
		return apcount * _spd;


	}

	int push_inven(int num)
	{
		return _inven[num];
	}

	void Damage(int d)
	{
		_hp -= d;
	}

	int GetKey()
	{
		int key;
		key = _getch();

		return key;
	}

	int pushStatus(int stat)
	{
		switch (stat)
		{
		case 1:
			return _str;
			break;
		case 2:
			return _dex;
			break;
		case 3:
			return _int;
			break;
		}
	}

	string pushName()
	{
		return _name;
	}

	int pushHP()
	{
		return _hp;
	}

	int attack()
	{
		switch (_weapon / 1000)
		{
		case 3:
			return _str / 2;
			break;
		case 4:
			return _dex / 2;
			break;
		case 5:
			return _int / 2;
			break;

		}
	}

	void toDie()
	{
		string dieText = "����� �׾����ϴ�. ��ü ü���� 50%�� ��Ȱ�մϴ�.";
		cout << "\n\n";
		for (int i = 0; dieText[i] != NULL; i++)
		{
			cout << dieText[i];
			Sleep(150);
		}

		_hp = _maxhp;
		system("cls");
	}

private:
	string _name;
	int _hp = 4;
	int _maxhp = 4;
	int _str = 4;
	int _dex = 4;
	int _int = 4;
	int _spd = 4;
	int _ap = 0;
	int _apcount = 0;
	int _weapon = 3000;
	int _armor = 2000;
	float get_ap = 0;
	int _dice = 0;

};