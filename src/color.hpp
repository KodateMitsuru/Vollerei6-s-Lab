#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <format>

void rgb_init();

inline std::string rgb_set(int wr, int wg, int wb, int br, int bg, int bb)
{						//����RGB
	return (std::string)std::format("\033[38;2;{0};{1};{2}m\033[48;2;{3};{4};{5}m", wr, wg, wb, br, bg, bb);	//\033[38��ʾǰ����\033[48��ʾ����������%d��ʾ��ϵ���
}
//����RGB
inline std::string red()
{
	return rgb_set(255, 0, 0, 0, 0, 0);
}

inline std::string green()
{
	return rgb_set(0, 255, 0, 0, 0, 0);
}

inline std::string white()
{
	return rgb_set(255, 255, 255, 0, 0, 0);
}

inline std::string yellow()
{
	return rgb_set(255, 255, 0, 0, 0, 0);
}

#endif // !COLOR_HPP
