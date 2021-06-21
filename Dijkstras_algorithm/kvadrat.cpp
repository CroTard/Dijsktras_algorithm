#include"kvadrat.h"

Kvadrat::Kvadrat(sf::Color boja, int x, int y, bool granicni, int distanca, bool visited, sf::RenderWindow* window, sf::RenderTexture* texture)
{
	//velicina
	float value = 15.f;

	kocka = sf::RectangleShape(sf::Vector2f(value, value));

	kocka.setOutlineColor(sf::Color(120, 120, 120));
	kocka.setOutlineThickness(1);
	kocka.setFillColor(boja);
	kocka.setPosition(value * x, value * y);

	this->texture = texture;
	this->broj_udalj = broj_udalj;
	this->value = value;
	this->x = x;
	this->y = y;
	this->window = window;
	this->granicni = granicni;
	this->distanca = distanca;
	this->visited = visited;
}

void Kvadrat::set_ziv(bool ziv)
{
	this->ziv = ziv;
}

Kvadrat::Kvadrat()
{
	this->x = x;
	this->y = y;
	this->kocka = kocka;
}

void Kvadrat::draw_sprite()
{
	if (distanca == 1)
	{
		sf::Texture tex;
		tex.loadFromFile("1.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 2)
	{
		sf::Texture tex;
		tex.loadFromFile("2.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 3)
	{
		sf::Texture tex;
		tex.loadFromFile("3.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 4)
	{
		sf::Texture tex;
		tex.loadFromFile("4.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 5)
	{
		sf::Texture tex;
		tex.loadFromFile("5.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 6)
	{
		sf::Texture tex;
		tex.loadFromFile("6.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 7)
	{
		sf::Texture tex;
		tex.loadFromFile("7.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 8)
	{
		sf::Texture tex;
		tex.loadFromFile("8.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 9)
	{
		sf::Texture tex;
		tex.loadFromFile("9.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
	else if (distanca == 10)
	{
		sf::Texture tex;
		tex.loadFromFile("10.png");
		sf::Sprite sprite;
		sprite.setTexture(tex);
		sprite.setPosition(value * x, value * y);
		this->sprite = sprite;
		texture->draw(sprite);
	}
}

void Kvadrat::set_color()
{
	if (start == true)
	{
		end = false;
		kocka.setFillColor(sf::Color(255, 0, 0, 255));
	}
	if (start == false)
	{
		kocka.setFillColor(sf::Color(0, 0, 0, 0));
	}
	if (end == true)
	{
		kocka.setFillColor(sf::Color(255, 255, 0, 255));
	}
}

void Kvadrat::set_color_visited()
{
	if (visited == true)
	{
		kocka.setFillColor(sf::Color(255, 0, 0, 150));
	}
}

void Kvadrat::set_color_current()
{
	if (current == true)
	{
		kocka.setFillColor(sf::Color(255, 255, 0, 150));
	}
}

sf::Color Kvadrat::get_color()
{
	return boja;
}

void Kvadrat::set_xy(int x, int y)
{
	this->x = x;
	this->y = y;
}