#pragma once
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Map.h"
#include "Time.h"
using namespace std;

class Scene : public Map
{
public:
	void SceneChange()
	{
		while (1)
		{
			if (pushHP() <= 0)
			{
				toDie();
				_Scene = 0;
				system("cls");
			}
			switch (_Scene)
			{
			case 99:
				Init();
				SelectMenu();  
				break;
			case 0:
				SelectMenu();
				break;
			case 1:
				Dungeon();
				break;
			case 2:
				Inven();
				break;
			case 3:
				Exit();
				break;
			}
		}
	}

	void SelectMenu()
	{
		cout << "\n\n";
		cout << setw(15) << right << "1. ���� ���� \n";
		cout << setw(15) << right << "2. �κ��丮  \n";
		cout << setw(15) << right << "3. ����      \n";
		SceneNum();
		system("cls");
	}

	void SceneNum()
	{
		int ainput = _getch();
		_Scene = ainput - 48;
	}

	void Dungeon()
	{
		RandMap();
	}

	void Inven()
	{
		for (int i = 0; i < 25; i++)
		{
			if (push_inven(i) != 0)
			{
				if (push_inven(i) == 3001) {
					cout << i + 1 << ". ";
					cout << "������ ��" << "\n";
				}
				if (push_inven(i) == 4001) {
					cout << i + 1 << ". ";
					cout << "Ŭ���� �ܵ�" << "\n";
				}
				if (push_inven(i) == 5001) {
					cout << i + 1 << ". ";
					cout << "��ü���� ������" << "\n";
				}
				if (push_inven(i) == 2001) {
					cout << i + 1 << ". ";
					cout << "�����̸� ����" << "\n";
				}
				if (push_inven(i) == 2002) {
					cout << i + 1 << ". ";
					cout << "�������� ����" << "\n";
				}
				if (push_inven(i) == 1002) {
					cout << i + 1 << ". ";
					cout << "����(��)" << "\n";
				}
				if (push_inven(i) == 1004) {
					cout << i + 1 << ". ";
					cout << "����(��)" << "\n";
				}
				if (push_inven(i) == 1006) {
					cout << i + 1 << ". ";
					cout << "����(��)" << "\n";
				}
			}
		}

		cout << "\n";
		cout << "��ȣŰ = ������ / ��� ���\n 0 = ���θ޴�\n";
		int input;
		cin >> input;
		if (0 != input)
		{
			equipment(input - 1);
		}
		else if (0 == input)
		{
			_Scene = 0;
		}
		system("cls");


	}

	void Exit()
	{
		exit(1);
	}

	
private:
	int _Scene = 99;
};