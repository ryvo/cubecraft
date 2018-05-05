#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <nlohmann/json.hpp>
#include <string>
#include <set>

namespace cw
{
	using json = nlohmann::json;
	using string = std::string;
	using setOfStrings = std::set<string>;

	class Block {
		public:
			bool loadFromFile(const std::string& filename);

			struct WallTextures
			{
				string top;
				string front;
				string back;
				string left;
				string right;
				string bottom;
			};

			string getName();
			WallTextures getWallTextures();
			setOfStrings &getUniqueTextureNames();

		private:
			string name;
			WallTextures wallTextures;
			setOfStrings uniqueTextureNames;
	};
}

#endif
