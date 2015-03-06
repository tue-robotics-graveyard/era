cmake_minimum_required(VERSION 2.8.3)
project(era)

include_directories(
    include
)

# ----------------------------------------------------------------------------------------------------

add_library(era_config
    include/era/config/variant.h
    include/era/config/data.h
    include/era/config/reader.h
    include/era/config/writer.h
    include/era/config/parser.h
    include/era/config/emitter.h

    src/config/parser.cpp
    src/config/emitter.cpp
)

# ----------------------------------------------------------------------------------------------------

add_library(era_geometry
    include/era/geometry/math.h
    include/era/geometry/mesh.h
    include/era/geometry/rasterizer.h
    include/era/geometry/primitives.h

    src/geometry/rasterizer.cpp
    src/geometry/primitives.cpp
)

# ----------------------------------------------------------------------------------------------------

add_library(era_io
    include/era/io/data.h
    include/era/io/writer.h
    include/era/io/json_writer.h
    include/era/io/binary_writer.h

    src/io/json_writer.cpp
)

