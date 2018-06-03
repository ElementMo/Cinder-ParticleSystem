
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;


#define WIDTH getWindowWidth()
#define HEIGHT getWindowHeight()

class BasicApp : public App {
public:
	void draw() override;
	void setup() override;
	float map(float i, float start, float end, float Tstart, float Tend);
private:
	float turbulance;
	vec2 loc, dir;
};

class Particle
{
private:
	vec2 pos, dir;
	float speed;
public:
	Particle(vec2 temp_pos, vec2 temp_dir, float temp_speed);
	void run(int tur);
	void checkEdge();
	void render(float col);
};

Particle *pars[5000];

void BasicApp::setup()
{
	app::setFullScreen();
	for (int i = 0; i < 5000; i++) {
		vec2 loc = vec2(Rand().randInt(WIDTH), Rand().randInt(HEIGHT));
		float angle = Rand().randFloat(6.28);
		vec2 dir = vec2(cos(angle), sin(angle));
		float speed = Rand().randFloat(1.0, 3.0);

		pars[i] = new Particle(loc, dir, speed);
		
	}
}

void BasicApp::draw()
{
	gl::color(ColorA(0, 0, 0, 0.1));
	gl::drawSolidCircle(getWindowCenter(), 1200);

	for (int i = 0; i < 5000; i++)
	{
		pars[i]->render(map(i,0,5000,0.1,0.8));
		pars[i]->run(getMousePos().x);
		pars[i]->checkEdge();
	}
}

float BasicApp::map(float i, float start, float end, float Tstart, float Tend)
{
	return Tstart + ((Tstart - Tend) / (start - end)*(i - start));
}

CINDER_APP(BasicApp, RendererGl)


Particle::Particle(vec2 temp_pos, vec2 temp_dir, float temp_speed)
{
	pos = temp_pos;
	dir = temp_dir;
	speed = temp_speed;
}
void Particle::run(int tur)
{
	float angle = Perlin().noise(pos.x / 500, pos.y / 500) * tur;
	dir.x = cos(angle);
	dir.y = sin(angle);
	dir.x *= speed;
	dir.y *= speed;
	pos.x += dir.x;
	pos.y += dir.y;
}
void Particle::checkEdge()
{
	if (pos.x < 0 || pos.x > WIDTH || pos.y<0 || pos.y>HEIGHT)
	{
		pos.x = Rand().randFloat(WIDTH);
		pos.y = Rand().randFloat(HEIGHT);
	}
}
void Particle::render(float col)
{
	gl::color(ColorA(CM_HSV, col, 1, 1, 0.5));
	gl::drawSolidCircle(vec2(pos.x, pos.y), 2);
}