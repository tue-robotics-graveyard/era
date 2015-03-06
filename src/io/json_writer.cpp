#include "era/io/json_writer.h"

namespace era
{

namespace io
{

// ----------------------------------------------------------------------------------------------------

JSONWriter::JSONWriter(Data& data) : Writer(data), add_comma_(false)
{
    addString("{");
}

// ----------------------------------------------------------------------------------------------------

JSONWriter::~JSONWriter()
{
}

}

} // end namespace era

