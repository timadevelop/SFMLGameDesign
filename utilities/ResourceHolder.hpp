#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include "SFML/Graphics.hpp"
#include <string>
#include <map>
#include <assert.h>
#include <memory>


namespace Textures
{
	enum class ID
	{
		Eagle,
		Raptor,
		Desert
	};
}


template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename);
	
	// for shaders & areas from texture
	// look for sfml::shader::loadFromFile() & sfml::texture::loadFromFile() docs
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);

	void insert(Identifier id, std::unique_ptr<Resource> resource);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;

private:
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"

#endif
