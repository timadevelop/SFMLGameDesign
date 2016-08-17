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
#include <SFML/System/Time.hpp>
#include "../commands/Command.h"

class SceneNode : public sf::Transformable, public sf::Drawable,
                  private sf::NonCopyable // no copy constructor
{
public:
    typedef std::unique_ptr<SceneNode> sceneUptr;
    SceneNode();
    void update(sf::Time dt);
    void attachChild(sceneUptr child); // take ownership of scene node
    sceneUptr detachChild(const SceneNode& node); // if return value is ignored it will be destroyed

public:
    virtual unsigned int getCategory() const;
    void onCommand(const Command& command, sf::Time dt);
public:
    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;


private:
    void updateChildren(sf::Time dt);
    virtual void updateCurrent(sf::Time dt);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<sceneUptr> mChildren;
    SceneNode* mParent = nullptr;
};


#endif //GAME_SCENENODE_H
