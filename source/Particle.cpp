#include "cells/Particle.hpp"
#include "cells/ParticleSystem.hpp"
#include <cmath>

Particle::Particle(const canv::Color &color,
                   float radius,
                   canv::Vec2<int> bounds)
    :mRadius(radius), mColor(color), mBounds(bounds)
{
    mCoords = canv::Vec2<float>(mBounds.x*(rand()/float(RAND_MAX)), mBounds.y*(rand()/float(RAND_MAX)));
}

void Particle::draw(canv::Canvas& canvas)
{
    canvas.setFillColor(mColor);
    canvas.drawEllipse(mCoords, canv::Vec2<float>(mRadius));
}

void Particle::update(ParticleSystem* system, float force)
{
    auto d = .0f;
    auto dx = .0f;
    auto dy = .0f;
    auto f = .0f;
    auto fx = 0.f;
    auto fy = 0.f;
    auto fScale = 3;

    for(int i = 0; i < system->getSize(); i++) {
        auto& other = (*system)[i];

        d = mCoords.distTo(other->mCoords);
        if(d>2 && d<100) {
            dx = other->mCoords.x - mCoords.x;
            dy = other->mCoords.y - mCoords.y;
            f = force / (d*d) * fScale;

            fx += f*dx;
            fy += f*dy;
        }
    }
    mVelocity.x = (mVelocity.x + fx)*0.5;
    mVelocity.y = (mVelocity.y + fy)*0.5;

    auto margin = 50;

    if(mCoords.x + mVelocity.x < margin || mCoords.x + mVelocity.x > mBounds.x - margin) mVelocity.x *= -1;
    if(mCoords.y + mVelocity.y < margin || mCoords.y + mVelocity.y > mBounds.y - margin) mVelocity.y *= -1;

    mCoords += mVelocity;
}
