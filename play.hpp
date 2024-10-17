#ifndef _play_h
#define _play_h
#include <iostream>
#include "character.hpp"
#include "archive.hpp"
using namespace std;
void play(Character* ID)
{
    char enemy_name[16] = "Enemy";
    Character Enemy(50, 15, 7, 0, 1, 0,enemy_name);
    Character *p=ID;
    int attack_option=0;
    bool attack_finish=false;
    while(1){
        attack_finish=false;
        cout<<"��ѡ����Ĺ�����ʽ"<<endl;
        cout<<"��1������ͨ��������2�������⹥��"<<endl;
        cout<<"���⹥��CD����"<<(*p).skillCD<<"��"<<endl;
        do{
            cin>>attack_option;
            switch(attack_option){
            case 1:
                (*p).attack(&Enemy);
                if((*p).skillCD>0) (*p).skillCD--;
                attack_finish=true;
                break;
            case 2:
                if((*p).skillCD==0){
                    (*p).skill(&Enemy);
                    attack_finish=true;
                }
                else cout<<"���ܻ�����ȴ��"<<endl;
                break;
            default:
                cout<<"��Ч���룡"<<endl;
            }
        }while(!attack_finish);
        cout<<"���˻���"<<Enemy.HP<<"��Ѫ��"<<endl;
        if(Enemy.HP<=0){
        	cout<<"�������ˣ�"<<endl;
            (*p).EXP+=1;
            (*p).LevelUp();
            Enemy.~Character();
            break;
        }
        Enemy.attack(ID);
        cout<<"�㻹��"<<(*p).HP<<"��Ѫ��"<<endl;
        if((*p).HP<=0){
            cout<<"������!"<<endl;
            (*p).HP=(*p).HPMAX;
            break;
        }
    }
    save(*p);
}
#endif
