//
// Created by vtimofeev on 08/08/16.
//

#include <algorithm>
#include <assert.h>
#include "SceneNode.h"

void SceneNode::atttachChild(sceneUptr child)
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

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target, states);
    drawChildren(target, states)
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{

}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const
{
    // recursively drawing all children
    for( const sceneUptr& child : mChildren) // why sceneUptr&
    {
        child->draw(target, states);
    }
}