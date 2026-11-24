#pragma once

//

#include <memory>
#include <vector>

//

#include "ModelInference.hpp"

//

#include "opencv4/opencv2/opencv.hpp"

//

/// @brief
class IFrameDepthEstimator {
public:
  virtual ~IFrameDepthEstimator() = default;

  virtual std::vector<float> estimate(const cv::Mat &frame) = 0;
};

/// @brief
class FrameDepthEstimator final : public IFrameDepthEstimator {
public:
  explicit FrameDepthEstimator(std::unique_ptr<IModelInference> model)
      : model_(std::move(model)) {}

  /// @brief
  /// @param frame
  /// @return
  std::vector<float> estimate(const cv::Mat &frame) override {
    std::vector<float> tensor = preprocessFrame(frame);
    std::vector<int64_t> shape = {1, 3, 768, 768};
    auto logits = model_->predict(tensor, shape);
    //
    return logits;
  }

private:
  /// @brief
  /// @param frame
  /// @return
  std::vector<float> preprocessFrame(const cv::Mat &frame) {
    if (frame.empty()) {
      return {};
    }
    cv::Mat blob = cv::dnn::blobFromImage(
      frame,
      1.0 / 255.0,
      cv::Size(768, 768),
      cv::Scalar(),
      true,
      false
    );
    const float *begin = blob.ptr<float>();
    return std::vector<float>(begin, begin + blob.total());
  }

private:
  std::unique_ptr<IModelInference> model_;
};
