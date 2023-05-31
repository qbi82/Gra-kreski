#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>


class Gracz : public sf::Sprite
{
	
	
private:
	double x;
	double y;
	double speed;
	double angle;
	double maxSpeed;
	double acc;
	double dec;
	double turnSpeed;
	Sprite sprite;
	sf::Texture t_gracz;
	int liczba_okrazen;

	void initTexture();
	void initSprite();

public:
	Gracz();
	virtual ~Gracz();

	void setLiczbaOkrzen(int liczba);
	int getLiczbaOkrzen() ;
	void ruch();
	void update();
	void render(sf::RenderTarget& target);
};

