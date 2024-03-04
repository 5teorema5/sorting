#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

using namespace sf;

const int s = 800;

struct row
{
	int x;
	int h;
} rows[s];

int main()
{
	RenderWindow window(VideoMode(940, 690), "sort");
	RectangleShape rectangle;
	RectangleShape wind;
	Event event;

	Font font;
	if (!font.loadFromFile("Fonts/GOST type A Standard.ttf"))
		throw("COULD NOT LOAD FONT!");
	Text t1;
	t1.setFont(font);
	t1.setCharacterSize(24);
	t1.setStyle(Text::Bold);
	t1.setString("quick sort O(NlogN)");
	t1.setRotation(270);
	t1.setPosition(5, 585);
	Text t2;
	t2.setFont(font);
	t2.setCharacterSize(24);
	t2.setStyle(Text::Bold);
	t2.setString("sort O(N^2)");
	t2.setRotation(270);
	t2.setPosition(5, 235);
	Text t3;
	t3.setFont(font);
	t3.setCharacterSize(20);
	t3.setStyle(Text::Bold);
	t3.setString("name");
	t3.setPosition(240, 315);
	Text t4;
	t4.setFont(font);
	t4.setCharacterSize(20);
	t4.setStyle(Text::Bold);
	t4.setString("name");
	t4.setPosition(660, 315);
	Text t5;
	t5.setFont(font);
	t5.setCharacterSize(20);
	t5.setStyle(Text::Bold);
	t5.setString("name");
	t5.setPosition(240, 640);
	Text t6;
	t6.setFont(font);
	t6.setCharacterSize(20);
	t6.setStyle(Text::Bold);
	t6.setString("Sort Choice");
	t6.setPosition(650, 640);
	Text title;
	title.setFont(font);
	title.setCharacterSize(28);
	title.setStyle(Text::Underlined);
	title.setStyle(Text::Bold);
	title.setString("<<< Comparing the speed of different sorts >>>");
	title.setPosition(220, 5);

	bool isCreated = false;
	int index3 = 0;
	int index4 = s/2;
	int work3 = 0;
	int work4 = 0;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		if (!isCreated)
		{
			for (int i = 0; i < s; i++)
			{
				rows[i].x = i;
				rows[i].h = 1 + rand() % 250;
			}
			isCreated = true;
		}

		if (isCreated)
		{
			//3я четверть
			if (rows[index3].h > rows[index3 + 1].h)
			{
				std::swap(rows[index3].h, rows[index3 + 1].h);
			}
			//4ая четверть
			int min_elem = 10000, min_index;
			for (unsigned int j = index4; j < s; j++)
			{
				if (rows[j].h < min_elem)
				{
					min_elem = rows[j].h;
					min_index = j;
				}
			}
			rows[min_index].h = rows[index4].h;
			rows[index4].h = min_elem;

		}

		window.clear(Color::Black);
		//отрисовка рамок
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				wind.setSize(Vector2f(410, 270));
				wind.setPosition(Vector2f(50 + 430 * i, 50 + 320 *j));
				wind.setFillColor(Color::Black);
				wind.setOutlineThickness(2);
				wind.setOutlineColor(Color::White);
				window.draw(wind);
			}
		}
		//отрисовка 3ей четверти
		for (int i = 0; i < s/2; i++)
		{
			rectangle.setSize(Vector2f(1, rows[i].h));
			rectangle.setPosition(Vector2f(i+55, 630));
			rectangle.setRotation(180);
			rectangle.setFillColor(Color(51, 204, 0));
			if (i == index3) rectangle.setFillColor(Color(51, 102, 0));
			window.draw(rectangle);
		}
		//отрисовка 4ой четверти
		for (int i = s/2; i < s; i++)
		{
			rectangle.setSize(Vector2f(1, rows[i].h));
			rectangle.setPosition(Vector2f(i + 85, 630));
			rectangle.setRotation(180);
			rectangle.setFillColor(Color::Yellow);
			if (i == index4) rectangle.setFillColor(Color(204, 204, 0));
			window.draw(rectangle);
		}
		
		window.draw(t1);
		window.draw(t2);
		window.draw(t3);
		window.draw(t4);
		window.draw(t5);
		window.draw(t6);
		window.draw(title);
		window.display();

		index3++;
		index4++;
		if (index3 > s/2-2 && work3 != s/2)
		{
			index3 = 0;
			work3++;
		}
		if (index4 > s-2-work4)
		{
			index4 = s/2;
			work4++;
		}
	}

	return 0;
}