#include "App.hpp"

//

#include <memory>

//

#include "ModelInference.hpp"
#include "FrameSource.hpp"
#include "FrameDepthEstimator.hpp"
#include "FrameRender.hpp"

//

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char **argv) {
  const char *modelPath = "../models/yolo26s-depth.onnx";
  const char *framePath = "../temp/image.jpg";
  const char *outputFramePath = "../temp/output_image.jpg";
  OnnxEnvironment env{};

  auto inf = std::make_unique<OnnxModelInference>(env, modelPath);
  auto fsr = std::make_unique<FrameSource>(framePath);
  auto des = std::make_unique<FrameDepthEstimator>(std::move(inf));
  auto frd = std::make_unique<FrameRender>(outputFramePath);

  App app(std::move(fsr), std::move(des), std::move(frd));
  return app.exec();
}
