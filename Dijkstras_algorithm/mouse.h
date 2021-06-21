#pragma once

#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Window/Mouse.hpp>
#include<SFML/System/clock.hpp>
#include<SFML/Audio.hpp>
#include"kvadrat.h"

using namespace sf;

//void mouse_move(RenderWindow& window, std::vector<std::vector<Kvadrat>>& world, sf::Event& event)
//{
//	Vector2i mouse_poz = Mouse::getPosition(window);
//	Vector2f world_poz = window.mapPixelToCoords(mouse_poz);
//
//	bool Start = Mouse::isButtonPressed(Mouse::Left);
//	bool End = Mouse::isButtonPressed(Mouse::Right);
//
//	for (unsigned __int64 i = 0; i < world.size(); i++)
//
//	{
//		for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
//		{
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
//			{
//				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//
//				sf::FloatRect bounds = world.at(i).at(j).sprite.getGlobalBounds();
//
//				if (bounds.contains(mouse))
//				{
//					cout << world.at(i).at(j).distanca << endl;
//					cout << world.at(i).at(j).visited << endl;
//				}
//			}
//
//			if (world.at(i).at(j).kocka.getGlobalBounds().contains(world_poz.x, world_poz.y))
//			{
//				if (Start)
//				{
//					for (unsigned __int64 n = 0; n < world.size(); n++)
//
//					{
//						for (unsigned __int64 m = 0; m < world.at(n).size(); m++)
//						{
//							world.at(n).at(m).start = false;
//							world.at(n).at(m).end = false;
//							world.at(n).at(m).current = false;
//							world.at(n).at(m).set_color();
//						}
//					}
//
//					world.at(i).at(j).start = true;
//					world.at(i).at(j).current = true;
//					world.at(i).at(j).distanca = 0;
//					world.at(i).at(j).set_color();
//				}
//			}
//		}
//	}
//}
void mouse_move(RenderWindow& window, std::vector<std::vector<Kvadrat>>& world, sf::Event& event)
{
	Vector2i mouse_poz = Mouse::getPosition(window);
	Vector2f world_poz = window.mapPixelToCoords(mouse_poz);

	//bool Start = Mouse::isButtonPressed(Mouse::Left);
	bool End = Mouse::isButtonPressed(Mouse::Left);
	for (unsigned __int64 i = 0; i < world.size(); i++)
	{
		for (unsigned __int64 j = 0; j < world.at(i).size(); j++)
		{
			if (world.at(i).at(j).kocka.getGlobalBounds().contains(world_poz.x, world_poz.y))
			{
				if (End)
				{
					for (unsigned __int64 n = 0; n < world.size(); n++)

					{
						for (unsigned __int64 m = 0; m < world.at(n).size(); m++)
						{
							world.at(n).at(m).current = false;
							world.at(n).at(m).end = false;
							//world.at(i).at(j).current = false;
							world.at(n).at(m).set_color();
						}
					}

					world.at(i).at(j).end = true;
					world.at(i).at(j).set_color();
				}
			}
		}
	}
}