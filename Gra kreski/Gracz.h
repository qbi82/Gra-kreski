#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include <SFML/Audio.hpp>
using namespace sf;
class Gracz 
{
	double x_1 = 980, y_1 = 628;
	double speed_1 = 0, angle_1 = 3.14/2;
	double maxSpeed_1 = 13;
	double acc_1 = 0.175, dec_1 = 0.4;
	double turnSpeed_1 = 0.09;
	
private:

	Sprite sprite;
	Texture t_gracz;
	

	void initTexture();
	void initSprite();

public:
	
	Gracz();
	
	virtual ~Gracz();
	void ruch();
	void update();
	void render(RenderTarget& target);
};

