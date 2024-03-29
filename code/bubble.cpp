#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

const int s = 300;

struct row
{
    int x;
    int h;
} rows[s];

int main()
{
    RenderWindow window(VideoMode(940, 640), "sort");
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
    t1.setString("<<bubble sorting O(N^2)>>");
    t1.setPosition(390, 10);

    bool isCreated = false;
    int index = 0;
    int r_1 = 1;
    int l_2 = 0, r_2 = 1;
    int min_elen_3 = 10000, min_ind;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //����� ��������

        if (isCreated)
        {
            for (int j = 0; j < s - r_1; j++) {
                bool flag = false;
                if (rows[j].h > rows[j + 1].h) {
                    std::swap(rows[j].h, rows[j + 1].h);
                    flag = true;
                }
                window.clear(Color::Black);
                wind.setSize(Vector2f(906, 566));
                wind.setPosition(Vector2f(15, 57));
                wind.setFillColor(Color::Black);
                wind.setOutlineThickness(2);
                wind.setOutlineColor(Color::White);
                window.draw(wind);
                window.draw(t1);
                for (int i = 0; i < s; ++i)
                {
                    rectangle.setSize(Vector2f(2, rows[i].h));
                    rectangle.setPosition(Vector2f(i * 3 + 20, 600 + 20));
                    rectangle.setRotation(180);
                    rectangle.setFillColor(Color(102, 102, 255));
                    if (flag) {
                        if (i == j) rectangle.setFillColor(Color(204, 0, 0));
                        if (i == j + 1) rectangle.setFillColor(Color(204, 0, 0));
                    }
                    window.draw(rectangle);
                }
                window.display();
            }
            r_1++;
        }

        if (!isCreated)
        {
            for (int i = 0; i < s; ++i)
            {
                rows[i].x = i;
                rows[i].h = 1 + rand() % 550;
            }
            isCreated = true;
        }

        index++;
        if (index >= 799)
            index = 0;
    }

    return 0;
}
