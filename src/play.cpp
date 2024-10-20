#include <iostream>
#include "play.hpp"
#include "character.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Windows.h"
#include "color.hpp"

void play(Character& player)
{
	using std::srand, std::time, std::rand,std::cout,std::endl,std::to_string;
	srand(time(NULL));
	Character enemy("Enemy", rand() % 120, rand() % 50, rand() % 30);
	while (true)
	{
		cout << "���" << attack(player, enemy) << "���˺�" << endl;
		cout << "�ܵ�" << attack(enemy, player) << "���˺�" << endl;
		green("���Ѫ��:" + to_string(enemy.getHp()));
		endl(cout);
		red("����Ѫ��:" + to_string(enemy.getHp()));
		endl(cout);
		if (player.getHp() <= 0)
		{
			cout << "ʧ��" << endl;
			break;
		}
		if (enemy.getHp() <= 0)
		{
			cout << "ʤ��" << endl;
			break;
		}
		Sleep(1000);
	}
}