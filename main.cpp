#include "App.hpp"

//

#include <memory>

//

#include "FrameSegmenter.hpp"

//

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char **argv) {
  const char *modelPath = "../models/yolo26s-seg.pt";
  const char *framePath = "../temp/.";
  OnnxEnvironment env{};

  auto inf = std::make_unique<OnnxModelInference>(env, modelPath);
  auto fsr = std::make_unique<FrameSource>(framePath);
  auto seg = std::make_unique<FrameSegmenter>(std::move(inf));

  App app(std::move(fsr), std::move(seg));
  return app.exec();
}
