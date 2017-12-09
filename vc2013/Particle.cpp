#include "Particle.h"

Particle::Particle(const ci::vec2 & position, float radius, float mass, float drag)
{
	this->posotion = position;
	this->radius = radius;
	this->drag = drag;
	this->mass = mass;

	forces = ci::vec2::
}