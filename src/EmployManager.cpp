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

class EmployManager {
public:
    int maximumEarnings(vector <int> value, vector <string> earning) {
        int n = value.size();
        set<int> ours;
        for (int i = 0; i < n; i++) {
            ours.insert(i);
        }
        int earn = 0;
        for (int i = 0; i < n; i++) {
            earn -= value[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                earn += earning[i][j] - '0';
            }
        }

        set<int> theirs;
        while (true) {
            int max_diff = INT_MIN;
            int target = -1;
            for (auto idx : ours) {
                int diff = value[idx];
                for (auto j : ours) {
                    diff -= earning[idx][j] - '0';
                }
                for (auto j : theirs) {
                    diff -= earning[idx][j] - '0';
                }
                if (max_diff < diff) {
                    max_diff = diff;
                    target = idx;
                }
            }
            if (max_diff < 0) {
                break;
            }
            ours.erase(target);
            theirs.insert(target);
            earn += max_diff;
        }
        return earn;
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
			int value[]               = {1, 1};
			string earning[]          = {"02", "20"};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int value[]               = {2, 2};
			string earning[]          = {"01", "10"};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int value[]               = {1, 2, 3, 4};
			string earning[]          = {"0121", "1021", "2201", "1110"};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int value[]               = {2, 2, 0, 1, 4, 0, 1, 0, 0, 4};
			string earning[]          = {"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"};
			int expected__            = 156;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int value[]               = ;
			string earning[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int value[]               = ;
			string earning[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int value[]               = ;
			string earning[]          = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EmployManager().maximumEarnings(vector <int>(value, value + (sizeof value / sizeof value[0])), vector <string>(earning, earning + (sizeof earning / sizeof earning[0])));
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
