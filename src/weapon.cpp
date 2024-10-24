#include "weapon.hpp"
#include <iostream>
#include <format>
#include <string>
#include "nlohmann/json.hpp"
#include <fstream>

Weapon::Weapon(const std::string& name, double ATK, double Crit, double combo, double suck)
{
	this->name = name;
	this->ATK = ATK;
	this->Crit = Crit;
	this->combo = combo;
}

void Weapon::Save(const std::string& characterName,nlohmann::json &archive)
{
	archive[characterName]["weapon"][this->name]["ATK"] = this->ATK;
	archive[characterName]["weapon"][this->name]["Crit"] = this->Crit;
	archive[characterName]["weapon"][this->name]["combo"] = this->combo;
	archive[characterName]["weapon"][this->name]["suck"] = this->suck;
}

void Weapon::Load(const std::string& characterName, nlohmann::json& archive)
{
	this->ATK = archive[characterName]["weapon"]["weapon"]["ATK"].get<double>();
	this->Crit = archive[characterName]["weapon"]["weapon"]["Crit"].get<double>();
	this->combo = archive[characterName]["weapon"]["weapon"]["combo"].get<double>();
	this->suck = archive[characterName]["weapon"]["weapon"]["suck"].get<double>();
}

void Weapon::getInfo()
{
	std::cout << std::format("��������:{0}, ����:{1}, ����:{2}, ��Ѫ:{3}\n", ATK, Crit, combo, suck);
}
