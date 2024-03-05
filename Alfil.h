/**
 * @file Alfil.h
 * @brief This file contains the declaration of the Alfil class.
 */

#ifndef AJEDREZPOO_ALFIL_H
#define AJEDREZPOO_ALFIL_H

#include <iostream>
#include "PiezaDeAjedrez.h"

/**
 * @class Alfil
 * @brief This class represents a Bishop piece in a chess game.
 * @details It inherits from the PiezaDeAjedrez class.
 */
class Alfil : public PiezaDeAjedrez {
public:

	Alfil(std::string nombreP, char colorP, int valorP, int filaP, char colP, char colorCasilla);

    /**
     * @brief Copy constructor for the Alfil class.
     * @param orig The original Alfil object to be copied.
     * This constructor creates a copy of an existing Alfil object.
     */
    Alfil(const Alfil &orig);

    /**
     * @brief Destructor for the Alfil class.
     */
    virtual ~Alfil();

    /**
     * @brief Sets the color of the square where the piece is located.
     * @param colorCasilla The color of the square.
     */
    void setColorCasilla(char colorCasilla);

    /**
     * @brief Gets the color of the square where the piece is located.
     * @return The color of the square.
     */
    char getColorCasilla() const;

    /**
     * @brief Moves the piece to a new location.
     * @param fila The row to move the piece to.
     * @param col The column to move the piece to.
     */
    virtual void mover(int fila, int col);

private:
    char colorCasilla; // The color of the square where the piece is located.
};

#endif //AJEDREZPOO_ALFIL_H
