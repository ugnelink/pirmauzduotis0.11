#include "trycatch.h"
void iv_ir_tikr(int& a) {
   
    
    do {
        try {

            if (cin.fail()) { throw std::runtime_error("ivedete netinkama duomeni!!!\n");  }
            else if (a <0 && a>1) { throw std::runtime_error("ivedete netinkama duomeni!!!\n"); }

        }
        catch (const std::runtime_error e) {
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
            cout << "iveskite duomeni dar karta: ";
            cin >> a;
            

        }
    } while (std::cin.fail() == true || (a < 0 && a>1));
}
void paz_ir_tikr(float& a) {
    
    do {
        try {

            if (cin.fail()) { throw std::runtime_error("ivedete netinkama duomeni!!!\n"); }
            else if (a < 0) { throw std::runtime_error("ivedete netinkama duomeni!!!\n"); }
            else if (a > 10) { throw std::runtime_error("ivedete netinkama duomeni!!!\n"); }
        }
        catch (const std::runtime_error e) {
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
            cout << "iveskite duomeni dar karta: ";
            cin >> a;
        }
    } while (std::cin.fail() == true || (a < 0) || (a > 10));
}
void skaicius_ir_tikr(int& a) {
   
    do {
        try {

            if (cin.fail()) { throw std::runtime_error("ivedete netinkama duomeni!!!\n"); }
            else if (a <= 0) { throw std::runtime_error("ivedete netinkama duomeni!!!\n"); }

        }
        catch (const std::runtime_error e) {
            std::cout << e.what();
            std::cin.clear();
            std::cin.ignore(256, '\n');
            cout << "iveskite duomeni dar karta: ";
            cin >> a;
        }
    } while (std::cin.fail() == true || (a <= 0));
}
