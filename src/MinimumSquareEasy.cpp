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

class MinimumSquareEasy {
public:
    long long minArea(vector <int> x, vector <int> y) {
        long long ret = LLONG_MAX;
        vector<int> skips(2);
        for (int i = 0, n = x.size(); i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                skips[0] = i;
                skips[1] = j;
                ret = min(ret, calcArea(x, y, skips));
            }
        }
        return ret;
    }

    long long calcArea(vector<int> x, vector<int> y, vector<int> skips) {
        int min_x, min_y, max_x, max_y;
        min_x = min_y = INT_MAX;
        max_x = max_y = INT_MIN;
        for (int i = 0, n = x.size(); i < n; i++) {
            if (i == skips[0] || i == skips[1]) {
                continue;
            }
            min_x = min(min_x, x[i]);
            max_x = max(max_x, x[i]);
            min_y = min(min_y, y[i]);
            max_y = max(max_y, y[i]);
        }
        long long side = max(abs(max_x - min_x), abs(max_y - min_y)) + 2;
        return side * side;
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

	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) {
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
			int x[]                   = {0, 1, 2};
			int y[]                   = {0, 1, 5};
			long long expected__      = 4;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-1, -1, 0, 2, 0};
			int y[]                   = {-2, -1, 0, -1, -2};
			long long expected__      = 9;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {1000000000, -1000000000, 1000000000, -1000000000};
			int y[]                   = {1000000000, 1000000000, -1000000000, -1000000000};
			long long expected__      = 4000000008000000004LL;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
			int y[]                   = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
			long long expected__      = 22801;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = MinimumSquareEasy().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
