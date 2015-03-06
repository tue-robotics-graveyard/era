#include <era/io/json_writer.h>
#include <era/io/binary_writer.h>
#include <iostream>

int main(int argc, char **argv)
{
    era::io::Data pkg;

//    era::io::JSONWriter w(pkg);
    era::io::BinaryWriter w(pkg);

    w.writeValue("test", 123);
    w.writeArray("array");

    std::vector<float> fs;
    for(unsigned int i = 0; i < 12; ++i)
    {
        fs.push_back((float)i / 10);
    }

    w.writeGroup("group");

    w.writeValue("bla", &fs[0], fs.size());

    w.finish();

    std::cout << pkg.size() << std::endl;

    for(unsigned int i = 0; i < pkg.size(); ++i)
        std::cout << (int)pkg[i] << std::endl;
    std::cout << std::endl;




    return 0;
}
