//
//  AIPlayer.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 5/1/21.
//

#ifndef AIPlayer_hpp
#define AIPlayer_hpp
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>
#include "TicTacToeGame.hpp"

class AIPlayer{
public:
    
    AIPlayer(int playerPiece, GameDataRef data);
    void placePiece( int gridArr[3][3], sf::Sprite gridPieces[3][3], int& gameState );
    
    
private:
    void checkSection(int x1, int y1, int x2, int y2, int x, int y,
                      int pieceToCheck, int gridArr[3][3], sf::Sprite gridPieces[3][3] );
    
    void checkIfPieceIsEmpty(int x, int y, int gridArr[3][3], sf::Sprite gridPieces[3][3]);
    
    int aiPiece;
    int playerPiece;
    std::vector<std::array<int, 6>> checkMatchVector;
    GameDataRef _data;
};

#endif /* AIPlayer_hpp */
