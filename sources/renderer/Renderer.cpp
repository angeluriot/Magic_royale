#include "renderer/Renderer.hpp"

std::string get_color_code(Renderer::Color color)
{
	switch (color)
	{
	case Renderer::Color::Red:
		return "\033[31m";
	case Renderer::Color::Green:
		return "\033[32m";
	case Renderer::Color::Yellow:
		return "\033[33m";
	case Renderer::Color::Blue:
		return "\033[34m";
	case Renderer::Color::Magenta:
		return "\033[35m";
	case Renderer::Color::Cyan:
		return "\033[36m";
	case Renderer::Color::White:
		return "\033[37m";
	case Renderer::Color::Gray:
		return "\033[90m";
	default:
		return "";
	}
}

Renderer::Color Renderer::get_color(Card::Color color)
{
	switch (color)
	{
	case Card::Color::Red:
		return Renderer::Color::Red;
	case Card::Color::Green:
		return Renderer::Color::Green;
	case Card::Color::Blue:
		return Renderer::Color::Blue;
	case Card::Color::White:
		return Renderer::Color::White;
	case Card::Color::Black:
		return Renderer::Color::Gray;
	case Card::Color::Colorless:
		return Renderer::Color::White;
	default:
		return Renderer::Color::White;
	}
}

void Renderer::print(std::string text, Color color, bool bold)
{
	std::cout << get_color_code(color) << (bold ? "\033[1m" : "") << text << "\033[0m" << std::flush;
}

void Renderer::new_lines(size_t number)
{
	for (size_t i = 0; i < number; i++)
		std::cout << std::endl;
}

void Renderer::confirm()
{
	new_lines();
	std::cin.get();
}

void Renderer::clear()
{
	#if defined _WIN32
		system("cls");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
	#elif defined (__APPLE__)
		system("clear");
	#endif
}
