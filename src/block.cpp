#include <block.h>
#include <iostream>

Block::Block() {
    std::cout << "New Block\n";
}

Block::~Block() {
    std::cout << "Block Destroyed\n";
}