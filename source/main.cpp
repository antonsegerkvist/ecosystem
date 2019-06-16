#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Renderer.hpp"
#include "Simulation.hpp"

int main(int argc, char** argv)
{
  srand(time(0));
  
  if(Renderer::Init())
  {
    Simulation simulation(500, 500);
    simulation.run();
    Renderer::Free();
  }
  return 0;
}