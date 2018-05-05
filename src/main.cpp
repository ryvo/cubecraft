#include <iostream>
#include <string>

#include "block/block.hpp"

using Block = cw::Block;

void main() {

	Block block;
	block.loadFromFile("data/blocks/definitions/grass.json");
	std::cout << block.getName() << std::endl;

	for (cw::setOfStrings::iterator it = block.getUniqueTextureNames().begin(); it != block.getUniqueTextureNames().end(); it++)
	{
		std::cout << (*it) << std::endl;
	}

	std::getchar();
}