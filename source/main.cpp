#include <iostream>
#include "Renderer.hpp"

int main(int argc, char** argv)
{
  Renderer::Init();
  Renderer::Free();
  return 0;
}