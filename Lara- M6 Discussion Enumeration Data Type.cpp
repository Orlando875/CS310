#include <iostream

enum Days { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

int main() {
    Days today = Monday;

    if (today == Mon) {  
        std::cout << "It's Monday!" << std::endl;
    }

    today = "Tuesday";  

    return 0;
}