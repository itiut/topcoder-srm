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

class CountingSeries {
public:
    long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
        long long ans = 0;
        if (a <= upperBound) {
            ans++;
            ans += (upperBound - a) / b;
        }
        for (long long geom = c; geom <= upperBound; geom *= d) {
            if (geom < a
                || (geom != a && (geom - a) % b != 0)) {
                ans++;
            }
            if (d == 1) {
                break;
            }
        }
        return ans;
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
			long long a               = 1;
			long long b               = 1;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 1000;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 3;
			long long b               = 3;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 343;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 40;
			long long b               = 77;
			long long c               = 40;
			long long d               = 100000;
			long long upperBound      = 40;
			long long expected__      = 1;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long a               = 452;
			long long b               = 24;
			long long c               = 4;
			long long d               = 5;
			long long upperBound      = 600;
			long long expected__      = 10;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long a               = 234;
			long long b               = 24;
			long long c               = 377;
			long long d               = 1;
			long long upperBound      = 10000;
			long long expected__      = 408;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
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
