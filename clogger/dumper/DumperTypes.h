/* @doc
 * filename:    DumperTypes.h
 * author:      ugupta
 * Description:
 * DumperTypes contain default dumper type and
 * other types required to completely define dumper class
 */

#pragma once

#include <dumper/StreamDumper.h>

namespace clogger {
namespace dumper {

struct DefaultDumperTypes
{
    using StreamT = std::ostream;
    using DumperT = StreamDumper<StreamT>;
};

} // namespace clogger
} // namespace dumper