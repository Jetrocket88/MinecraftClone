
#include "face.h"

face::face(int x, int y, int z, std::vector<Vertex>& vertexArray, unsigned int& count, faceType face)
{
	count++;
	for (int i = 0; i < 4; i++) {
		Vertex v;

		v.vecPositions = faceVertices[face][i];
		v.vecPositions.x += x * 2;
		v.vecPositions.y += y * 2;
		v.vecPositions.z += z * 2;
		v.texCoords = faceTexCoords[i % 4];

		v.ColorValues = glm::vec4(2.0f, 1.0f, 2.0f, 1.0f);
		vertexArray.push_back(v);
	}
}
