#include <memory>
#include <iostream>
#include <list>

#include "math.h"
#define PI 3.14159265

#include "actor.h"
#include "character.h"


Character::Character(double x, double y, double width, double height, double mass, double maxSpeed, int maxHealth)
    : Actor(x, y, width, height) {
    this->mass = mass;
    this->maxSpeed = maxSpeed;
    this->health =
    this->maxHealth = maxHealth;
}

void Character::damage(float d) {
    this->health -= d;
    if (this->health > this->maxHealth) this->health = this->maxHealth;
    if (this->health < 0) this->health = 0;
}

void Character::heal(int healAmount) {
    this->health += healAmount;
    if (this->health > this->maxHealth) this->health = this->maxHealth;
}

void Character::move(void) {
    // mouse
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {/* slice with blade */ }
    // keyboard
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { /*pan the camera up*/}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { xSpeed -= 0.5; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) { /*jump down through a platform*/}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { xSpeed += 0.5; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { ySpeed -= 5; }

    if (xSpeed > 0) { xSpeed -= 0.1; }
    else if (xSpeed < 0) { xSpeed += 0.1; }
    if (ySpeed < 0) { ySpeed -= 0.4; }
    else if (ySpeed > 0) { ySpeed -= 0.2; }

    /*if(!collidesSquare()){ ySpeed += 0.2;}
     * else if(collidesSquare()){ySpeed=0;}*/

}

void Character::update(const float &dt) {
    Actor::update(dt);
    move();
}

