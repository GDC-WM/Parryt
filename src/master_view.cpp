#include "master_view.h"
#include "master_logic.h"
#include <iostream>

MasterView::MasterView(std::shared_ptr<sf::RenderWindow> window) {
    this->window = window;
}

void MasterView::init(std::shared_ptr<MasterLogic> logic) {
    this->logic = logic;
}

void MasterView::setPlayer(std::shared_ptr<Fred> fred) {
    player = std::make_shared<PlayerView>(this->logic, fred, this->window);
}

void MasterView::addEnemy(std::shared_ptr<Enemy> enemy) {
    if (enemy->getSelectedItem() && enemy->getSelectedItem()->getType() == ActorType::RANGEWEAPON) {
        this->rangeEnemies.emplace_back(std::make_shared<RangeEnemyView>(this->logic, enemy));
    }
    else this->enemies.emplace_back(std::make_shared<EnemyView>(this->logic, enemy));
}

void MasterView::removeEnemy(std::shared_ptr<Enemy> enemy) {
    if (enemy->getSelectedItem() && enemy->getSelectedItem()->getType() == ActorType::RANGEWEAPON) {
        for (std::shared_ptr<RangeEnemyView> view : this->rangeEnemies) {
            if (view->getEnemy() == enemy) this->rangeEnemies.remove(view);
        }
    }
    else {
        for (std::shared_ptr<EnemyView> view : this->enemies) {
            //if (view->getEnemy() == enemy) this->enemies.remove(view); //commented out for seg fault problem
        }
    }
}

void MasterView::reset(void) {
    this->enemies.clear();
    this->rangeEnemies.clear();
}

void MasterView::setMenu(void) {
    menu = std::make_shared<MenuView>(this->logic, this->window);
}

void MasterView::setPaused(void) {
    paused = std::make_shared<PausedView>(this->logic, this->window);
}

void MasterView::setTutorial(void) {
    tutorial = std::make_shared<TutorialView>(this->logic, this->window);
}

void MasterView::setLoser(void) {
    loser = std::make_shared<LoserView>(this->logic, this->window);
}

void MasterView::setWinner(void) {
    winner = std::make_shared<WinnerView>(this->logic, this->window);
}

void MasterView::setStory(void) {
    story = std::make_shared<StoryView>(this->logic, this->window);
    startStory();
}

void MasterView::startStory(void) {
    story->updateText();
}

void MasterView::switchToDay(void) {
    player->switchToDay();
}

void MasterView::switchToNight(void) {
    player->switchToNight();
}

void MasterView::update(float delta) {
    if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == false)) {
        menu->update(delta);
    }
    else if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == true) && (this->logic->loser == false) && (this->logic->winner == false)) {
        tutorial->update(delta);
    }

    else if ((this->logic->paused == true) && (this->logic->playing == true) && (this->logic->options == false)) {
        paused->update(delta);
    }
    
    else if ((this->logic->paused == false) && (this->logic->playing == true) && (this->logic->story == true)) {
        story->update(delta);
    }

    else if ((this->logic->paused == false) && (this->logic->playing == true) && (this->logic->options == false)) {
        player->update(delta);
        for (std::shared_ptr<EnemyView> enemy : this->enemies) enemy->update(delta);
        for (std::shared_ptr<RangeEnemyView> rangeEnemy : this->rangeEnemies) rangeEnemy->update(delta);
    }

    else if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == true) && (this->logic->loser == true)) {
        loser->update(delta);
    }
    else if ((this->logic->paused == true) && (this->logic->playing == false) && (this->logic->options == true) && (this->logic->winner == true)) {
        winner->update(delta);
    }
}