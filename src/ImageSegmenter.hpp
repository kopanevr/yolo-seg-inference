#pragma once

//

#include <memory>
#include <vector>

//

#include "ModelInference.hpp"

//

/// @brief
class IImageSegmenter {
public:
  virtual ~IImageSegmenter() = default;

  virtual int segment(std::vector<float> &image) = 0;
};

/// @brief
class ImageSegmenter final : public IImageSegmenter {
public:
  explicit ImageSegmenter(std::unique_ptr<IModelInference> model)
      : model_(std::move(model)) {}

  int segment(std::vector<float> &image) override {
    std::vector<int64_t> shape = {1, 3, 640, 640};
    auto logits = model_->predict(image, shape);
    return 0;
  }

private:
  std::unique_ptr<IModelInference> model_;
};
