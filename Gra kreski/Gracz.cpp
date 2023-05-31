#include "Gracz.h"
#include <cmath>
#include<iostream>

void Gracz::initTexture()
{
	if (!this->t_gracz.loadFromFile("resources/Car2.png"))
	{
		std::cout << "Error::Player" << std::endl;

	}
    sprite.setScale(1.0f, .9f);
}

void Gracz::initSprite()
{
	this->sprite.setTexture(this->t_gracz);
    this->sprite.setPosition(x, y);
    this->sprite.setRotation(angle * 180 / 3.1415);
	
}

Gracz::Gracz()
{
    this->x = 980.0;
    this->y = 628.0;
    this->speed = 0.0;
    this->angle = (3.14)/2;
    this->maxSpeed = 13.0;
    this->acc = 0.175;
    this->dec = 0.4;
    this->turnSpeed = 0.09;
	this->initTexture();
	this->initSprite();
}

Gracz::~Gracz()
{
}

void Gracz::setLiczbaOkrzen(int liczba)
{
    liczba_okrazen = liczba;
}

int Gracz::getLiczbaOkrzen()
{
    return liczba_okrazen;
}

void Gracz::ruch()
{


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        
        if (speed < 0) {
            speed += dec;
            angle += 0.01;
        }
        else {
            speed += acc;
        }
    

	if ( speed != 0) {
		if (speed > maxSpeed / 2.0) {
			speed -= dec;
		}
		angle -= turnSpeed * speed/ maxSpeed;
		}
    }
    else {
        // Przyspieszanie do przodu
        if (speed < maxSpeed) {
            speed += acc;
        }
    }
    // Pozosta³a czêœæ funkcji ruch() bez zmian

    x += sin(angle) * speed;
    y -= cos(angle) * speed;
    sprite.setPosition(x, y);

  
}

void Gracz::update()
{
	this->ruch();
    this->sprite.setRotation(angle * 180 / 3.1415);
}

void Gracz::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


