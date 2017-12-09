#pragma once
#include "cinder\gl\gl.h"
#include "cinder\Vector.h"

class Particle
{
public:
	Particle(const ci::vec2 & position, float radius, float mass, float drag);
	void  update();
	void draw();
	ci::vec2 posotion, prevPosotion;
	ci::vec2 forces;
	float radius;
	float mass;
	float drag;
};