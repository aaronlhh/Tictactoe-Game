//
//  PauseState.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 5/1/21.
//

#ifndef PauseState_hpp
#define PauseState_hpp

#include "States.hpp"
#include "TicTacToeGame.hpp"
#include "GameState.hpp"


class PauseState: public States{
public:
    PauseState(GameDataRef data);
    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);
    
private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _resumeButton;
    sf::Sprite _homeButton;
   
};

#endif /* PauseState_hpp */
