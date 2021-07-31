#include "Utils.hpp"


void Util::sleep(uint ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}