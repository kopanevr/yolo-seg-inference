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

  virtual void drawDepth(const std::vector<float> &depth) = 0;
};

/// @brief
class FrameRender final : public IFrameRender {
public:
  explicit FrameRender(const std::string &framePath) : framePath_(framePath) {}

  void drawDepth(const std::vector<float> &depth) override {
    if (depth.empty()) {
      return;
    }
    cv::imwrite(framePath_, colorizeDepth(depth));
  }

private:
  /// @brief
  /// @param frame
  /// @param depth
  cv::Mat colorizeDepth(const std::vector<float> &depth) {
    cv::Mat depthMap(
      768,
      768,
      CV_32FC1,
      const_cast<void *>(static_cast<const void *>(depth.data()))
    );

    cv::Mat depthNorm{};
    cv::normalize(
      depthMap,
      depthNorm,
      0,
      255,
      cv::NORM_MINMAX,
      CV_8UC1
    );

    cv::Mat depthColor{};
    cv::applyColorMap(depthNorm, depthColor, cv::COLORMAP_INFERNO);

    return depthColor;
  }

private:
  std::string framePath_;
};
