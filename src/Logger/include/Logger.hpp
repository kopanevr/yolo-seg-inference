/**
 * @file
 * @brief
 */

#pragma once

//

#include <memory>
#include <mutex>
#include <string_view>

//

#include "LogSink.hpp"

//

/// @brief
class Logger final {
public:
  static Logger &getInstance() {
    static Logger instance{};
    return instance;
  }

  /// @brief
  void log(std::string_view message) const { logSink_->write(message); }

  Logger &operator=(const Logger &) = delete;
  Logger(const Logger &) = delete;

private:
  /// @brief Конструктор.
  Logger() : logSink_(std::make_unique<TerminalSink>()) {}
  ~Logger() = default;

private:
  /// @brief
  std::unique_ptr<ILogSink> logSink_;
};

#define LOG(...) Logger::getInstance().log(__VA_ARGS__)

#if defined(__cplusplus) && __cplusplus >= 202002L

#ifndef NDEBUG
#define DEBUG(...) LOG("[ОТЛАДКА] " __VA_OPT__(, ) __VA_ARGS__)
#else
#define DEBUG(...) ((void)0)
#endif

#define INFO(...) LOG("[ИНФО] " __VA_OPT__(, ) __VA_ARGS__)
#define WARNING(...) LOG("[ВНИМАНИЕ] " __VA_OPT__(, ) __VA_ARGS__)
#define ERROR(...) LOG("[ОШИБКА] " __VA_OPT__(, ) __VA_ARGS__)

#define SEPARATOR LOG("------")

#else

#define DEBUG(...) ((void)0)

#define INFO(...) ((void)0)
#define WARNING(...) ((void)0)
#define ERROR(...) ((void)0)

#define SEPARATOR ((void)0)

#endif
