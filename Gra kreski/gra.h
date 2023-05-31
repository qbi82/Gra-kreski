#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Gracz.h"
#include <string>
#include <cmath>
#include<iostream>


class gra
	
{
private:
	bool start=false;
	sf::RectangleShape finishLine;
	bool switch_help = true;
	sf::RenderWindow okno;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Event e2;
	sf::Texture background;
	Gracz* gracz;
	sf::Font font;
	bool przekroczyl_linie = false;
	bool pokaz_tekst = true;
	int okrazenia_ilosc = 0;
	bool pierwsza_iteracja = true;
	double limit_okrazen = 5;
	sf::Text wskaznik_okrazen;
	sf::Text text;
	sf::Text CZAS_OKRAZENIA_1;
	sf::Text zegar;
	sf::Clock clock2;
	sf::Time granice;
	sf::Clock clock1;
	sf::Time time;
	sf::Clock clock;
	sf::Time startowanie;
	sf::Clock czas_okrazenia_gr1;
	sf::Text controls_text;
	sf::Text Czas_najszybszy_Gracza1;
	sf::Time czas_koncowy_poprzedniego_okrazenia = czas_okrazenia_gr1.getElapsedTime();
	sf::Time czas_startowy_biezacego_okrazenia;
	float czas_najszybszy_gr1;
	float odliczanie = 3;
	void inicjalizacjaWart();
	void inicjalizacjaOkna();
	void inicjalizacjaGracza();
	void initTexture();
	void initTXT();
	
	
	

public:
	gra();
	virtual ~gra();

	void initFont();
	void PokazSterowanie();
	const bool running() const;

	void renderLiczbaOkrzen();
	void rysujLinieMety();
	void liczOkrazeniaGracza(Gracz& t_gracz);
	void aktualizujLiczbeOkrzen();
	void liczOkrazeniaGracza();
	void licznikOkrazen();


	void renderback();
	void updateGracz();
	void pollEvents();
	void update();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};


