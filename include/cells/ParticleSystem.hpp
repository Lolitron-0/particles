#ifndef PARTICLESYSTEM_HPP
#define PARTICLESYSTEM_HPP
#include "CanvasLib/CanvasLib.hpp"
#include <vector>
#include <memory>

class Particle;

class ParticleSystem {
public:
    typedef std::shared_ptr<Particle> ParticlePtr;
    typedef std::vector<ParticlePtr> ParticleVector;
    typedef std::shared_ptr<ParticleSystem> SystemPtr;
    typedef std::vector<std::pair<SystemPtr,float>> ParticleSystemPull;

    ParticleSystem(const canv::Color& color, int amount);

    int getSize();
    void setSize(int s);

    //update and drawing are done together to save some time
    auto updateAndDraw(canv::Canvas& canvas) -> void;

    ParticlePtr& operator[](int i);

    static void addRule(SystemPtr a, SystemPtr b, float force);

private:
    auto addRule(SystemPtr system, float force) -> void;

    canv::Color mColor;
    ParticleVector mParticles;
    ParticleSystemPull mInteractionPull;

    constexpr static const float particleRadius = 7;
};


#endif // PARTICLESYSTEM_HPP
