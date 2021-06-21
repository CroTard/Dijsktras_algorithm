#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>

using namespace std;

struct Kvadrat
{
	Kvadrat(sf::Color boja, int x, int y, bool granicni, int distanca, bool visited, sf::RenderWindow* window, sf::RenderTexture* texture);
	Kvadrat();

	void draw_sprite();

	sf::Color get_color();

	void set_color();
	void set_color_visited();
	void set_color_current();
	void set_ziv(bool ziv);

	void set_xy(int x, int y);

	sf::RectangleShape kocka;
	sf::Color boja;

	int x, y;
	int origin_x;
	int origin_y;
	int zbroj;
	int distanca;
	int store;

	bool start;
	bool end;
	bool desno;

	bool current;
	bool visited;
	bool granicni;

	sf::Sprite sprite;

private:

	bool ziv;

	float value;

	sf::RenderWindow* window;
	sf::RenderTexture* texture;
	sf::Text text;
	sf::Font font;

	string broj_udalj;
};
