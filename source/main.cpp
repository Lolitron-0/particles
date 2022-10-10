#include <iostream>
#include "CanvasLib/CanvasLib.hpp"
#include "cells/ParticleSystem.hpp"


using namespace std;

int main()
{
    srand(time(0));

    canv::Canvas canvas(1200, 800);
    std::shared_ptr<ParticleSystem> red(
                std::make_shared<ParticleSystem>(canv::Colors::red, 100));
    std::shared_ptr<ParticleSystem> green(
                std::make_shared<ParticleSystem>(canv::Colors::green, 100));
    std::shared_ptr<ParticleSystem> white(
                std::make_shared<ParticleSystem>(canv::Colors::white, 100));

    ParticleSystem::addRule(red, red, 2);
    ParticleSystem::addRule(red, green, 2);
    ParticleSystem::addRule(green, red, -2);

    canvas.setUpdateFunction([&](){
        red->updateAndDraw(canvas);
        green->updateAndDraw(canvas);
        //white->updateAndDraw(canvas);
    });
    canvas.start();
    return 0;
}
