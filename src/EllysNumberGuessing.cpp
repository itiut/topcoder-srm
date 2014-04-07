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

class EllysNumberGuessing {
public:
    int getNumber(vector <int> guesses, vector <int> answers) {
        vector<int> candidates;
        int c1 = guesses[0] - answers[0];
        int c2 = guesses[0] + answers[0];
        if (0 < c1 && c1 <= 1000000000) {
            candidates.push_back(c1);
        }
        if (0 < c2 && c2 <= 1000000000) {
            candidates.push_back(c2);
        }
        int ret;
        if (candidates.size() == 2) {
            ret = -1;
        } else if (candidates.size() == 1) {
            ret = candidates[0];
        } else {
            ret = -2;
        }
        for (int i = 1; i < guesses.size(); i++) {
            int c1 = guesses[i] - answers[i];
            int c2 = guesses[i] + answers[i];
            if (candidates.size() == 1) {
                if (c1 != candidates[0] && c2 != candidates[0]) {
                    return -2;
                }
            } else if (candidates.size() == 2) {
                if (find(begin(candidates), end(candidates), c1) != end(candidates)
                    && find(begin(candidates), end(candidates), c2) != end(candidates)) {
                } else if (find(begin(candidates), end(candidates), c1) != end(candidates)) {
                    candidates.clear();
                    candidates.push_back(c1);
                    ret = c1;
                } else if (find(begin(candidates), end(candidates), c2) != end(candidates)) {
                    candidates.clear();
                    candidates.push_back(c2);
                    ret = c2;
                } else {
                    return -2;
                }
            }
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
			int guesses[]             = {600, 594};
			int answers[]             = {6, 12};
			int expected__            = 606;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int guesses[]             = {100, 50, 34, 40};
			int answers[]             = {58, 8, 8, 2};
			int expected__            = 42;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int guesses[]             = {500000, 600000, 700000};
			int answers[]             = {120013, 220013, 79987};
			int expected__            = -2;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int guesses[]             = {500000000};
			int answers[]             = {133742666};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int guesses[]             = {76938260, 523164588, 14196746, 296286419, 535893832, 41243148, 364561227, 270003278, 472017422, 367932361, 395758413, 301278456, 186276934, 316343129, 336557549, 52536121, 98343562, 356769915, 89249181, 335191879};
			int answers[]             = {466274085, 20047757, 529015599, 246925926, 7318513, 501969197, 178651118, 273209067, 71194923, 175279984, 147453932, 241933889, 356935411, 226869216, 206654796, 490676224, 444868783, 186442430, 453963164, 208020466};
			int expected__            = 543212345;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int guesses[]             = {42};
			int answers[]             = {42};
			int expected__            = 84;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int guesses[]             = {999900000};
			int answers[]             = {100001};
			int expected__            = 999799999;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int guesses[]             = {500000000};
			int answers[]             = {600000000};
			int expected__            = -2;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 8: {
			int guesses[]             = {42, 42, 42, 42, 42};
			int answers[]             = {13, 13, 13, 13, 13};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 9: {
			int guesses[]             = ;
			int answers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
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
