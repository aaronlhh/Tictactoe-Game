//
//  main.cpp
//  TicTacToe-Game
//
//  Created by Aaron Lin on 4/29/21.
//

#include <iostream>
#include "TicTacToeGame.hpp"
#include "DEFINITIONS.hpp"

//#include <SFML/Graphics.hpp>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(1200, 1000), "dropdown");
//    while(window.isOpen()){
//        sf::Event event;
//        while(window.pollEvent(event)){
//            if(event.type == sf::Event::Closed){
//                window.close();
//            }
//        }
//        window.clear();
//        window.display();
//    }
//}


int main(){
    TicTacToeGame(SCREEN_WIDTH, SCREEN_HEIGHT, "TicTacToe-Game");
    return EXIT_SUCCESS;
}
