#include "Game.hpp"
#include "Board.hpp"
#include <iostream>
#include <regex>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int lar = 30;
    int hau = 15;
    int nb_level = 3;
    int teupor = 10;
    int diam = 5;
    int streum = 6;
    int geurchar = 3;
    Board *test = new Board(hau, lar, teupor, diam, streum, geurchar);
    
    Game *a= new Game(hau, lar, nb_level, teupor, diam, streum, geurchar);

    //a.affiche();
    a->playStreumons();
    a->to_txt();
    a->play();
    std::string filename = "jeu.txt";
    Game b(filename);

    std::cout << "Validité (i,j) : " << a->isValid(3,5) << std::endl;
    std::cout << "Destination : " << a->isDest(3,5) << std::endl;
    std::cout << "Heuristique h : " << a->heuristicH(3,5) << std::endl;


    /* Test déplacement des streumons */

}
