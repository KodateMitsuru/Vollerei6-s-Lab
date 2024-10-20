#include <iostream>
#include "play.hpp"
#include "character.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Windows.h"
#include "color.hpp"
#include "random_get.hpp"

void play(Character& player)
{
	using std::cout,std::endl,std::to_string;
	Character enemy("Enemy", 120*getDis(), 50*getDis(), 30*getDis());
	while (true)
	{
		cout << "���" << attack(player, enemy) << "���˺�" << endl;
		cout << "�ܵ�" << attack(enemy, player) << "���˺�" << endl;
		green("���Ѫ��:" + to_string(player.getHp()));
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