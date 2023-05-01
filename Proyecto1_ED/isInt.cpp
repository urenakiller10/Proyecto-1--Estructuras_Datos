#include "auxiliaries.h"
#include <stdexcept>

// Definición de la función isInt
bool isInt(std::string cadena) {
    try {
        int n = std::stoi(cadena);
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }
    return true;
}
