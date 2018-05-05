#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <string>
#include <GL/glew.h>

/**
	A texture class can load 24-bit PNG images.
*/
namespace cw
{
	class Texture
	{
		public:
			bool loadFromFile(const std::string& filename);
			~Texture();

		private:
			void clear();
			GLuint textureID;
	};
}
#endif