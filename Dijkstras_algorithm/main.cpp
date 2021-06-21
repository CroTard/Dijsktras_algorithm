#include<SFML/Graphics.hpp>
#include<SFML/System/clock.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window/Mouse.hpp>

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

#include"kvadrat.h"
#include"World_pushback.h"
#include"Mouse.h"
#include"Susjedi.h"

using namespace sf;
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(760, 760), "Dijkstra's algorithm");

	sf::RenderTexture texture;
	if (!texture.create(1200, 800))
		return -1;

	std::vector<std::vector<Kvadrat>>* world = new std::vector<std::vector<Kvadrat>>;
	(*world) = world_pushback(&window, &texture);

	unsigned __int64 broj_i = 1;
	unsigned __int64 broj_j = 1;

	int sw = 1;

	world->at(49).at(49).start = true;
	world->at(49).at(49).distanca = 0;

	world->at(49).at(49).set_color();

	for (unsigned __int64 i = 1; i < world->size() - 1; i++)
	{
		for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
		{
			world->at(i).at(j).zbroj = 0;
			world->at(i).at(j).store = 0;
		}
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				mouse_move(window, *world, event);
			}
			else if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				//mouse_move2(window, *world, event);
			}
			/*else if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
			{
				for (unsigned __int64 i = 1; i < world->size() - 1; i++)
				{
					for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
					{
						if (world->at(i).at(j).start == true || world->at(i).at(j).current == true)
						{
							susjedi_trazi(window, *world, i, j);

							world->at(i).at(j).current = false;

							if (world->at(i).at(j).current == false)
							{
								break;
							}
						}
					}
				}
			}*/
		}

		switch (sw)
		{
		case 1:
			for (unsigned __int64 i = 1; i < world->size() - 1; i++)
			{
				for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
				{
					//window.draw(world->at(i).at(j).kocka);
					world->at(i).at(j).draw_sprite();
				}
			}

			//cout << sw << endl;
			sw = 2;

		case 2:

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				world->clear();

				*world = world_pushback(&window, &texture);

				sw = 1;

				world->at(49).at(49).start = true;
				world->at(49).at(49).distanca = 0;
				world->at(49).at(49).set_color();
				world->at(49).at(49).origin_x = 50;
				world->at(49).at(49).origin_y = 50;

				for (unsigned __int64 i = 1; i < world->size() - 1; i++)
				{
					for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
					{
						world->at(i).at(j).zbroj = 0;
					}
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				for (unsigned __int64 i = 1; i < world->size() - 1; i++)
				{
					for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
					{
						if (world->at(i).at(j).start == true || world->at(i).at(j).current == true)
						{
							susjedi_trazi(window, *world, i, j);
							world->at(i).at(j).visited = true;
							world->at(i).at(j).current = false;

							world->at(i).at(j).set_color_visited();
							//world->at(i).at(j).set_color_current();
						}
					}
				}
			}

		default:

			texture.display();
			window.clear();

			sf::Sprite sprite(texture.getTexture());
			window.draw(sprite);

			for (unsigned __int64 i = 1; i < world->size() - 1; i++)
			{
				for (unsigned __int64 j = 1; j < world->at(i).size() - 1; j++)
				{
					window.draw(world->at(i).at(j).kocka);

					//cout << world->at(i).at(j).visited << " ";
				}
				//cout << endl;
			}

			break;
		}

		window.display();
	}

	delete world;

	return 0;
}