#pragma once

//

#include <memory>

//

#include "ModelInference.hpp"

//

/// @brief
class App final {
public:
  explicit App(std::unique_ptr<IModelInference> inference)
      : modelInference_(std::move(inference)) {}
  ~App() = default;

  App(const App &) = delete;
  App &operator=(const App &) = delete;

  int exec();

private:
  std::unique_ptr<IModelInference> modelInference_;
};
