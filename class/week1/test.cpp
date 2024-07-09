#include <iostream>
#include <string>

namespace MS {
	double OSVersion = 8.1;
	std::string OSName("Windows");
}

namespace APPLE {
	double OSVersion = 10.9;
	std::string OSName("Mavericks");
}

int main() {
	using namespace std;
	using namespace MS;
	cout << OSVersion << " " << OSName << endl;
	cout << APPLE::OSVersion << " " << APPLE::OSName << endl;
}