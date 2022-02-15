#ifndef LOG_HPP_
#define LOG_HPP_

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

inline std::shared_ptr<spdlog::logger> file_log = spdlog::basic_logger_mt("LOGGER", "log.txt");

#define LOG_INFO(...)		spdlog::info(__VA_ARGS__);		file_log->info(__VA_ARGS__)
#define LOG_WARN(...)		spdlog::warn(__VA_ARGS__);		file_log->warn(__VA_ARGS__)
#define LOG_ERROR(...)		spdlog::error(__VA_ARGS__);		file_log->error(__VA_ARGS__)
#define LOG_CRITICAL(...)	spdlog::critical(__VA_ARGS__);  file_log->critical(__VA_ARGS__)
#define LOG_DEBUG(...)		spdlog::debug(__VA_ARGS__);		file_log->debug(__VA_ARGS__)

#endif // !LOG_HPP_
