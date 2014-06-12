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

class AlphabetPath {
public:
    vector<int> dy{-1, 0, 1, 0};
    vector<int> dx{0, 1, 0, -1};

    bool dfs(vector<string>& letterMaze, int h, int w, int y, int x) {
        if (letterMaze[y][x] == 'Z') {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx) {
                continue;
            }
            if (letterMaze[ny][nx] == letterMaze[y][x] + 1) {
                return dfs(letterMaze, h, w, ny, nx);
            }
        }
        return false;
    }

    string doesItExist(vector <string> letterMaze) {
        int h = letterMaze.size();
        int w = letterMaze[0].size();
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (letterMaze[y][x] != 'A') {
                    continue;
                }
                if (dfs(letterMaze, h, w, y, x)) {
                    return "YES";
                }
                break;
            }
        }
        return "NO";
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
			string letterMaze[]       = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string letterMaze[]       = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
;
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string letterMaze[]       = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string letterMaze[]       = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."};
			string expected__         = "NO";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string letterMaze[]       = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."};
			string expected__         = "YES";

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string letterMaze[]       = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letterMaze[]       = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string letterMaze[]       = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
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
