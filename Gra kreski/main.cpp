#include <iostream>
#include "gra.h"
#include "MainMenu.h"
using namespace std;
using namespace sf;
int main()
{
	srand(static_cast<unsigned>(time(0)));
	gra gra;

	while(gra.running())
	{
		//Update
		gra.update();
		
		//Render
		gra.render();
	}

    return 0;
}