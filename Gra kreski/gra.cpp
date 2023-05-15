#include "gra.h"
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
}

//Konstruktory / destruktory
gra::gra()
{
	this->initTexture();
	this->inicjalizacjaWart();
	this->inicjalizacjaOkna();
	this->inicjalizacjaGracza();
	
}

void gra::initTexture()
{
	if (this->background.loadFromFile("resources/es3-GT¯.stad.png"))
	{


	}
}
gra::~gra()
{
	delete this->gracz;
}



const bool gra::running() const
{
	return this->okno.isOpen();
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
	while(this->okno.pollEvent(e))
	{
		if (e.Event::type == Event::Closed)
			this->okno.close();
		
		if(e.Event::KeyPressed && e.Event::key.code == Keyboard::Escape)
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
	
	this->okno.display();
	
	
}

const RenderWindow& gra::getWindow() const
{
	
	return this->okno;
}


