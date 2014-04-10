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

class FortunateNumbers {
public:
    bool isFortune(int n) {
        while (n > 0) {
            int d = n % 10;
            if (d != 5 && d != 8) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    int getFortunate(vector <int> a, vector <int> b, vector <int> c) {
        set<int> fortunes;
        for (auto x : a) {
            for (auto y : b) {
                for (auto z : c) {
                    int n = x + y + z;
                    if (isFortune(n)) {
                        fortunes.insert(n);
                    }
                }
            }
        }
        return fortunes.size();
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
			int a[]                   = { 1, 10, 100 };
			int b[]                   = { 3, 53 };
			int c[]                   = { 4, 54 };
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = { 47 };
			int b[]                   = { 500 };
			int c[]                   = { 33 };
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = { 100, 1, 10, 100, 1, 1 };
			int b[]                   = { 3, 53, 53, 53, 53, 53, 53 };
			int c[]                   = { 4, 54, 4, 54, 4, 54 };
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = { 500, 800 };
			int b[]                   = { 50, 80 };
			int c[]                   = { 5, 8 };
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = { 30000, 26264 };
			int b[]                   = { 30000, 29294 };
			int c[]                   = { 30000, 29594 };
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int b[]                   = ;
			int c[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = FortunateNumbers().getFortunate(vector <int>(a, a + (sizeof a / sizeof a[0])), vector <int>(b, b + (sizeof b / sizeof b[0])), vector <int>(c, c + (sizeof c / sizeof c[0])));
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
