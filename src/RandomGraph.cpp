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

class RandomGraph {
public:
    double probability(int n, int p) {
        double pp = p / 1000.0;
        vector<double> qs(n + 1);
        qs[0] = 1.0;
        for (int i = 1; i <= n; i++) {
            qs[i] = qs[i - 1] * (1.0 - pp);
        }

        vector<double> dp(4, 1.0);
        for (int i = 4; i <= n; i++) {
            double prob = 0;
            prob += qs[i - 1] * dp[i - 1];
            prob += (i - 1) * pp * qs[i - 2] * qs[i - 2] * dp[i - 2];
            prob += (i - 1) * (i - 2) / 2 * pp * pp * qs[i - 3] * qs[i - 3] * qs[i - 3] * dp[i - 3];
            prob += (i - 1) * pp * qs[i - 2] * (i - 2) * pp * qs[i - 3] * qs[i - 3] * dp[i - 3];
            dp.push_back(prob);
        }
        return 1 - dp[n];
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
			int n                     = 7;
			int p                     = 0;
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int p                     = 620;
			double expected__         = 0.0;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 4;
			int p                     = 500;
			double expected__         = 0.59375;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 8;
			int p                     = 100;
			double expected__         = 0.33566851611343496;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 15;
			int p                     = 50;
			double expected__         = 0.5686761670525845;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int n                     = 50;
			int p                     = 10;
			double expected__         = 0.7494276522159893;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int n                     = 50;
			int p                     = 1000;
			double expected__         = 1.0;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int n                     = ;
			int p                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int n                     = ;
			int p                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int n                     = ;
			int p                     = ;
			double expected__         = ;

			std::clock_t start__      = std::clock();
			double received__         = RandomGraph().probability(n, p);
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
