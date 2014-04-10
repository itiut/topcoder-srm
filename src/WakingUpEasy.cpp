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

class WakingUpEasy {
public:
    int countAlarms(vector <int> volume, int S) {
        int ret = 0;
        int i = 0;
        while (S > 0) {
            S -= volume[i];
            i = (i + 1) % volume.size();
            ret++;
        }
        return ret;
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

	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
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
			std::cerr << "    Expected: " << expected << std::endl;
			std::cerr << "    Received: " << received << std::endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int volume[]              = {5, 2, 4};
			int S                     = 13;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int volume[]              = {5, 2, 4};
			int S                     = 3;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int volume[]              = {1};
			int S                     = 10000;
			int expected__            = 10000;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int volume[]              = {42, 68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69};
			int S                     = 9999;
			int expected__            = 203;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int volume[]              = ;
			int S                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int volume[]              = ;
			int S                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int volume[]              = ;
			int S                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = WakingUpEasy().countAlarms(vector <int>(volume, volume + (sizeof volume / sizeof volume[0])), S);
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
