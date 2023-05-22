#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Gracz.h"
#include <string>
#include <cmath>
#include<iostream>
using namespace sf;

class gra
	
{
private:
	bool start=false;
	bool switch_help = true;
	RenderWindow okno;
	VideoMode videoMode;
	Event ev;
	Event e2;
	Texture background;
	Gracz* gracz;
	Font font;
	bool przekroczyl_linie = false;
	bool pokaz_tekst = true;
	int okrazenia_ilosc = 0;
	bool pierwsza_iteracja = true;
	double limit_okrazen = 5;
	sf::Text wskaznik_okrazen;
	sf::Text text;
	sf::Text CZAS_OKRAZENIA_1;
	sf::Text zegar;
	Clock clock2;
	Time granice;
	Clock clock1;
	Time time;
	Clock clock;
	Time startowanie;
	Clock czas_okrazenia_gr1;
	sf::Text controls_text;
	Text Czas_najszybszy_Gracza1;
	Time czas_koncowy_poprzedniego_okrazenia = czas_okrazenia_gr1.getElapsedTime();
	Time czas_startowy_biezacego_okrazenia;
	float czas_najszybszy_gr1;
	float odliczanie = 3;
	void inicjalizacjaWart();
	void inicjalizacjaOkna();
	void inicjalizacjaGracza();
	void initTexture();
	void initTXT();
	void liniaStartu();
	void liczenie_okrazen();
	

public:
	gra();
	virtual ~gra();

	void initFont();
	void PokazSterowanie();
	const bool running() const;
	void wystartujgre();
	
	void licznikOkrazen();
	void renderback();
	void updateGracz();
	void pollEvents();
	void update();
	void renderPlayer();
	void render();
	const RenderWindow& getWindow() const;
};


