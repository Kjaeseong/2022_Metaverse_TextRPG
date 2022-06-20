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
		cout << "큰 돌덩이가 굴러오고 있습니다.\n";
		cout << "1 ~ 3의 숫자키를 눌러 행동을 선택하세요\n\n";
		cout << setw(15) << right << "1. 힘으로 막는다.\n";
		cout << setw(15) << right << "2. 구석으로 숨는다.\n";
		cout << setw(15) << right << "3. 멍하니 서있는다.\n";
		
		switch (GetKey())
		{
		case '1':
			if (pushStatus(1) > 8)
			{
				cout << "성공적으로 막았습니다.\n";
			}
			else
			{
				cout << "돌을 막을 힘이 모자라 데미지를 입었습니다\n";
				Damage(3);
			}
			break;
		case '2':
			if (pushStatus(2) > 8)
			{
				cout << "성공적으로 피했습니다.\n";
			}
			else
			{
				cout << "행동이 굼떠 구석에 들어가지 못했습니다.\n";
				Damage(3);
			}
			break;
		case '3':
			Damage(3);
			cout << "3 데미지를 입었습니다\n";
			break;
		}

		cout << "\n다음 맵으로 이동합니다";
		Sleep(1000);
		system("cls");
	}

	void spear()
	{
		cout << "벽에 무수한 구멍이 있습니다. 어쩐지 화살이 날아올 것 같습니다.\n";
		cout << "1 ~ 3의 숫자키를 눌러 행동을 선택하세요\n\n";
		cout << setw(15) << right << "1. 당당히 걸어간다.\n";
		cout << setw(15) << right << "2. 은신을 쓰며 걸어간다.\n";
		cout << setw(15) << right << "3. 벽에 있는 컨트롤패널을 조사한다.\n";

		switch (GetKey())
		{
		case '1':
			Damage(3);
			cout << "3 데미지를 입었습니다\n";
			break;
			break;
		case '2':
			if (pushStatus(2) > 8)
			{
				cout << "성공적으로 피했습니다.\n";
			}
			else
			{
				cout << "민첩이 모자란 당신은 창처를 입습니다.\n";
				Damage(3);
			}
			break;
		case '3':
			if (pushStatus(3) > 8)
			{
				cout << "함정을 성공적으로 해제했습니다..\n";
			}
			else
			{
				cout << "민첩함이 모자란 당신은 창처를 입습니다.\n";
				Damage(3);
			}
			break;
		}

		cout << "\n다음 맵으로 이동합니다";
		Sleep(1000);
		system("cls");
	}

	void lever()
	{
		cout << "길이 끊겨 있습니다. 당길 수 있는 레버가 있습니다.\n";
		cout << "1 ~ 3의 숫자키를 눌러 행동을 선택하세요\n\n";
		cout << setw(15) << right << "1. 레버를 당겨본다.\n";
		cout << setw(15) << right << "2. 천장에 연결된 줄을 잡고 도약한다.\n";
		cout << setw(15) << right << "3. 가시밭길로 걸어간다.\n";

		switch (GetKey())
		{
		case '1':
			if (pushStatus(1) > 8)
			{
				cout << "힘으로 레버를 당겼습니다. 길이 생성되어 무사히 건넜습니다.\n";
			}
			else
			{
				cout << "힘이 모자랍니다. 결국 가시밭길로 건넙니다.\n";
				Damage(3);
			}
			break;
		case '2':
			if (pushStatus(2) > 8)
			{
				cout << "성공적으로 건넜습니다.\n";
			}
			else
			{
				cout << "당신은 무겁습니다. 줄이 끊어서 가시 위로 추락합니다.\n";
				Damage(3);
			}
			break;
		case '3':
				cout << "모든걸 체념하고 가시밭길로 걸어갑니다.\n";
				Damage(3);
			break;
		}

		cout << "\n다음 맵으로 이동합니다";
		Sleep(1000);
		system("cls");
	}

	void Quiz()
	{
		cout << "퀴즈를 내는 석상이 포인터에 관한 문제를 내고 있습니다.\n";
		cout << "1 ~ 3의 숫자키를 눌러 행동을 선택하세요\n\n";
		cout << setw(15) << right << "1. 부숴버린다.\n";
		cout << setw(15) << right << "2. 은신을 쓰고 지나간다.\n";
		cout << setw(15) << right << "3. Computational Thinking.\n";

		switch (GetKey())
		{
		case '1':
			cout << "흠씬 두들겨 맞습니다.\n";
			Damage(3);
			break;
		case '2':
			cout << "발각되었습니다. 흠씬 두들겨 맞습니다.\n";
			Damage(3);
			break;
		case '3':
			if (pushStatus(3) > 8)
			{
				cout << "문제를 성공적으로 풀었습니다..\n";
			}
			else
			{
				cout << "당신은 지능이 유감스럽습니다. 문제를 풀지 못해 흠씬 두들겨 맞습니다.\n";
				Damage(3);
			}
			break;
		}

		cout << "\n다음 맵으로 이동합니다";
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
			cout << setw(20) << left << " 몬스터 ";
			cout << setw(20) << right << pushName() << "\n";

			cout << setw(20) << left << _hp;
			cout << setw(20) << right << pushHP() << "\n";

			cout << setw(40) << right << apSet(_delta) << "\n";

			


			if (apSet(apcount) % 300 > 290 && attackcount == true)
			{
				cout << setw(40) << right << "'1' 키를 눌러 공격";
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
				cout << setw(40) << right << "□□□□□□□□□■";
			}
			else if ((apSet(apcount) % 300) / 30 == 2)
			{
				cout << setw(40) << right << "□□□□□□□□■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 3)
			{
				cout << setw(40) << right << "□□□□□□□■■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 4)
			{
				cout << setw(40) << right << "□□□□□□■■■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 5)
			{
				cout << setw(40) << right << "□□□□□■■■■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 6)
			{
				cout << setw(40) << right << "□□□□■■■■■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 7)
			{
				cout << setw(40) << right << "□□□■■■■■■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 8)
			{
				cout << setw(40) << right << "□□■■■■■■■■";
			}
			else if ((apSet(apcount) % 300) / 30 == 9)
			{
				cout << setw(40) << right << "□■■■■■■■■■";
			}

			system("cls");


			
		}

	}




private:
	int _hp = 10;
	int _atk = 2;
	int _delta = 0;



};


