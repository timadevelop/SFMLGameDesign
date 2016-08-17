//
// Created by vtimofeev on 08/08/16.
//

#include <algorithm>
#include <assert.h>
#include "SceneNode.h"
#include "../commands/Category.h"

SceneNode::SceneNode() : mChildren(), mParent(nullptr)
{}

void SceneNode::update(sf::Time dt){
    updateCurrent(dt);
    updateChildren(dt);
}
void SceneNode::updateChildren(sf::Time dt) {
    for(sceneUptr& child : mChildren)
    {
        child->update(dt);
    }
}

// Make it virtual and overload for entities
void SceneNode::updateCurrent(sf::Time dt) {}

// Drawing

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}
void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    // recursively drawing all children
    for( const sceneUptr& child : mChildren) // why sceneUptr&
    {
        child->draw(target, states);
    }
}

//

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for(const SceneNode* node = this; node != nullptr; node = node->mParent)
        transform = node->getTransform() * transform; // left.combine(r)

    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return  getWorldTransform() * sf::Vector2f(); // left.transformPoint(r)
}

// childs

void SceneNode::attachChild(sceneUptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child)); // "moving" ownership to STL container
}

SceneNode::sceneUptr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
                              [&] (sceneUptr& p) -> bool {return p.get() == &node;} );
    // http://en.cppreference.com/w/cpp/memory/unique_ptr/get

    assert(found != mChildren.end());

    sceneUptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

// Comands

unsigned int SceneNode::getCategory() const {
    return Category::Scene;
}

void SceneNode::onCommand(const Command &command, sf::Time dt) {
    if(command.category & getCategory()) // if current scene node is a receiver
        command.action(*this, dt);

    for(sceneUptr& child : mChildren)
        child->onCommand(command, dt);
}