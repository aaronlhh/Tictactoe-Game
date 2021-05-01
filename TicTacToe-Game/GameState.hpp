//
//  GameState.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/30/21.
//

#ifndef GameState_hpp
#define GameState_hpp

#include "TicTacToeGame.hpp"
#include "States.hpp"
#include <SFML/Graphics.hpp>
#include "AIPlayer.hpp"

class GameState: public States{
public:
    GameState(GameDataRef data);
    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);
    
private:
    void initGridPiece();  // initialize the grid
    
    void checkAndPlacePiece();
    
    void checkPlayerHasWon(int turn);
    void check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);
    
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _pauseButton;
    
    // adding grid variables
    sf::Sprite _gridSprite;
    sf::Sprite _gridPieces[3][3];
    int gridArr[3][3];
    
    int turn;
    int gameState; // contains constants in DEFINITION such as STATE_DRAW
    
    AIPlayer* AI;
    
    sf::Clock clock;  // keep track time after win/lose/draw
};

#endif /* GameState_hpp */
