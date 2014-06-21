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

class BoxesDiv2 {
public:
    int ceilToPower2(int n) {
        for (int i = 1; ; i <<= 1) {
            if (i >= n) {
                return i;
            }
        }
    }

    void packCandies(vector<int>& candies) {
        for (auto& c : candies) {
            c = ceilToPower2(c);
        }
    }

    int findSize(vector <int> candyCounts) {
        packCandies(candyCounts);
        make_heap(begin(candyCounts), end(candyCounts), greater<int>());

        while (candyCounts.size() > 1) {
            int a = candyCounts.front();
            pop_heap(begin(candyCounts), end(candyCounts), greater<int>());
            candyCounts.pop_back();
            int b = candyCounts.front();
            pop_heap(begin(candyCounts), end(candyCounts), greater<int>());
            candyCounts.pop_back();
            candyCounts.push_back(ceilToPower2(a + b));
            push_heap(begin(candyCounts), end(candyCounts), greater<int>());
        }
        return candyCounts.front();
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
			int candyCounts[]         = {8,8};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int candyCounts[]         = {5,6};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int candyCounts[]         = {1,7};
			int expected__            = 16;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int candyCounts[]         = {1,1,13,1,1};
			int expected__            = 32;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int candyCounts[]         = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
			int expected__            = 1024;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int candyCounts[]         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int candyCounts[]         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int candyCounts[]         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BoxesDiv2().findSize(vector <int>(candyCounts, candyCounts + (sizeof candyCounts / sizeof candyCounts[0])));
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