export module hello;

#ifdef _MSC_VER
import std;
#else
import <iostream>;
import <string>;
#endif

export namespace hello {
    void say(const std::string& message) {
        std::cout << "Message: " << message << std::endl;
    }
}