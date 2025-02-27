#pragma once

#ifndef TEXTURE_H  
#define TEXTURE_H 

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../vendor/stb_image.h"
#include <glad/glad.h>

class Texture {
public:
	unsigned int texID;

	Texture(std::string path, std::string fileType);
	void bind(unsigned int slot) const;
	void unBind() const;
private:
	int width, height, nrChannels;
	unsigned char *data;
};


#endif
