#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <string>
#include "BMPHeaders.h"

namespace BasicEngine
{
    namespace Rendering
    {
        class TextureLoader
        {
            public:
                TextureLoader();
                ~TextureLoader();

                unsigned int LoadTexture(const std::string& filename, unsigned int width, unsigned int height);

            private:
                void LoadBMPFile(const std::string& filename, unsigned int& width, unsigned int& height, unsigned char*& data);
        };
    }
}

#endif
