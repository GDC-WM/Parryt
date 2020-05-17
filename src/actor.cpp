#include "actor.h"

#include "math.h"
#define PI 3.14159265

Actor::Actor(double x, double y, double width, double height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->xSpeed =
	this->ySpeed = 0;
}

void Actor::update(const float &dt) {
	this->x += this->xSpeed * dt;
	this->y += this->ySpeed * dt;
}

const double Actor::getSpeed(void) const {
	return sqrt(pow(this->xSpeed, 2) + pow(this->ySpeed, 2));
}

const double Actor::getDirection(void) const {
	return (atan2(this->ySpeed, this->xSpeed) * 180.0 / PI);
}

void Actor::setOrientation(int x, int y) {
	float yDiff = this->getCenterX() - x;
	float xDiff = this->getCenterY() - y;
	this->orientation = atan(yDiff / xDiff) * 180 / PI;
}

void Actor::setOrientation(Actor &a) {
	float xDiff = this->getCenterX() - a.getCenterX();
	float yDiff = this->getCenterY() - a.getCenterY();
	this->orientation = atan(yDiff / xDiff) * 180 / PI;
}

const bool Actor::collidesSquare(const Actor &a) {
	return (
		a.getX() <= this->x + this->width &&
		a.getX() + a.getWidth() >= this->x &&
		a.getY() <= this->y + this->height &&
		a.getY() + a.getHeight() >= this->y
	);
}

const Actor &Actor::getSquareOverlap(const Actor &a) {
	double x, y, w, h;
	if (a.getX() <= this->x + this->width) ;
	else if (a.getX() + a.getWidth() > this->x) ;
	else throw std::domain_error("Not overlapping");
}

const bool Actor::collidesCircle(const Actor &a) {
	return (
		sqrt(pow(this->getCenterX() - a.getCenterX(), 2) +
		pow(this->getCenterY() - a.getCenterY(), 2)) <
		(this->getHeight() / 2) + (a.getHeight() / 2)
	);
}

const bool Actor::collidesCircle(const Actor &a, int range) {
	return (
		sqrt(pow(this->getCenterX() - a.getCenterX(), 2) +
		pow(this->getCenterY() - a.getCenterY(), 2)) <
		range
	);
}

const bool Actor::liesInsideSquare(const Actor &a) {
	return (
		a.getX() <= this->x &&
		a.getX() + a.getWidth() >= this->x + this->width &&
		a.getY() <= this->y &&
		a.getY() + a.getHeight() >= this->y + this->height
	);
}

sf::Shape &getShape(void) {

}
