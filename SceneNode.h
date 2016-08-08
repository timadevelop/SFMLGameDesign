//
// Created by vtimofeev on 08/08/16.
//

#ifndef GAME_SCENENODE_H
#define GAME_SCENENODE_H


#include <memory>
#include <vector>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable,
                  private sf::NonCopyable // no copy constructor
{
public:
    typedef std::unique_ptr<SceneNode> sceneUptr;
    SceneNode();
    void atttachChild(sceneUptr child); // take ownership of scene node
    sceneUptr detachChild(const SceneNode& node); // if return value is ignored it will be destroyed

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<sceneUptr> mChildren;
    SceneNode* mParent = nullptr;
};


#endif //GAME_SCENENODE_H
