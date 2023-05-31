#include "gra.h"
#include <iostream>
#include <sstream>
using namespace sf;




//private funkc
void gra::inicjalizacjaWart()
{
	this->okno;
}


void gra::inicjalizacjaOkna()
{
	
	this->okno.create(VideoMode::getDesktopMode(), "Menu", Style::Titlebar | Style::Close | Style::Fullscreen);
	this->okno.setFramerateLimit(61);
}

void gra::inicjalizacjaGracza()
{
	this->gracz = new Gracz();
	this->gracz->setLiczbaOkrzen(0);
}

gra::gra()
{

	this->initTexture();
	this->initFont();
	this->initTXT();
	this->inicjalizacjaWart();
	this->inicjalizacjaOkna();
	this->inicjalizacjaGracza();
	
	
}

void gra::initFont()
{
	this->font.loadFromFile("ChunkFive-Regular.otf");


}
void gra::initTexture()
{
	this->background.loadFromFile("resources/es3-GT¯.stad.png");
	
}

void gra::initTXT()
{
	if (!font.loadFromFile("ChunkFive-Regular.otf")) {
		// obs³uga b³êdu z za³adowaniem czcionkiif (!this->t_gracz.loadFromFile("resources/Car2.png"))
		{
			std::cout << "Error::Player" << std::endl;

		}
	}

	
	

	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(Color::Black);
	text.setPosition(20, 40);

	CZAS_OKRAZENIA_1.setFont(font);
	CZAS_OKRAZENIA_1.setCharacterSize(40);
	CZAS_OKRAZENIA_1.setFillColor(Color::Black);
	CZAS_OKRAZENIA_1.setPosition(20, 80);

	zegar.setFont(font);
	zegar.setCharacterSize(100);
	zegar.setFillColor(Color::Black);
	zegar.setPosition(600, 360);

	
	
	czas_okrazenia_gr1.restart();

	
	start = false;
	
	RectangleShape Okrazenia(Vector2f(661.0f, 20.0f));
	Okrazenia.setSize(sf::Vector2f(661, 20));
	Okrazenia.setFillColor(Color::Black);
	Okrazenia.setOutlineThickness(2);
	Okrazenia.setOutlineColor(Color::Black);

	Czas_najszybszy_Gracza1.setFont(font);
	Czas_najszybszy_Gracza1.setCharacterSize(40);
	Czas_najszybszy_Gracza1.setFillColor(Color::Black);
	Czas_najszybszy_Gracza1.setPosition(700, 20);
	
}




gra::~gra()
{
	delete this->gracz;
}



void gra::PokazSterowanie()
{
	
	controls_text.setFont(this->font);
	controls_text.setCharacterSize(40);
	controls_text.setFillColor(sf::Color::Black);
	controls_text.setPosition(20, 150);
	controls_text.setString("LEWO - SKRET W LEWO\nSPACJA - HAMULEC\nESC - WYJSCIE");
}

const bool gra::running() const
{
	return this->okno.isOpen();
}




void gra::rysujLinieMety()
{
	finishLine.setSize(sf::Vector2f(1.0f, 280.0f));
	finishLine.setPosition(988.0f, 628.0f);
	finishLine.setFillColor(sf::Color::Green);
	this->okno.draw(finishLine);
}

void gra::liczOkrazeniaGracza(Gracz& t_gracz)
{
	if (t_gracz.getGlobalBounds().intersects(finishLine.getGlobalBounds()) && !przekroczyl_linie)
	{
		int liczba_okrazen = t_gracz.getLiczbaOkrzen() + 1;
		t_gracz.setLiczbaOkrzen(liczba_okrazen);
		przekroczyl_linie = true;
		aktualizujLiczbeOkrzen();
		clock1.restart();
	}
	else if (!t_gracz.getGlobalBounds().intersects(finishLine.getGlobalBounds()))
	{
		przekroczyl_linie = false;
	}
}


void gra::aktualizujLiczbeOkrzen()
{
	int liczba_okrazen_w = gracz->getLiczbaOkrzen();

	wskaznik_okrazen.setString("Okrazenia: " + std::to_string(liczba_okrazen_w));

}


void gra::renderLiczbaOkrzen()
{
	sf::Text wskaznik_okrazen;
	wskaznik_okrazen.setFont(this->font);
	wskaznik_okrazen.setCharacterSize(24);
	wskaznik_okrazen.setFillColor(sf::Color::White);
	wskaznik_okrazen.setPosition(10.f, 10.f);

	std::stringstream ss;
	ss << "Liczba okr¹¿eñ: " << this->gracz->getLiczbaOkrzen();
	wskaznik_okrazen.setString(ss.str());

	this->okno.draw(wskaznik_okrazen);
}




void gra::updateGracz()
{
	this->gracz->update();
	aktualizujLiczbeOkrzen();
}

void gra::pollEvents()
{
	while (this->okno.pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->okno.close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
			{
				this->okno.close();
			}
		}
	}
}

void gra::update()
{
	Event e;
	
		while (this->okno.pollEvent(e))
		{
			if (e.Event::type == Event::Closed)
				this->okno.close();

			if (e.Event::KeyPressed && e.Event::key.code == Keyboard::Escape)
				this->okno.close();

		}
		this->updateGracz();
		this->liczOkrazeniaGracza(*gracz);
		this->renderLiczbaOkrzen();
	}
	

void gra::renderPlayer()
{
	this->gracz->render(this->okno);
}
	
void gra::renderback()
{
	Sprite sprite_backg;
	sprite_backg.setTexture(this->background);
	sprite_backg.setScale(static_cast<float>(this->okno.getSize().x) / sprite_backg.getTexture()->getSize().x,
		static_cast<float>(this->okno.getSize().y) / sprite_backg.getTexture()->getSize().y);
	this->okno.draw(sprite_backg);
	
}

void gra::render()
{
	this->okno.clear();
	this->renderback();
	this->renderPlayer();
	this->rysujLinieMety();
	this->renderLiczbaOkrzen(); // Dodane wywo³anie renderLiczbaOkrzen()
	okno.draw(text);
	okno.draw(CZAS_OKRAZENIA_1);
	okno.draw(zegar);
	okno.draw(Czas_najszybszy_Gracza1);
	
	this->okno.display();
}


const RenderWindow& gra::getWindow() const
{
	
	return this->okno;
}


