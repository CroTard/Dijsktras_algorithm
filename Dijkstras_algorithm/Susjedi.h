#pragma once

void susjedi_trazi(RenderWindow& window, std::vector<std::vector<Kvadrat>>& world, unsigned __int64 m, unsigned __int64 n)
{
	unsigned __int64 i = m;
	unsigned __int64 j = n;

	//	cout << "Lijevo" << endl

	world.at(i - 1).at(j).visited = true;
	world.at(i - 1).at(j).current = true;

	world.at(i - 1).at(j).set_color_current();

	//

	//	cout << "Gore" << endl;

	world.at(i).at(j - 1).visited = true;
	world.at(i).at(j - 1).current = true;

	world.at(i).at(j - 1).set_color_current();

	//

	if (true)
	{
		world.at(i - 1).at(j).origin_x = i;
		world.at(i - 1).at(j).origin_y = j;
	}
	else
	{
		world.at(i).at(j - 1).origin_x = i;
		world.at(i).at(j - 1).origin_y = j;
	}

	/*if (world.at(i + 1).at(j).visited == false)
	{
		//	cout << "Desno" << endl;
		world.at(i + 1).at(j).zbroj += world.at(i + 1).at(j).distanca;

		world.at(i + 1).at(j).origin_x = i;
		world.at(i + 1).at(j).origin_y = j;

		world.at(i + 1).at(j).visited = true;
		world.at(i + 1).at(j).current = true;
		world.at(i + 1).at(j).desno = true;

		world.at(i + 1).at(j).set_color_current();
		//cout << "Break" << endl;
	}

	if (world.at(i).at(j + 1).visited == false)
	{
		//	cout << "Dolje" << endl;
		world.at(i).at(j + 1).zbroj += world.at(i).at(j + 1).distanca;

		world.at(i).at(j + 1).origin_x = i;
		world.at(i).at(j + 1).origin_y = j;

		world.at(i).at(j + 1).visited = true;
		world.at(i).at(j + 1).current = true;

		world.at(i).at(j + 1).set_color_visited();
	}*/
}