#include "cells/ParticleSystem.hpp"
#include "cells/Particle.hpp"

ParticleSystem::ParticleSystem(const canv::Color &color, int amount)
    :mColor(color)
{
    mParticles = ParticleVector();
    for(int i = 0; i < amount; i++)
        mParticles.push_back(std::make_shared<Particle>(mColor, ParticleSystem::particleRadius, canv::Vec2<int>(1200,800)));
}

int ParticleSystem::getSize()
{
    return mParticles.size();
}

void ParticleSystem::setSize(int s)
{
    mParticles = ParticleVector();
    for(int i = 0; i < s; i++)
        mParticles.push_back(std::make_shared<Particle>(mColor, ParticleSystem::particleRadius, canv::Vec2<int>(1200,800)));
}

void ParticleSystem::updateAndDraw(canv::Canvas& canvas)
{
    for(ParticlePtr part : mParticles) {
        for(auto &pair : mInteractionPull) {
            part->update(pair.first.get(), pair.second);
        }
        part->draw(canvas);
    }
}

void ParticleSystem::addRule(SystemPtr system, float force)
{
    mInteractionPull.push_back(std::make_pair(system, force));
}

ParticleSystem::ParticlePtr& ParticleSystem::operator[](int i)
{
    return mParticles[i];
}

void ParticleSystem::addRule(SystemPtr a, SystemPtr b, float force)
{
    a->addRule(b, force);
    //b->addRule(a, force);
}
