#pragma once

//

#include <vector>

//

#include "opencv4/opencv2/opencv.hpp"

//

class IFrameRender {
public:
  virtual ~IFrameRender() = default;

  virtual void render(const cv::Mat &frame, std::vector<float> &mask) = 0;
};

/// @brief
class FrameRender final : public IFrameRender {
  void render(const cv::Mat &frame, std::vector<float> &mask) override {}
};
