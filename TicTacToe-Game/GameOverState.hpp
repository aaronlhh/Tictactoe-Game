//
//  GameOverState.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 5/1/21.
//

#ifndef GameOverState_hpp
#define GameOverState_hpp

#include "States.hpp"
#include "TicTacToeGame.hpp"
#include "GameState.hpp"

class GameOverState: public States{
public:
    
    GameOverState(GameDataRef data);
    
    void init();
    
    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    GameDataRef _data;
    sf::Sprite _retryButton;
    sf::Sprite _homeButton; 
    
};

#endif /* GameOverState_hpp */
