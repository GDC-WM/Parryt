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

void Actor::update(float delta) {
    this->x += this->xSpeed * delta;
    this->y += this->ySpeed * delta;
}

const double Actor::getSpeed(void) {
    return sqrt(pow(this->xSpeed, 2) + pow(this->ySpeed, 2));
}

const double Actor::getDirection(void) {
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

const bool Actor::collidesSquare(Actor &a) {
    return (
        a.getX() <= this->x + this->width &&
        a.getX() + a.getWidth() >= this->x &&
        a.getY() <= this->y + this->height &&
        a.getY() + a.getHeight() >= this->y
    );
}

const bool Actor::collidesCircle(Actor &a) {
    return (
        sqrt(pow(this->getCenterX() - a.getCenterX(), 2) +
        pow(this->getCenterY() - a.getCenterY(), 2)) <
        (this->getHeight() / 2) + (a.getHeight() / 2)
    );
}

const bool Actor::collidesCircle(Actor &a, int range) {
    return (
        sqrt(pow(this->getCenterX() - a.getCenterX(), 2) +
        pow(this->getCenterY() - a.getCenterY(), 2)) <
        range
    );
}

const bool Actor::liesInsideSquare(Actor &a) {
    return (
        a.getX() <= this->x &&
        a.getX() + a.getWidth() >= this->x + this->width &&
        a.getY() <= this->y &&
        a.getY() + a.getHeight() >= this->y + this->height
    );
}

void Actor::draw(sf::RenderWindow &window) {

}
