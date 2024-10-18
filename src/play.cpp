#include <iostream>
#include "play.hpp"
#include "character.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Windows.h"

double attack(const Character& attacker, Character& target)
{
	double damage = 0;
	damage = (std::max)(attacker.ATK - target.DEF, attacker.ATK * 0.05);
	target.HP -= damage;
	return damage;
}

void play(Character& player)
{
	using std::srand, std::time, std::rand,std::cout,std::endl;
	srand(time(NULL));
	Character enemy("Enemy", rand() % 120, rand() % 50, rand() % 30);
	while (true)
	{
		cout << "���" << attack(player, enemy) << "���˺�" << endl;
		cout << "�ܵ�" << attack(enemy, player) << "���˺�" << endl;
		cout << "����Ѫ��:" << enemy.getHp() << endl;
		cout << "���Ѫ��:" << player.getHp() << endl;
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