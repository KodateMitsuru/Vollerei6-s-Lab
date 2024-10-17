//���character�������character�ĸ������ԣ��Լ�����ִ�еĸ���� 
#define _character_h
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class Character{
	public:
		Character(double a,double b,double c,int d,int e,int f,char g[16]);//���캯��
		~Character() = default;
		double HPMAX;//��ʾ����ֵ���� 
		double HP;//��ʾ���е�����ֵ 
		double ATK;
		double DEF;
		int EXP;
		int LV;
		int skillCD;//��ǰ��ʣ����ȴʱ�� 
		int skillCD_MAX;//���CD 
		char name[16]="";
		void attack(Character *ID) const;//�������Ȳ����ú�����ʽ��װ�����ں���ά�� 
		void skill(Character *ID);
		void LevelUp();///���� 
};//��ɫ�࣬������ɫ�ĸ�������/��ɫ�ɽ��е���Ϊ 

inline Character::Character(double a,double b,double c,int d,int e,int f,char g[16]){
	HPMAX=a;
	HP=a;
	ATK=b;
	DEF=c;
	EXP=d;
	LV=e;
	skillCD=0;
	skillCD_MAX=f;
	strcpy(name,g);
}

inline void Character::attack(Character *ID)
{
	double DMG=0;
	Character *p=ID;
	DMG=ATK-(*p).DEF;
	(*p).HP-=DMG;
	cout<<"�����"<<DMG<<"���˺�"<<endl;
}

inline void Character::skill(Character *ID)
{
	skillCD=skillCD_MAX;
	double DMG=0;
	Character *p=ID;
	DMG=(ATK-(*p).DEF)*1.2;
	(*p).HP-=DMG;
	cout<<"�����"<<DMG<<"���˺�"<<endl;
}

inline void Character::LevelUp()
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
#end
