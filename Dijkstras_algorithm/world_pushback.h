#pragma once

std::vector<std::vector<Kvadrat>> world_pushback(sf::RenderWindow* window, sf::RenderTexture* texture)
{
	std::vector<std::vector<Kvadrat>> world;

	bool granicni;
	int distanca;
	bool visited = false;

	srand(time(nullptr));
	for (int i = 0; i <= 50; i++)
	{
		std::vector<Kvadrat>v;

		for (int j = 0; j <= 50; j++)
		{
			int broj = rand() % 10 + 1;

			int r = 0;
			int g = 0;
			int b = 0;
			int a = 0;

			distanca = broj;

			if (i == 0 || i == 50 || j == 0 || j == 50)
			{
				granicni = true;
				distanca = 99;
			}
			else
			{
				granicni = false;
			}

			Kvadrat kvad(sf::Color(r, g, b, a), i, j, granicni, distanca, visited, window, texture);

			v.push_back(kvad);
		}
		world.push_back(v);
	}

	return world;
}
