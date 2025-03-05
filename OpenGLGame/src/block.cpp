#include "block.h"




block::block(int x, int y, int z, std::vector<Vertex>& vertexArray, unsigned int& count)
{
	count++;
	for (int v = 0; v < 8; v++) { // Each cube has 8 vertices
		Vertex vertex;
		vertex.vecPositions = vertices[v]; // Adjust position for floor layout

		vertex.vecPositions.x += x * 2; 
		vertex.vecPositions.y += y * 2;
		vertex.vecPositions.z += z * 2;

		vertex.texCoords = cubeTexCoords[v];

		vertex.ColorValues = glm::vec4(2.0f, 1.0f, 2.0f, 1.0f);
		vertexArray.push_back(vertex);
	}
}
