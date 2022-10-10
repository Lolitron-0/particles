#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include "CanvasLib/CanvasLib.hpp"

class ParticleSystem;

class Particle {
public:
    Particle(const canv::Color& color, float radius, canv::Vec2<int> bounds);

    auto draw(canv::Canvas& canvas) -> void;
    auto update(ParticleSystem* system, float force) -> void;

private:
    canv::Color mColor;
    canv::Vec2<float> mCoords;
    canv::Vec2<float> mVelocity;
    canv::Vec2<int> mBounds;
    float mRadius;
};

#endif // PARTICLE_HPP
