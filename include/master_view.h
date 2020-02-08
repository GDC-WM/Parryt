#ifndef MASTER_VIEW_H
#define MASTER_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

#include "master_logic.h"
#include "actor.h"
#include "character.h"
#include "fred.h"
#include "menu_view.h"

#include "view.h"
#include "enemy_view.h"
#include "range_enemy_view.h"
#include "player_view.h"
#include "paused_view.h"
#include "tutorial_view.h"
#include "options_view.h"
#include "loser_view.h"
#include "winner_view.h"
#include "story_view.h"
#include "room.h"
#include "exit.h"


/* Manages all of the different views and game states */
class MasterView {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterLogic> logic;
        std::shared_ptr<PausedView> paused; 
        std::shared_ptr<PlayerView> player; 
        std::shared_ptr<MenuView> menu;
        std::shared_ptr<TutorialView> tutorial;
        std::shared_ptr<LoserView> loser;
        std::shared_ptr<WinnerView> winner;
        std::shared_ptr<StoryView> story;
		std::list<std::shared_ptr<EnemyView>> enemies;
        std::list<std::shared_ptr<RangeEnemyView>> rangeEnemies;

    public:
        MasterView(std::shared_ptr<sf::RenderWindow> window);

        void init(std::shared_ptr<MasterLogic> logic);

        void removeEnemy(std::shared_ptr<Enemy> enemy);

        void reset();

        void setMenu();

        void setPaused();

        void setTutorial();

        void setLoser();

        void setWinner();
    
        void setStory();
    
        void startStory();

        void setPlayer(std::shared_ptr<Fred> fred);

        /**
         * Create a view for the new enemy from logic and add the view to the enemyview list
         */
		void addEnemy(std::shared_ptr<Enemy> enemy);

        void switchToDay();
    
        void switchToNight();

        void update(float delta);
};

#endif
