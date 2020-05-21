#ifndef DEF_ASSETMANAGER
#define DEF_ASSETMANAGER

#include <map>

#include <SFML/Graphics.hpp>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> TexturesMap;
	std::map<std::string, sf::Font> FontMap;

public:
	//constructors
	AssetManager() { }
	virtual ~AssetManager() { }

	//methodes
	void LoadTextures(std::string _name, std::string _filename);
	sf::Texture &GetTexture(std::string _name);
	
	void LoadFont(std::string _name, std::string _filename);
	sf::Font &GetFont(std::string _name);
};

#endif // ! DEF_ASSETMANAGER