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

class PairGameEasy {
public:
    string able(int a, int b, int c, int d) {
        while (a <= c && b <= d) {
            if (a == c && b == d) {
                return "Able to generate";
            }
            if (c > d) {
                c -= d;
            } else {
                d -= c;
            }
        }
        return "Not able to generate";
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
			int a                     = 1;
			int b                     = 2;
			int c                     = 3;
			int d                     = 5;
			string expected__         = "Able to generate";

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 1;
			int b                     = 2;
			int c                     = 2;
			int d                     = 1;
			string expected__         = "Not able to generate";

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 2;
			int b                     = 2;
			int c                     = 2;
			int d                     = 999;
			string expected__         = "Not able to generate";

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 2;
			int b                     = 2;
			int c                     = 2;
			int d                     = 1000;
			string expected__         = "Able to generate";

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 47;
			int b                     = 58;
			int c                     = 384;
			int d                     = 221;
			string expected__         = "Able to generate";

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int a                     = 1000;
			int b                     = 1000;
			int c                     = 1000;
			int d                     = 1000;
			string expected__         = "Able to generate";

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int d                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = PairGameEasy().able(a, b, c, d);
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
