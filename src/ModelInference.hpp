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

  virtual std::vector<float> predict() = 0;

private:
};

/// @brief
class OnnxEnvironment {
public:
  explicit OnnxEnvironment(OrtLoggingLevel logLevel = ORT_LOGGING_LEVEL_WARNING,
                           const char *logid = "onnxRuntime")
      : env_(logLevel, logid) {}

  Ort::Env &get() { return env_; }

private:
  Ort::Env env_;
};

/// @brief
class OnnxModelInference final : public IModelInference {
public:
  explicit OnnxModelInference(OnnxEnvironment &env,
                              const ORTCHAR_T *modelPath) {
    Ort::SessionOptions opts{};
    session_ = std::make_unique<Ort::Session>(env.get(), modelPath, opts);
  }

  std::vector<float> predict() override { return {}; }

private:
  std::unique_ptr<Ort::Session> session_;
};
