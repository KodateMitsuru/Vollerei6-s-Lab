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
		cout << "���" <<green()<< attack(player, enemy) <<white()<< "���˺�" << endl;
		cout << "�ܵ�" <<red()<< attack(enemy, player) <<white()<< "���˺�" << endl;
		cout << green()<<"���Ѫ��:" << player.getHp()<<white()<<endl;
		cout <<red()<<"����Ѫ��:"<<enemy.getHp()<<white()<<endl;
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