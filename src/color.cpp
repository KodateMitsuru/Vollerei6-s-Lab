#include <iostream>
#include <windows.h>
#include <format>
#include <string>
#include "color.hpp"
void rgb_init() {																// ��ʼ��
	using namespace std;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//������
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//��ȡ����̨����ģʽ
	GetConsoleMode(hOut, &dwOutMode);					//��ȡ����̨���ģʽ
	dwInMode |= 0x0200;									//����
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//���ÿ���̨����ģʽ
	SetConsoleMode(hOut, dwOutMode);					//���ÿ���̨���ģʽ
}

void rgb_set(int wr,int wg,int wb,int br,int bg,int bb) {						//����RGB
	std::cout <<std::format("\033[38;2;{0};{1};{2}m\033[48;2;{3};{4};{5}m",wr,wg,wb,br,bg,bb);	//\033[38��ʾǰ����\033[48��ʾ����������%d��ʾ��ϵ���
}

void red(const std::string& str)
{
	rgb_set(255, 0, 0, 0, 0, 0);
	std::cout << str;
	rgb_set(255, 255, 255, 0, 0, 0);
}

void green(const std::string& str)
{
	rgb_set(0, 255, 0, 0, 0, 0);
	std::cout << str;
	rgb_set(255, 255, 255, 0, 0, 0);
}
