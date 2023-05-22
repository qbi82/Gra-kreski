#include "gra.h"
using namespace sf;

void gra::liniaStartu()
{
	
	bool przekroczyl_linie = false;
	bool pierwsza_iteracja = true;
	//rysowanie lini mety
	sf::RectangleShape finishLine(sf::Vector2f(1.0f, 298.0f));
	finishLine.setPosition(988.0f, 628.0f);
	finishLine.setFillColor(sf::Color::Green);
	/*if (t_gracz.getGlobalBounds().intersects(finishLine.getGlobalBounds()) && !przekroczyl_linie) {
		okrazenia_ilosc++;
		przekroczyl_linie = true;
		wskaznik_okrazen.setString("Okrazenie: " + std::to_string(okrazenia_ilosc));
		clock1.restart();

		czas_startowy_biezacego_okrazenia = czas_okrazenia_gr1.getElapsedTime();

		sf::Time czas_trwania_okrazenia = czas_startowy_biezacego_okrazenia - czas_koncowy_poprzedniego_okrazenia;
		if (okrazenia_ilosc > 1)
		{
			if (pierwsza_iteracja) {
				czas_najszybszy_gr1 = czas_trwania_okrazenia.asSeconds();
				pierwsza_iteracja = false;
			}
			Czas_najszybszy_Gracza1.setString("Najszybsze okrazenie: " + std::to_string(czas_najszybszy_gr1));
		}
		if (okrazenia_ilosc != 1) {
			CZAS_OKRAZENIA_1.setString("Czas okrazenia " + std::to_string(okrazenia_ilosc) + ": " + std::to_string(czas_trwania_okrazenia.asSeconds()));
			if (okrazenia_ilosc > 1 && czas_najszybszy_gr1 > czas_trwania_okrazenia.asSeconds())
			{
				czas_najszybszy_gr1 = czas_trwania_okrazenia.asSeconds();
			}
			czas_koncowy_poprzedniego_okrazenia = czas_startowy_biezacego_okrazenia;

		}

	}*/
	this->okno.draw(finishLine);
}

void gra::licznikOkrazen()
{

}

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

	wskaznik_okrazen.setFont(font);
	wskaznik_okrazen.setCharacterSize(40);
	wskaznik_okrazen.setFillColor(Color::Black);
	wskaznik_okrazen.setPosition(20, 0);
	wskaznik_okrazen.setString("Okrazenia: " + std::to_string(okrazenia_ilosc));

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

void gra::liczenie_okrazen()
{

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

void gra::wystartujgre()
{
	/*Event e2;
	while (this->okno.pollEvent(this->e2))
	{
		if (e2.type == sf::Event::KeyPressed)
		{
			if (e2.key.code == sf::Keyboard::Space)
			{
				start = true;
				switch_help = !switch_help;
			}
		}
	}

	if (switch_help)
	{
		
	*/	/*okno.draw(controls_text);
	}*/
		
	}




void gra::updateGracz()
{
	this->gracz->update();
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
	this->liniaStartu();
	okno.draw(wskaznik_okrazen);
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


