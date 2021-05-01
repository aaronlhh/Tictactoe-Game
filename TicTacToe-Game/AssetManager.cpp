//
//  AssetManager.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#include "AssetManager.hpp"


void AssetManager::loadTexture(std::string name, std::string fileName){
    sf::Texture tex;
    if(tex.loadFromFile(fileName)){
        this->_textures[name] = tex;
    }
}

sf::Texture& AssetManager::getTexture(std::string name){
    return _textures.at(name);   // map
}

void AssetManager::loadFont(std::string name, std::string fileName){
    sf::Font font;
    if(font.loadFromFile(fileName)){
        this->_fonts[name] = font;
    }
}

sf::Font& AssetManager::getFont(std::string name){
    return _fonts.at(name);
}


