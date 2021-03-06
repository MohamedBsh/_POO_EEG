#include "Streumons.hpp"

Streumons::~Streumons()
{
}

/**
 * @brief  constructeur d'un streumon de type aléatoire
 */
Streumons::Streumons()
{
    this->symbol = 's';
    this->type = rand() % 3;
    this->typeevol = rand() % 3;
}

/**
 * @brief  constructeur d'un streumon de type donné
 * @param  _type: type de déplacement du streumon
 */
Streumons::Streumons(int _type):type(_type)
{
    this->symbol = 's';
    this->typeevol = rand() % 3;
}

char Streumons::getSymbol() const
{
    return this->symbol;
}

int Streumons::getType() const
{
    return this->type;
}

int Streumons::getTypeEvol() const
{
    return this->typeevol;
}
