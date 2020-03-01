#include "lut_cube.hpp"

#include "logger.hpp"

namespace vkBasalt
{
    LutCube::LutCube()
    {
    }
    LutCube::LutCube(const std::string& file)
    {
        std::ifstream cubeStream(file);
        if (!cubeStream.good())
        {
            Logger::err("lut cube file does not exist");
        }

        std::string line;

        while (std::getline(cubeStream, line))
        {
            parseLine(line);
        }
    }
    void LutCube::parseLine(std::string line)
    {
        if (line.length() == 0)
        {
            return;
        }
        if (line[0] == '#')
        {
            return;
        }
        if (line.find("LUT_3D_SIZE") != std::string::npos)
        {
            line = line.substr(line.find("LUT_3D_SIZE") + 11);
            line = skipWhiteSpace(line);
            size = std::stoi(line);

            colorCube = std::vector<unsigned char>(size * size * size * 4, 255);
            return;
        }
        if (line.find("DOMAIN_MIN") != std::string::npos)
        {
            line = line.substr(line.find("DOMAIN_MIN") + 10);
            splitTripel(line, minX, minY, minZ);
            return;
        }
        if (line.find("DOMAIN_MAX") != std::string::npos)
        {
            line = line.substr(line.find("DOMAIN_MAX") + 10);
            splitTripel(line, maxX, maxY, maxZ);
            return;
        }
        if (line.find_first_of("0123456789") == 0)
        {
            float         x, y, z;
            unsigned char outX, outY, outZ;
            splitTripel(line, x, y, z);
            clampTripel(x, y, z, outX, outY, outZ);
            writeColor(currentX, currentY, currentZ, outX, outY, outZ);
            if (currentX != size - 1)
            {
                currentX++;
            }
            else if (currentY != size - 1)
            {
                currentY++;
                currentX = 0;
            }
            else if (currentZ != size - 1)
            {
                currentZ++;
                currentX = 0;
                currentY = 0;
            }
            return;
        }
    }

    std::string LutCube::skipWhiteSpace(std::string text)
    {
        while (text.size() > 0 && (text[0] == ' ' || text[0] == '\t'))
        {
            text = text.substr(1);
        }
        return text;
    }

    void LutCube::splitTripel(std::string tripel, float& x, float& y, float& z)
    {
        tripel       = skipWhiteSpace(tripel);
        size_t after = tripel.find_first_of(" \n");
        x            = std::stof(tripel.substr(0, after));
        tripel       = tripel.substr(after);

        tripel = skipWhiteSpace(tripel);
        after  = tripel.find_first_of(" \n");
        y      = std::stof(tripel.substr(0, after));
        tripel = tripel.substr(after);

        tripel = skipWhiteSpace(tripel);
        z      = std::stof(tripel);
    }

    void LutCube::clampTripel(float x, float y, float z, unsigned char& outX, unsigned char& outY, unsigned char& outZ)
    {
        outX = (unsigned char) 255 * (x / (maxX - minX));
        outY = (unsigned char) 255 * (y / (maxY - minY));
        outZ = (unsigned char) 255 * (z / (maxZ - minZ));
    }

    void LutCube::writeColor(int x, int y, int z, unsigned char r, unsigned char g, unsigned char b)
    {
        static const int colorSize = 4; // 4 bytes per point in the cube, rgba

        int locationR = (((z * size) + y) * size + x) * colorSize;

        colorCube[locationR + 0] = r;
        colorCube[locationR + 1] = g;
        colorCube[locationR + 2] = b;
    }
} // namespace vkBasalt
