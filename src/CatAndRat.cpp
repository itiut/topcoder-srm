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

class CatAndRat {
public:
    double getTime(int R, int T, int Vrat, int Vcat) {
        if (Vrat >= Vcat) {
            return -1.0;
        }

        return min((double) T * Vrat, M_PI * R) / (Vcat - Vrat);
    }
};

// BEGIN CUT HERE
#include <algorithm>
#include <cmath>
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

	static const double MAX_DOUBLE_ERROR = 1e-9;
	static bool topcoder_fequ(double expected, double result) {
		if (std::isnan(expected)) {
			return std::isnan(result);
		} else if (std::isinf(expected)) {
			if (expected > 0) {
				return result > 0 && std::isinf(result);
			} else {
				return result < 0 && std::isinf(result);
			}
		} else if (std::isnan(result) || std::isinf(result)) {
			return false;
		} else if (std::fabs(result - expected) < MAX_DOUBLE_ERROR) {
			return true;
		} else {
			double mmin = std::min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			double mmax = std::max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR));
			return result > mmin && result < mmax;
		}
	}
	double moj_relative_error(double expected, double result) {
		if (std::isnan(expected) || std::isinf(expected) || std::isnan(result) || std::isinf(result) || expected == 0) {
			return 0;
		}
		return std::fabs(result-expected) / std::fabs(expected);
	}

	int verify_case(int casenum, const double &expected, const double &received, std::clock_t elapsed) {
		std::cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received);
			if (rerr > 0) {
				std::sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int R                     = 10;
			int T                     = 1;
			int Vrat                  = 1;
			int Vcat                  = 1;
			double expected__         = -1.0;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int R                     = 10;
			int T                     = 1;
			int Vrat                  = 1;
			int Vcat                  = 2;
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int R                     = 10;
			int T                     = 1;
			int Vrat                  = 2;
			int Vcat                  = 1;
			double expected__         = -1.0;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int R                     = 1000;
			int T                     = 1000;
			int Vrat                  = 1;
			int Vcat                  = 1000;
			double expected__         = 1.001001001001001;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int R                     = 1;
			int T                     = 1000;
			int Vrat                  = 1;
			int Vcat                  = 2;
			double expected__         = 3.141592653589793;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int R                     = ;
			int T                     = ;
			int Vrat                  = ;
			int Vcat                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int R                     = ;
			int T                     = ;
			int Vrat                  = ;
			int Vcat                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int R                     = ;
			int T                     = ;
			int Vrat                  = ;
			int Vcat                  = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = CatAndRat().getTime(R, T, Vrat, Vcat);
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
