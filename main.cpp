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
  OnnxEnvironment env{};
  const char *modelPath = "../models/yolo26s-seg.pt";
  auto inf = std::make_unique<OnnxModelInference>(env, modelPath);
  App app(std::move(inf));
  return app.exec();
}
