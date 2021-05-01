//
//  TicTacToeGame.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef TicTacToeGame_hpp
#define TicTacToeGame_hpp

#include <memory>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

struct GameData{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;



class TicTacToeGame{
public:
    
    TicTacToeGame(int width, int height, std::string name);
    
    
private:
    const float dt = 1.0f / 60.0f;
    sf::Clock _clock;
    GameDataRef _data = std::make_shared<GameData>();
    void run();
    
};


#endif /* TicTacToeGame_hpp */
