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

class IncrementingSequence {
public:
    string canItBeDone(int k, vector <int> A) {
        int n = A.size();
        vector<int> hs(n + 1, 0);
        for (auto a : A) {
            hs[a]++;
        }
        for (int i = 1; i <= n; i++) {
            if (hs[i] == 1) {
                continue;
            }
            if (hs[i] == 0 || i + k > n) {
                return "IMPOSSIBLE";
            }
            int inc = hs[i] - 1;
            hs[i] -= inc;
            hs[i + k] += inc;
        }
        return "POSSIBLE";
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
			int k                     = 3;
			int A[]                   = {1,2,4,3};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int k                     = 5;
			int A[]                   = {2,2};
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int k                     = 1;
			int A[]                   = {1,1,1,1,1,1,1,1};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int k                     = 2;
			int A[]                   = {5,3,3,2,1};
			string expected__         = "IMPOSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int k                     = 9;
			int A[]                   = {1,2,3,1,4,5,6,7,9,8};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int k                     = 2;
			int A[]                   = {1,1,1,1,1,1,2,2,2,2,2,2};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int k                     = 1;
			int A[]                   = {1};
			string expected__         = "POSSIBLE";

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int k                     = ;
			int A[]                   = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = IncrementingSequence().canItBeDone(k, vector <int>(A, A + (sizeof A / sizeof A[0])));
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
