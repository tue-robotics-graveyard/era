#include <era/config/writer.h>
#include <era/config/reader.h>
#include <era/config/parser.h>
#include <era/config/emitter.h>

#include <iostream>

using namespace era;

// ----------------------------------------------------------------------------------------------------

void showValue(config::Reader& r, const std::string& key)
{
    int v;
    if (r.value(key, v))
        std::cout << key << " = " << v << std::endl;
    else
        std::cout << "Unknown key: '" << key << "'." << std::endl;
}

// ----------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        config::Data data;
        config::Parser p(data);
        p.readFile(argv[1]);

        config::emit(data, std::cout, config::EMIT_JSON);

        return 0;
    }

    config::Data data;
    config::Writer w(data);

    w.writeGroup("test");
    w.setValue("a", 5);
    w.setValue("b", 123);

    w.writeArray("array");

    for(int i = 0; i < 12; ++i)
    {
        w.addArrayItem();
        w.setValue("a", i);
        w.setValue("b", i * 2);
        w.endArrayItem();
    }

    w.endArray();

    w.endGroup();

    std::cout << "----------" << std::endl;

    config::emit(data, std::cout, config::EMIT_JSON | config::EMIT_MINIMAL);

    std::cout << "----------" << std::endl;

    // - - - - - - -

    config::Reader r(data);

    if (!r.readGroup("test"))
        std::cout << "Unknown group" << std::endl;

    if (r.readArray("array"))
    {
        while(r.nextArrayItem())
        {
            showValue(r, "a");
            showValue(r, "b");
        }
        r.endArray();
    }
    else
    {
        std::cout << "Unknown array" << std::endl;
    }

    showValue(r, "b");

    return 0;
}
