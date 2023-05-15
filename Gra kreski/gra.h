#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Gracz.h"
using namespace sf;

class gra
{
private: 
	RenderWindow okno;
	VideoMode videoMode;
	Event ev;
	
	Texture background;
	Gracz* gracz;

	
	void inicjalizacjaWart();
	void inicjalizacjaOkna();
	void inicjalizacjaGracza();
	void initTexture();


public:
	gra();
	virtual ~gra();

	//akcesory
	const bool running() const;

	void renderback();
	void updateGracz();
	void pollEvents();
	void update();
	void renderPlayer();
	void render();
	const RenderWindow& getWindow() const;
};


