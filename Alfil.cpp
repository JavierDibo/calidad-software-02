#include <string>
#include <exception>
#include "Alfil.h"
#include "PiezaDeAjedrez.h"
#include "MovimientoInvalido.h"

/**
 * @file Alfil.cpp
 * @brief Implementation file for the Alfil class.
 */


Alfil::Alfil(std::string nombreP, char colorP, int valorP, int filaP, char colP, char colorCasilla) :
        PiezaDeAjedrez(nombreP, colorP, valorP, filaP, colP), colorCasilla(colorCasilla) {

}

/**
 * @brief Copy constructor for the Alfil class
 * @param orig The original Alfil object to be copied
 */
Alfil::Alfil(const Alfil &orig) : PiezaDeAjedrez(orig), colorCasilla(orig.colorCasilla) {

}

/**
 * @brief Destructor for the Alfil class
 */
Alfil::~Alfil() {

}

/**
 * @brief Sets the color of the square where the bishop chess piece is placed
 * @param colorCasilla The color of the square
 */
void Alfil::setColorCasilla(char colorCasilla) {
    this->colorCasilla = colorCasilla;
}

/**
 * @brief Gets the color of the square where the bishop chess piece is placed
 * @return The color of the square
 */
char Alfil::getColorCasilla() const {
    return colorCasilla;
}

/**
 * @brief Moves the bishop chess piece to a new position
 * @param fila The row increment for the move
 * @param col The column increment for the move
 * @throws MovimientoInvalido if the move is invalid
 */
void Alfil::mover(int fila, int col) {
    throw MovimientoInvalido("mover. Error, movimiento invalido. ");
}
