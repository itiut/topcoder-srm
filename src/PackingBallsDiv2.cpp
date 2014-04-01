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

class PackingBallsDiv2 {
public:
    int minPacks(int R, int G, int B) {
        vector<int> balls{R, G, B};
        int variety = *min_element(begin(balls), end(balls));
        int ret = variety;
        for (int i = 0; i < balls.size(); i++) {
            balls[i] -= variety;
            int quo = balls[i] / 3;
            if (quo > 0) {
                ret += quo;
                balls[i] -= quo * 3;
            }
        }
        sort(begin(balls), end(balls));
        switch (balls[2]) {
        case 2:
            ret += (balls[1] > 0) ? 2 : 1;
            break;
        case 1:
            ret++;
            break;
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
			int R                     = 4;
			int G                     = 2;
			int B                     = 4;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int R                     = 1;
			int G                     = 7;
			int B                     = 1;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int R                     = 2;
			int G                     = 3;
			int B                     = 5;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int R                     = 78;
			int G                     = 53;
			int B                     = 64;
			int expected__            = 66;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int R                     = 100;
			int G                     = 100;
			int B                     = 100;
			int expected__            = 100;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int R                     = 1;
			int G                     = 2;
			int B                     = 2;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int R                     = 1;
			int G                     = 2;
			int B                     = 5;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			int R                     = 1;
			int G                     = 1;
			int B                     = 3;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = PackingBallsDiv2().minPacks(R, G, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
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
