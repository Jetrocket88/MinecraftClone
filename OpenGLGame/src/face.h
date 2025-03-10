#pragma once

#include "vertex.h"
#include <vector>

enum faceType {
    FRONT = 1,
    BACK = 2,
    LEFT = 3,
    RIGHT = 4,
    BOTTOM = 5,
    TOP = 6
};

#ifndef FACE_H
#define FACE_H

class face{
public:
    face(int x, int y, int z, std::vector<Vertex>& vertexArray, unsigned int& count, faceType face);

private:

    const std::vector<glm::vec3> faceVertices[7] = {
       { { } },
       { { 0, 0, 0 }, { 1, 0, 0 }, { 1, 1, 0 }, { 0, 1, 0 } }, // FRONT
       { { 0, 0, -1 }, { 1, 0, -1 }, { 1, 1, -1 }, { 0, 1, -1 } }, // BACK
       { { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, -1 }, { 0, 1, 0 } }, // LEFT
       { { 1, 0, 0 }, { 1, 0, -1 }, { 1, 1, -1 }, { 1, 1, 0 } }, // RIGHT
       { { 0, 0, 0 }, { 1, 0, 0 }, { 1, 0, -1 }, { 0, 0, -1 } }, // BOTTOM
       { { 0, 1, 0 }, { 1, 1, 0 }, { 1, 1, -1 }, { 0, 1, -1 } }  // TOP
    };

    const glm::vec2 faceTexCoords[4] = {
        {1, 0}, {0, 0}, {0, 1}, {1, 1}
    };
};
#endif // !FACE_H
