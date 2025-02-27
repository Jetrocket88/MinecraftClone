#include "texture.h"

Texture::Texture(std::string path, std::string fileType)
{
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);  

	stbi_set_flip_vertically_on_load(true);
	data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
	if (data) {
		if (fileType == "png") { glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); }
		else if (fileType == "jpg") { glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); }
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
		std::cout << "Error loading texture" << std::endl;
	}
	stbi_image_free(data);
}

void Texture::bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, texID);
}

void Texture::unBind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
