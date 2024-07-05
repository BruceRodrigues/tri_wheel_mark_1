#ifndef PRINTER_H
#define PRINTER_H

namespace Util {

    class Printer {

        public:
            static void println(const char* message);
            static void print(const char* message);

        private:
            Printer();
    };

}

#endif