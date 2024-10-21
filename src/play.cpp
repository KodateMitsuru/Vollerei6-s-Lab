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
	Character enemy("Enemy", 75*getDis(), 50*getDis(), 30*getDis(),0,0,3,200*getDis());
	battle(player, enemy);
}

void battle(Character& player, Character& enemy)
{
	double status1 = 0,status2=0;
	double editSpeed1 = 1000 / player.getSpeed();
	double editSpeed2 = 1000 / enemy.getSpeed();
	while (true)
	{
		using std::cout, std::endl;
		status1 += (std::min)(editSpeed1, editSpeed2);
		status2 += (std::min)(editSpeed1, editSpeed2);
		if (status1 >= editSpeed1)
		{
			cout << "���" << green() << attack(player, enemy) << white() << "���˺�" << endl;
			cout << red() << "����Ѫ��:" << enemy.getHp() << white() << endl ;
			status1 -= editSpeed1;
		}
		if (status2 >= editSpeed2)
		{
			cout << "�ܵ�" <<red()<< attack(enemy, player) <<white()<< "���˺�" << endl;
			cout << green() << "���Ѫ��:" << player.getHp() << white() << endl ;
			status2-=editSpeed2;
		}
		endl(cout);
		if (player.getHp() <= 0 && enemy.getHp() <= 0)
		{
			cout << "ƽ��" << endl;
		}
		if (player.getHp() <= 0)
		{
			cout << red()<<"ʧ��" <<white()<< endl;
			break;
		}
		if (enemy.getHp() <= 0)
		{
			cout << green()<<"ʤ��" <<white()<< endl;
			break;
		}
		Sleep(1000);

	}
}