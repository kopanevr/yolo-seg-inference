#pragma once

//

#include <string>

//

#include "opencv4/opencv2/opencv.hpp"

//

class IFrameSource {
public:
  virtual ~IFrameSource() = default ;

  virtual bool getFrame(cv::Mat &frame) const = 0;
};

/// @brief
class FrameSource final : public IFrameSource {
public:
  FrameSource(const std::string &framePath) : framePath_(framePath) {}

  /// @brief
  /// @param frame
  /// @return
  bool getFrame(cv::Mat &frame) const override {
    frame = cv::imread(framePath_);
    return !frame.empty();
  }

private:
  std::string framePath_;
};
