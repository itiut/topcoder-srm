#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class LCMSetEasy {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    string include(vector <int> S, int x) {
        int l = 1;
        for (auto y : S) {
            if (x % y == 0) {
                l = lcm(l, y);
            }
        }
        if (l == x) {
            return "Possible";
        }
        return "Impossible";
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}

	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;

		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl;
			std::cerr << "    Received: \"" << received << "\"" << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int S[]                   = {2,3,4,5};
			int x                     = 20;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {2,3,4};
			int x                     = 611;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {2,3,4};
			int x                     = 12;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {1,2,3,4,5,6,7,8,9,10};
			int x                     = 24;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int S[]                   = {100,200,300,400,500,600};
			int x                     = 2000;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int S[]                   = {100,200,300,400,500,600};
			int x                     = 8000;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int S[]                   = {1000000000,999999999,999999998};
			int x                     = 999999999;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int S[]                   = ;
			int x                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int S[]                   = ;
			int x                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int S[]                   = ;
			int x                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LCMSetEasy().include(vector <int>(S, S + (sizeof S / sizeof S[0])), x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
