#include <stdexcept>
#include "MovimientoInvalido.h"

/**
 * @file MovimientoInvalido.cpp
 * @brief Implementation file for the MovimientoInvalido class
 */

/**
 * @brief Constructor for the MovimientoInvalido class
 * @param[in] arg The error message to be passed to the runtime_error base class
 */
MovimientoInvalido::MovimientoInvalido(const std::string &arg) : runtime_error(arg) {

}
