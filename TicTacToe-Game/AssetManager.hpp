//
//  AssetManager.hpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager{
public:
    
    AssetManager(){}
    ~AssetManager(){}
    
    void loadTexture(std::string name, std::string fileName);
    sf::Texture& getTexture(std::string name);
    
    void loadFont(std::string name, std::string fileName);
    sf::Font& getFont(std::string name);
    
private:
    
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
};

#endif /* AssetManager_hpp */
