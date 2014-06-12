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

class BuildingHeightsEasy {
public:
    int minimum(int M, vector <int> heights) {
        sort(begin(heights), end(heights), greater<int>());
        int ans = INT_MAX;
        for (int hh = 1; hh <= 50; hh++) {
            int cost = 0;
            int num = 0;
            for (auto h : heights) {
                if (num >= M) {
                    break;
                }
                if (h > hh) {
                    continue;
                }
                num++;
                cost += (hh - h);
            }
            if (num >= M) {
                ans = min(ans, cost);
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
			int M                     = 2;
			int heights[]             = {1, 2, 1, 4, 3};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int M                     = 3;
			int heights[]             = {1, 3, 5, 2, 1};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int M                     = 1;
			int heights[]             = {43, 19, 15};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int M                     = 3;
			int heights[]             = {19, 23, 9, 12};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int M                     = 12;
			int heights[]             = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
			int expected__            = 47;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int M                     = ;
			int heights[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int M                     = ;
			int heights[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int M                     = ;
			int heights[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = BuildingHeightsEasy().minimum(M, vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
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
