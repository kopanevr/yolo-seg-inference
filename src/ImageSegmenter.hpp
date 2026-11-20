#pragma once

//

#include <memory>

//

#include "ModelInference.hpp"

//

/// @brief
class IImageSegmenter {
public:
  virtual ~IImageSegmenter() = default;

  virtual int segment() = 0;
};

/// @brief
class ImageSegmenter final : public IImageSegmenter {
public:
  explicit ImageSegmenter(std::unique_ptr<IModelInference> model)
      : model_(std::move(model)) {}

  int segment() override { return 0; }

private:
  std::unique_ptr<IModelInference> model_;
};
