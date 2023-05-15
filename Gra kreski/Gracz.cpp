#include "Gracz.h"
#include <cmath>
#include<iostream>

void Gracz::initTexture()
{
	if (this->t_gracz.loadFromFile("resources/Car1.png"))
	{
		std::cout << "Error::Player" << std::endl;

	}
}

void Gracz::initSprite()
{
	this->sprite.setTexture(this->t_gracz);
    this->sprite.setPosition(x_1, y_1);
    this->sprite.setRotation(angle_1 * 180 / 3.1415);
	
}

Gracz::Gracz()
{
	this->initTexture();
	this->initSprite();
}

Gracz::~Gracz()
{
}


void Gracz::ruch()
{

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        
        if (speed_1 < 0) {
            speed_1 += dec_1;
            angle_1 += 0.01;
        }
        else {
            speed_1 += acc_1;
        }
    

	if ( speed_1 != 0) {
		if (speed_1 > maxSpeed_1 / 2.0) {
			speed_1 -= dec_1;
		}
		angle_1 -= turnSpeed_1 * speed_1 / maxSpeed_1;
		}
    }
    else {
        // Przyspieszanie do przodu
        if (speed_1 < maxSpeed_1) {
            speed_1 += acc_1;
        }
    }
    // Pozosta³a czêœæ funkcji ruch() bez zmian

    x_1 += sin(angle_1) * speed_1;
    y_1 -= cos(angle_1) * speed_1;
    sprite.setPosition(x_1, y_1);

}

void Gracz::update()
{
	this->ruch();
    this->sprite.setRotation(angle_1 * 180 / 3.1415);
}

void Gracz::render(RenderTarget& target)
{
	target.draw(this->sprite);
}


