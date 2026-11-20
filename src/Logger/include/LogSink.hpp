#pragma once

//

#include <iostream>
#include <memory>
#include <mutex>
#include <string_view>

//

/// @brief
class ILogSink {
public:
  /// @brief
  virtual ~ILogSink() = default;

  /// @brief
  /// @param message
  virtual void write(std::string_view message) const = 0;

private:
};

/// @brief
class TerminalSink final : public ILogSink {
public:
  /// @brief
  /// @param message
  void write(std::string_view message) const override {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << message << std::endl;
  }

private:
  /// @brief
  mutable std::mutex mutex_;
};
