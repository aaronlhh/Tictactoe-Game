//
//  AIPlayer.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 5/1/21.
//

#include "AIPlayer.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>
using namespace std;


AIPlayer::AIPlayer(int playerPiece, GameDataRef data)
: _data(data){
    this->playerPiece = playerPiece;
    if(playerPiece == O_PIECE){
        aiPiece = X_PIECE;
    }else
        aiPiece = O_PIECE;
    
    // brute forcing all possible steps into checkMatchVector
    checkMatchVector.push_back({ 0, 2, 1, 2, 2, 2 });
    checkMatchVector.push_back({ 0, 2, 0, 1, 0, 0 });
    checkMatchVector.push_back({ 0, 2, 1, 1, 2, 0 });
    checkMatchVector.push_back({ 2, 2, 1, 2, 0, 2 });
    checkMatchVector.push_back({ 2, 2, 2, 1, 2, 0 });
    checkMatchVector.push_back({ 2, 2, 1, 1, 0, 0 });
    checkMatchVector.push_back({ 0, 0, 0, 1, 0, 2 });
    checkMatchVector.push_back({ 0, 0, 1, 0, 2, 0 });
    checkMatchVector.push_back({ 0, 0, 1, 1, 2, 2 });
    checkMatchVector.push_back({ 2, 0, 2, 1, 2, 2 });
    checkMatchVector.push_back({ 2, 0, 1, 0, 0, 0 });
    checkMatchVector.push_back({ 2, 0, 1, 1, 0, 2 });
    checkMatchVector.push_back({ 0, 1, 1, 1, 2, 1 });
    checkMatchVector.push_back({ 1, 2, 1, 1, 1, 0 });
    checkMatchVector.push_back({ 2, 1, 1, 1, 0, 1 });
    checkMatchVector.push_back({ 1, 0, 1, 1, 1, 2 });
    checkMatchVector.push_back({ 0, 1, 2, 1, 1, 1 });
    checkMatchVector.push_back({ 1, 2, 1, 0, 1, 1 });
    checkMatchVector.push_back({ 0, 2, 2, 0, 1, 1 });
    checkMatchVector.push_back({ 2, 2, 0, 0, 1, 1 });
    checkMatchVector.push_back({ 0, 2, 2, 2, 1, 2 });
    checkMatchVector.push_back({ 0, 0, 2, 0, 1, 0 });
    checkMatchVector.push_back({ 0, 2, 0, 0, 0, 1 });
    checkMatchVector.push_back({ 2, 2, 2, 0, 2, 1 });
    
}

void AIPlayer::placePiece( int gridArr[3][3], sf::Sprite gridPieces[3][3], int& gameState ){
    try{
        for(int i = 0 ; i < checkMatchVector.size(); ++i){
            checkSection(checkMatchVector[i][0], checkMatchVector[i][1],
                         checkMatchVector[i][2], checkMatchVector[i][3],
                         checkMatchVector[i][4], checkMatchVector[i][5],
                         AI_PIECE, gridArr, gridPieces);
        }
        for(int i = 0 ; i < checkMatchVector.size(); ++i){
            checkSection(checkMatchVector[i][0], checkMatchVector[i][1],
                         checkMatchVector[i][2], checkMatchVector[i][3],
                         checkMatchVector[i][4], checkMatchVector[i][5],
                         PLAYER_PIECE, gridArr, gridPieces);
        }
        // center is empty
        checkIfPieceIsEmpty(1, 1, gridArr, gridPieces);
        
        // corners are empty
        checkIfPieceIsEmpty(0, 0, gridArr, gridPieces);
        checkIfPieceIsEmpty(0, 2, gridArr, gridPieces);
        checkIfPieceIsEmpty(2, 0, gridArr, gridPieces);
        checkIfPieceIsEmpty(2, 2, gridArr, gridPieces);
        
        checkIfPieceIsEmpty(0, 1, gridArr, gridPieces);
        checkIfPieceIsEmpty(1, 0, gridArr, gridPieces);
        checkIfPieceIsEmpty(1, 2, gridArr, gridPieces);
        checkIfPieceIsEmpty(2, 1, gridArr, gridPieces);
        
    }catch(int error){
        
    }
    
    gameState = STATE_PLAYING;
}


void AIPlayer::checkSection(int x1, int y1, int x2, int y2, int x, int y,
                            int pieceToCheck, int gridArr[3][3], sf::Sprite gridPieces[3][3] ){
    
    if(gridArr[x1][y1] == pieceToCheck &&
       gridArr[x2][y2] == pieceToCheck){
        if(gridArr[x][y] == EMPTY_PIECE ){
            gridArr[x][y] = AI_PIECE;
            gridPieces[x][y].setTexture(this->_data->assets.getTexture("O Piece"));
            gridPieces[x][y].setColor(sf::Color(255,255,255,255));
            throw -1;
        }
    }
}


void AIPlayer::checkIfPieceIsEmpty(int x, int y, int gridArr[3][3], sf::Sprite gridPieces[3][3]){
    if(gridArr[x][y] == EMPTY_PIECE){
        gridArr[x][y] = AI_PIECE;
        gridPieces[x][y].setTexture(this->_data->assets.getTexture("O Piece"));
        gridPieces[x][y].setColor(sf::Color(255,255,255,255));
        throw -2;
    }
}
