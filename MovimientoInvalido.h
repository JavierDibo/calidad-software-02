#ifndef AJEDREZPOO_MOVIMIENTOINVALIDO_H
#define AJEDREZPOO_MOVIMIENTOINVALIDO_H

#include <stdexcept>
#include <utility>

/**
 * @file MovimientoInvalido.h
 * @brief Header file for the MovimientoInvalido class
 */

/**
 * @class MovimientoInvalido
 * @brief Exception class for invalid movements in the chess game
 * @details This class is derived from the standard runtime_error class and is used to indicate invalid movements in the chess game
 */
class MovimientoInvalido : public std::runtime_error {
public:
    /**
     * @brief Constructor for the MovimientoInvalido class
     * @param[in] arg The error message to be passed to the runtime_error base class
     */
    explicit MovimientoInvalido(const std::string &arg);
};

#endif //AJEDREZPOO_MOVIMIENTOINVALIDO_H
