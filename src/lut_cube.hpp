#ifndef LUT_CUBE_HPP_INCLUDED
#define LUT_CUBE_HPP_INCLUDED

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

namespace vkBasalt
{
    /*
       reads .cube files
       returns a vector of bytes
       one byte is one color value
       4 bytes stand for rgba
       the alpha value is always 255

       size will be set according to the size in the file, which can be in [2,256]
       the cube will have the dimentions size * size * size

       so the vector will have a length of size*size*size*4

       See: https://wwwimages2.adobe.com/content/dam/acom/en/products/speedgrade/cc/pdfs/cube-lut-specification-1.0.pdf
    */
    class LutCube
    {
    public:
        std::vector<unsigned char> colorCube;
        int                        size;

        LutCube(const std::string& file);
        LutCube();

    private:
        float minX = 0.0f;
        float minY = 0.0f;
        float minZ = 0.0f;

        float maxX = 1.0f;
        float maxY = 1.0f;
        float maxZ = 1.0f;

        int currentX = 0;
        int currentY = 0;
        int currentZ = 0;

        void writeColor(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b);

        void parseLine(std::string line);

        // splits a tripel of floats
        void splitTripel(std::string tripel, float& x, float& y, float& z);

        void clampTripel(float x, float y, float z, unsigned char& outX, unsigned char& outY, unsigned char& outZ);

        // returns the text without leading whitespace
        std::string skipWhiteSpace(std::string text);
    };

} // namespace vkBasalt
#endif // LUT_CUBE_HPP_INCLUDED
