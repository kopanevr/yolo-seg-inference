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
class IFrameSegmenter {
public:
  virtual ~IFrameSegmenter() = default;

  virtual std::vector<float> segment(const cv::Mat &frame) = 0;
};

/// @brief
class FrameSegmenter final : public IFrameSegmenter {
public:
  explicit FrameSegmenter(std::unique_ptr<IModelInference> model)
      : model_(std::move(model)) {}

  /// @brief
  /// @param frame
  /// @return
  std::vector<float> segment(const cv::Mat &frame) override {
    std::vector<float> tensor = preprocessImage(frame);
    std::vector<int64_t> shape = {1, 3, 640, 640};
    auto logits = model_->predict(tensor, shape);
    //
    return logits;
  }

private:
  /// @brief
  /// @param frame
  /// @return
  std::vector<float> preprocessImage(const cv::Mat &frame) {
    cv::Mat blob = cv::dnn::blobFromImage(
      frame,
      1.0,
      cv::Size(640, 640),
      cv::Scalar(),
      true,
      false
    );
    return {blob.datastart, blob.dataend};
  }

private:
  std::unique_ptr<IModelInference> model_;
};
