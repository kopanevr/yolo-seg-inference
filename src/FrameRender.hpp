#pragma once

//

#include <string>
#include <vector>

//

#include "opencv4/opencv2/opencv.hpp"

//

class IFrameRender {
public:
  virtual ~IFrameRender() = default;

  virtual void drawDepth(const cv::Mat &frame, std::vector<float> &depth) = 0;
};

/// @brief
class FrameRender final : public IFrameRender {
public:
  explicit FrameRender(const std::string &framePath) : framePath_(framePath) {}

  void drawDepth(const cv::Mat &frame, std::vector<float> &depth) override {
    if (frame.empty() || depth.empty()) {
      return;
    }

    //
  }

private:
  std::string framePath_;
};
