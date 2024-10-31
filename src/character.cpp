#include "character.hpp"
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>
#include <format>
#include "random_get.hpp"
/*以下各函数属于Character类*/
Character::Character(const std::string & name,double HPMAX,double ATK,double DEF,int EXP,int LV,int skillCD_MAX,double speed)//构造函数
{
	this->HPMAX = HPMAX;
	this->HP = HPMAX;
	this->ATK = ATK;
	this->DEF = DEF;
	this->EXP = EXP;
	this->LV = LV;
	this->skillCD = skillCD_MAX;
	this->skillCD_MAX = skillCD_MAX;
	this-> name = name;
	this->speed = speed;
}
/**
 * @brief 构造函数
 * @param HPMAX 生命值上限
 *		  ATK 攻击力
 *        DEF 防御力
 *        EXP 经验值
 *        LV 等级
 *        skillCD_MAX 最大冷却时间
 *        name 名字
 *        speed 速度，用于判定先后手
 */

void Character::LevelUp()
{
	if(EXP>=10*LV){
		EXP-=10*LV;
		LV+=1;
		HPMAX+=10;
		if(HP>0.5*HPMAX){
			HP=HPMAX;
		}
		else{
			HP+=HPMAX*0.5;
		}
		ATK+=2;
		DEF+=1;
	}
}
/**
 * @brief 判定角色是否满足升级条件，满足则为角色升级并提升属性
 */

void Character::Load()
{
	using json = nlohmann::json;
	std::ifstream fin("archive.json");
	if (fin.is_open())
	{
		json archive;
		fin >> archive;
		if (archive.contains(name))
		{
			try
			{
				HPMAX = archive[name]["HP_MAX"].get<double>();
				HP = archive[name]["HP"].get<double>();
				ATK = archive[name]["ATK"].get<double>();
				DEF = archive[name]["DEF"].get<double>();
				EXP = archive[name]["EXP"].get<int>();
				LV = archive[name]["LV"].get<int>();
				skillCD_MAX = archive[name]["skillCD_MAX"].get<int>();
				this->speed = archive[name]["speed"].get<double>();
				weapon.Load(name, archive);
				std::cout << "角色:" << name << "读取成功" << std::endl;
			}
			catch (std::exception &e)
			{
				#ifdef _DEBUG
				std::cerr << e.what()<<std::endl;
				#endif 		
				Save();
	  		}
		}
		else
		{
			Save();
			std::cout << "已为您新建角色：" << name << std::endl;
		}
	}
	else
	{
		Save();
		std::cout << "已为您新建角色：" << name << std::endl;
	}
}
/**
 * @brief 读取存档或新建存档
 */

void Character::Save()
{
	using json = nlohmann::json;
	std::ifstream fin("archive.json");
	std::ofstream fout;
	json archive;
	if (fin.is_open())
	{
		fin >> archive;
	}
	else
	{
		fout.open("archive.json");
		fout << "{}";
		fout.close();
		fout.clear();
	}
	fin.close();
	fout.open("archive.json");
	if (fout.is_open())
	{
		archive[name]["HP_MAX"] = HPMAX;
		archive[name]["HP"] = HP;
		archive[name]["ATK"] = ATK;
		archive[name]["DEF"] = DEF;
		archive[name]["EXP"] = EXP;
		archive[name]["LV"] = LV;
		archive[name]["skillCD_MAX"] = skillCD_MAX;
		archive[name]["speed"] = this->speed;
		weapon.Save(name,archive);
		fout << archive << std::endl;
		fout.close();
	}
}
/**
 * @brief 将各项属性保存到archive.json文件
 */

void Character::getInfo()
{
	std::cout << std::format("金币数:{0}\n血量:{1}\n攻击:{2}\n防御:{3}\n速度:{4}\n等级:{5}\n经验:{6}/{7}\n", coin, HPMAX, ATK, DEF, speed, LV, EXP, LV * 10);
	this->weapon.getInfo();
}
/**
 * @brief 获取角色属性信息（包括武器） 
 */

double Character::damage(const double takeDamage)
{
	double damageNum = (std::max)(takeDamage - DEF, takeDamage * 0.05);
	HP -= damageNum;
	return damageNum;
}
/**
 * @brief 收到伤害并返回伤害数值，该伤害不低于折算前伤害的5%
 * @param takeDamage 折算前受到的伤害，通常是攻击力
 */

/*以下函数并不属于Character类*/
double attack(Character& attacker, Character& target)
{
	return target.damage(attacker.getATK());
}
/**
 * @brief 一方对另一方造成伤害，并返回最终的伤害值
 * @param &attacker 攻击发起方
 *        &target 攻击对象
 */

double skill(Character& attacker, Character& target)
{
	attacker.resetSkillCD();
	return target.damage(attacker.getATK() * 1.2);
}
/**
 * @brief 一方对另一方使用技能造成伤害后重置技能CD，并返回最终的伤害值
 * @param &attacker 攻击发起方
 *        &target 攻击对象
 */

double selectAction(Character& attacker, Character& target)
{
	std::cout << "轮到你行动了" << std::endl;
	std::cout << "按1使用普通攻击，按2使用技能" << std::endl;
	std::cout << "技能CD还有" << attacker.getSkillCD() << std::endl;
	char option='0';
	double damageNum = 0;
	while (damageNum!=0) {
		option = std::cin.get();
		switch (option) {
		case '1':
			damageNum=attack(attacker, target); 
			break;
		case '2':
			if(attacker.getSkillCD()==0){
				damageNum = skill(attacker, target);
				break;
			}
			else {
				std::cout << "技能还在冷却！" << std::endl;
			}
		default:
			std::cout << "输入无效！" << std::endl;
		}
	}
	return damageNum;
}
/**
 * @brief 选择普通攻击或使用技能，并返回最终的伤害值
 * @param &attacker 攻击发起方
 *        &target 攻击对象
 */