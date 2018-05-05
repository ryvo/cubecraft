#include "block.hpp"

#include <fstream>
#include <string>

namespace cw
{
	bool Block::loadFromFile(const std::string& filename)
	{
		std::ifstream ifs(filename);
		json j = json::parse(ifs);
		json jt = j["textures"];

		name = j["name"].get<string>();
		wallTextures.top = jt["top"].get<string>();
		wallTextures.front = jt["front"].get<string>();
		wallTextures.back = jt["back"].get<string>();
		wallTextures.left = jt["left"].get<string>();
		wallTextures.right = jt["right"].get<string>();
		wallTextures.bottom = jt["bottom"].get<string>();

		// Create of set of unique texture names
		for (json::iterator it = jt.begin(); it != jt.end(); ++it) {
			string value = it.value().get<string>();
			if (uniqueTextureNames.find(value) == uniqueTextureNames.end())
			{
				uniqueTextureNames.insert(value);
			}
		}

		return true;
	}

	string Block::getName() 
	{
		return name;
	}

	Block::WallTextures Block::getWallTextures()
	{
		return wallTextures;
	}
	
	setOfStrings &Block::getUniqueTextureNames()
	{
		return uniqueTextureNames;
	}

}