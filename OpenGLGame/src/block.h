#pragma once

#include "vertex.h"
#include <vector>

enum blockType {
    BLOCK_AIR,
    BLOCK_GRASS,
    BLOCK_DIRT
};

#ifndef BLOCK_H 
#define BLOCK_H 

class block {
public:
    blockType type = BLOCK_GRASS;
    block(int x, int y, int z, std::vector<Vertex>& vertexArray, unsigned int& count);

private:
    
    const std::vector<glm::vec3> vertices = {
        { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 0, 1, 0 },
        { 0, 0, 1 }, { 1, 0, 1 }, { 1, 1, 1 }, { 0, 1, 1 } 
    };

    const glm::vec2 faceTexCoords[8] = {
        {1, 1}, {1, 0}, {0, 0}, {0, 1},
        {1, 1}, {1, 0}, {0, 0}, {0, 1}
    };

    const std::vector<glm::vec2> cubeTexCoords = {
        {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f},
        {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f},
        {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f},
        {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}
    };


};

#endif
