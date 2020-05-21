#include "AssetManager.h"


//manage textures
void AssetManager::LoadTextures(std::string _name, std::string _filename)
{
	sf::Texture _texture;

	if (_texture.loadFromFile(_filename))
		this->TexturesMap[_name] = _texture;
}

sf::Texture & AssetManager::GetTexture(std::string _name)
{
	return this->TexturesMap.at(_name);
}


//manage fonts
void AssetManager::LoadFont(std::string _name, std::string _filename)
{
	sf::Font _font;

	if (_font.loadFromFile(_filename))
		this->FontMap[_name] = _font;
}

sf::Font & AssetManager::GetFont(std::string _name)
{
	return this->FontMap.at(_name);
}
