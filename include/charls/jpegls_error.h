// Copyright (c) Team CharLS.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include "public_types.h"

#ifdef __cplusplus

#include <system_error>

extern "C" {
#endif

CHARLS_API_IMPORT_EXPORT const void* CHARLS_API_CALLING_CONVENTION charls_get_jpegls_category(void);
CHARLS_API_IMPORT_EXPORT const char* CHARLS_API_CALLING_CONVENTION charls_get_error_message(int32_t error_value);

#ifdef __cplusplus
}

namespace charls {

CHARLS_NO_DISCARD inline const std::error_category& jpegls_category() noexcept
{
    return *static_cast<const std::error_category*>(charls_get_jpegls_category());
}

CHARLS_NO_DISCARD inline std::error_code make_error_code(jpegls_errc error_value) noexcept
{
    return {static_cast<int>(error_value), jpegls_category()};
}


/// <summary>
/// Exception that will be thrown when a called charls method cannot succeed and is allowed to throw.
/// </summary>
class jpegls_error final : public std::system_error
{
public:
    explicit jpegls_error(std::error_code ec)
        : system_error{ec}
    {
    }

    explicit jpegls_error(jpegls_errc error_value)
        : system_error{error_value}
    {
    }
};

inline void check_jpegls_errc(const std::error_code ec)
{
    if (ec)
        throw jpegls_error(ec);
}

} // namespace charls

#endif
