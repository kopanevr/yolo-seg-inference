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

  virtual std::vector<float> predict(std::vector<float> &inputData,
                                     std::vector<int64_t> &inputShape) = 0;

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
  explicit OnnxModelInference(OnnxEnvironment &env, const ORTCHAR_T *modelPath)
      : memoryInfo_(
            Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault)) {
    Ort::SessionOptions opts{};
    session_ = std::make_unique<Ort::Session>(env.get(), modelPath, opts);
  }

  std::vector<float> predict(std::vector<float> &inputData,
                             std::vector<int64_t> &inputShape) override {
    Ort::Value inputTensor = Ort::Value::CreateTensor<float>(
      memoryInfo_,
      inputData.data(),
      inputData.size(),
      inputShape.data(),
      inputShape.size()
    );

    auto outputTensors = session_->Run(
      Ort::RunOptions{nullptr},
      inputNamesPtr_.data(),
      &inputTensor,
      1,
      outputNamesPtr_.data(),
      outputNamesPtr_.size()
    );

    return {};
  }

private:

private:
  void cacheNodeNames() {
    const size_t numInputs = session_->GetInputCount();
  }

  std::unique_ptr<Ort::Session> session_;
  Ort::MemoryInfo memoryInfo_;

  std::vector<std::string> inputNames_;
  std::vector<std::string> outputNames_;
  std::vector<const char*> inputNamesPtr_;
  std::vector<const char*> outputNamesPtr_;
};
