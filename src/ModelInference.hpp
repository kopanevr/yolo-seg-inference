#pragma once

//

#include <memory>
#include <string>
#include <string_view>

//

#include "onnxruntime_cxx_api.h"

//

/// @brief
class IModelInference {
public:
  virtual ~IModelInference() = default;

private:
};

/// @brief
class OnnxModelInference final : public IModelInference {
public:
  explicit OnnxModelInference(std::string_view modelPath) {}

private:
};
