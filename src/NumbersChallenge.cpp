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

class NumbersChallenge {
public:
    int MinNumber(vector <int> S) {
        sort(begin(S), end(S));
        int right = 0;
        for (auto a : S) {
            if (a - right > 1) {
                break;
            }
            right += a;
        }
        return right + 1;
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
			int S[]                   = {5, 1, 2};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S[]                   = {2, 1, 4};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S[]                   = {2, 1, 2, 7};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S[]                   = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
			int expected__            = 1092;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int S[]                   = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
			int expected__            = 56523;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int S[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int S[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int S[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = NumbersChallenge().MinNumber(vector <int>(S, S + (sizeof S / sizeof S[0])));
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
