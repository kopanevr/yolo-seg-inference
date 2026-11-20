#pragma once

//

#include "opencv4/opencv2/opencv.hpp"

//

class IFrameRender {
public:
  virtual ~IFrameRender() = default;

  virtual void render(const cv::Mat &frame) = 0;
};

/// @brief
class FrameRender final : public IFrameRender {
  void render(const cv::Mat &frame) override {}
};
