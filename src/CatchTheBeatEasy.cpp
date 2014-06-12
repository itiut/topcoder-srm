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
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class CatchTheBeatEasy {
public:
    string ableToCatchAll(vector <int> x, vector <int> y) {
        vector<pair<int, int>> ps;
        ps.push_back(make_pair(0, 0));
        for (int i = 0; i < x.size(); i++) {
            ps.push_back(make_pair(y[i], x[i]));
        }
        sort(begin(ps), end(ps));

        for (int i = 0; i < ps.size() - 1; i++) {
            if (ps[i + 1].first - ps[i].first < abs(ps[i + 1].second - ps[i].second)) {
                return "Not able to catch";
            }
        }
        return "Able to catch";
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
			int x[]                   = {-1, 1, 0};
			int y[]                   = {1, 3, 4};
			string expected__         = "Able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-3};
			int y[]                   = {2};
			string expected__         = "Not able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-1, 1, 0};
			int y[]                   = {1, 2, 4};
			string expected__         = "Not able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {0, -1, 1};
			int y[]                   = {9, 1, 3};
			string expected__         = "Able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {70,-108,52,-70,84,-29,66,-33};
			int y[]                   = {141,299,402,280,28,363,427,232};
			string expected__         = "Not able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x[]                   = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
			int y[]                   = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
			string expected__         = "Able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int x[]                   = {0,0,0,0};
			int y[]                   = {0,0,0,0};
			string expected__         = "Able to catch";

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int x[]                   = ;
			int y[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = CatchTheBeatEasy().ableToCatchAll(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
