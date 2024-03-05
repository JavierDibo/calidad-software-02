#include "PiezaDeAjedrez.h"
/**
 * @file PiezaDeAjedrez.cpp
 * @brief Implementation file for the PiezaDeAjedrez class
 */

/**
 * @brief Constructor for the PiezaDeAjedrez class
 * @param[in] nombreP The name of the chess piece
 * @param[in] colorP The color of the chess piece
 * @param[in] valorP The value of the chess piece
 * @param[in] filaP The row position of the chess piece on the board
 * @param[in] colP The column position of the chess piece on the board
 */
PiezaDeAjedrez::PiezaDeAjedrez(std::string nombreP, char colorP, int valorP, int filaP, char colP) :
        nombre(nombreP), color(colorP), valor(valorP), posicionFila(filaP), posicionColumna(colP) {
}

/**
 * @brief Copy constructor for the PiezaDeAjedrez class
 * @param[in] orig The original PiezaDeAjedrez object to be copied
 */
PiezaDeAjedrez::PiezaDeAjedrez(const PiezaDeAjedrez &orig) {
}

/**
 * @brief Destructor for the PiezaDeAjedrez class
 */
PiezaDeAjedrez::~PiezaDeAjedrez() {
}

/**
 * @brief Sets the row position of the chess piece
 * @param[in] posicionFila The row position of the chess piece
 */
void PiezaDeAjedrez::SetPosicionFila(int posicionFila) {
    this->posicionFila = posicionFila;
}

/**
 * @brief Gets the row position of the chess piece
 * @return The row position of the chess piece
 */
int PiezaDeAjedrez::GetPosicionFila() const {
    return posicionFila;
}

/**
 * @brief Gets the color of the chess piece
 * @return The color of the chess piece
 */
char PiezaDeAjedrez::GetColor() const {
    return color;
}

/**
 * @brief Gets the name of the chess piece
 * @return The name of the chess piece
 */
std::string PiezaDeAjedrez::GetNombre() const {
    return nombre;
}

/**
 * @brief Moves the chess piece to a new position
 * @param[in] fila The row increment for the move
 * @param[in] col The column increment for the move
 * @throws std::out_of_range if the new position is outside the board
 */
void PiezaDeAjedrez::mover(int fila, int col) {
    if ((posicionFila + fila) > 8 || (posicionFila + fila) < 1)
        throw std::out_of_range("mover. Error, la pieza se sale del tablero.");
    this->posicionFila += fila;
}
