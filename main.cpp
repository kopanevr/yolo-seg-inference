#include "App.hpp"

//

#include <memory>

//

#include "ModelInference.hpp"

//

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char **argv) {
  auto inference = std::make_unique<OnnxModelInference>("../models/yolo26s-seg.pt");
  App app(std::move(inference));
  return app.exec();
}
