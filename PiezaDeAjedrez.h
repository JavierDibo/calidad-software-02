#ifndef AJEDREZPOO_PIEZADEAJEDREZ_H
#define AJEDREZPOO_PIEZADEAJEDREZ_H

#include <iostream>

/**
 * @file PiezaDeAjedrez.h
 * @brief Header file for the PiezaDeAjedrez class
 */

/**
 * @class PiezaDeAjedrez
 * @brief Class representing a chess piece
 * @details This class contains all the information about a chess piece, including its name, color, value, and position on the board
 */
class PiezaDeAjedrez {
public:
    /**
     * @brief Constructor for the PiezaDeAjedrez class
     * @param[in] nombreP The name of the chess piece
     * @param[in] colorP The color of the chess piece
     * @param[in] valorP The value of the chess piece
     * @param[in] filaP The row position of the chess piece on the board
     * @param[in] colP The column position of the chess piece on the board
     */
    PiezaDeAjedrez(std::string nombreP, char colorP, int valorP, int filaP, char colP);

    /**
     * @brief Copy constructor for the PiezaDeAjedrez class
     * @param orig The original PiezaDeAjedrez object to be copied
     */
    PiezaDeAjedrez(const PiezaDeAjedrez &orig);

    /**
     * @brief Destructor for the PiezaDeAjedrez class
     */
    virtual ~PiezaDeAjedrez();

    /**
     * @brief Sets the row position of the chess piece
     * @param[in] posicionFila The row position of the chess piece
     */
    void SetPosicionFila(int posicionFila);

    /**
     * @brief Gets the row position of the chess piece
     * @return The row position of the chess piece
     */
    int GetPosicionFila() const;

    /**
     * @brief Gets the color of the chess piece
     * @return The color of the chess piece
     */
    char GetColor() const;

    /**
     * @brief Gets the name of the chess piece
     * @return The name of the chess piece
     */
    std::string GetNombre() const;

    /**
     * @brief Moves the chess piece to a new position
     * @param[in] fila The row increment for the move
     * @param[in] col The column increment for the move
     */
    virtual void mover(int fila, int col);

private:
    std::string nombre = ""; ///< The name of the chess piece
    char color; ///< The color of the chess piece
    int valor = 0; ///< The value of the chess piece
    int posicionFila = 0; ///< The row position of the chess piece on the board
    char posicionColumna = '-'; ///< The column position of the chess piece on the board

};

#endif //AJEDREZPOO_PIEZADEAJEDREZ_H
