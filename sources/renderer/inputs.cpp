#include "renderer/inputs.hpp"
#include <iostream>

#if defined _WIN32
#include <conio.h>

Key wait_for_key()
{
	int c;

	while (true)
	{
		c = _getch();

		if (c == 0 || c == 224)
		{
			c = _getch();

			switch (c)
			{
			case 72:
				return Key::Up;
			case 75:
				return Key::Left;
			case 77:
				return Key::Right;
			case 80:
				return Key::Down;
			default:
				continue;
			}
		}

		else if (c == 13)
			break;
	}

	return Key::Enter;
}

#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

char get_input()
{
	char buf = 0;
	struct termios old = { 0 };
	fflush(stdout);

	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");

	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;

	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");

	if (read(0, &buf, 1) < 0)
		perror("read()");

	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;

	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror ("tcsetattr ~ICANON");

	return buf;
}

Key wait_for_key()
{
	int c;

	while (true)
	{
		c = get_input();

		switch (c)
		{
		case 65:
			return Key::Up;
		case 68:
			return Key::Left;
		case 67:
			return Key::Right;
		case 66:
			return Key::Down;
		case 10:
			return Key::Enter;
		default:
			continue;
		}
	}

	return Key::Enter;
}

#pragma GCC diagnostic pop
#endif
