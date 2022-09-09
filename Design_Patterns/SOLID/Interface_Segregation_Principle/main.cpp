#include <iostream>
#include <memory>
struct IPrinter{
    virtual void print()=0;
};
struct IScanner{
    virtual void scan()=0;
};
struct IFax{
    virtual void fax()=0;
};
struct IWifi{
    virtual void wifi()=0;
};

struct Printer:IPrinter{
    inline void print()override{
        std::cout<<"Printed"<<std::endl;
    }
};
struct Scanner:IScanner{
    inline void scan()override{
        std::cout<<"Scanned"<<std::endl;
    }
};
struct WifiScanner:IScanner,IWifi{
    inline void scan()override{
        std::cout<<"Scanned"<<std::endl;
    }
    inline void wifi()override{
        std::cout<<"Connected"<<std::endl;
    }
};
struct WifiPrinter:IPrinter, IWifi{
    inline void print()override{
        std::cout<<"Printed"<<std::endl;
    }
    inline void wifi()override{
        std::cout<<"Connected"<<std::endl;
    }
};

struct SuperMachine: IPrinter,IScanner,IFax,IWifi{
    inline void print()override{
        std::cout<<"Printed"<<std::endl;
    }
    inline void scan()override{
        std::cout<<"Scanned"<<std::endl;
    }
    inline void fax()override{
        std::cout<<"Sent"<<std::endl;
    }
    inline void wifi()override{
        std::cout<<"Connected"<<std::endl;
    }
};

int main(){
    auto printer = Printer();
    printer.print();
    auto scanner = Scanner();
    scanner.scan();
    auto wifiscanner = WifiScanner();
    wifiscanner.scan();
    wifiscanner.wifi();
    auto superMachine = SuperMachine();
    superMachine.fax();
    superMachine.print();
    wifiscanner.scan();
    wifiscanner.wifi();
    return 0;
}
