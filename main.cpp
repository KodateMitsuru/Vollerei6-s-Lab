#include <iostream>
#include "character.hpp"
#include "play.hpp"
#include "archive.hpp"
using namespace std;
void archive();
void play();
void data_search();
void exit();

//�����򲿷� 
int main()
{
    char player_name[16]="Player";
    Character Player(100,20,10,0,1,3,player_name);//����һ����Ҷ��� 
    archive(&Player);//����
    int status=0;
    while(true)
    {
        cout<<"��ӭ��������-���"<<endl;
		cout<<"��ѡ����Ҫ�����ҳ��"<<endl;
		cout<<"����1��������Ϸ"<<endl;
		cout<<"����2���鿴˵��"<<endl;
		cout<<"����3���浵�˳�"<<endl;
		cin>>status;
        switch(status){
        case 1:play(&Player);break;
        case 2:data_search(Player);break;
        case 3:exit(Player);break;
        default:cout<<"������Ч��"<<endl;
        }
        if(status==3) break;
    }
    Player.~Character();
    return 0;
}
