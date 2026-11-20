#include "App.hpp"

//

#include <memory>

//

#include "ImageSegmenter.hpp"

//

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char **argv) {
  const char *modelPath = "../models/yolo26s-seg.pt";
  OnnxEnvironment env{};

  auto inf = std::make_unique<OnnxModelInference>(env, modelPath);
  auto seg = std::make_unique<ImageSegmenter>(std::move(inf));

  App app(std::move(seg));
  return app.exec();
}
