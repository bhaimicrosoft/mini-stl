#pragma once

#include <string_view>

namespace ministl
{
  inline constexpr int version_major = 0;
  inline constexpr int version_minor = 1;
  inline constexpr int version_patch = 0;

  [[nodiscard]]
  inline constexpr std::string_view version() noexcept
  {
    return "0.1.0";
  }
}