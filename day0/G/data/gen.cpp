#include <cstdio>
#include <cstdlib>
#include <random>
#include <cassert>
#include <algorithm>
using namespace std;
namespace Generator {
	#define dmin(_a, _b) ((_a) < (_b) ? (_a) : (_b))
	#define dmax(_a, _b) ((_a) > (_b) ? (_a) : (_b))
	#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
	#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
	char command[180], prefix[36], inname[36];
	int n, m, k;
	random_device rd;
	mt19937 randgen(rd());
	FILE *log;
	void output(int index, int isdown = 0) {
		if (isdown) sprintf(prefix, "../down/%d", index);
		else sprintf(prefix, "%d", index);
		fprintf(log, "Output to %s.in:\n", prefix);
		sprintf(inname, "%s.in", prefix);
		FILE *p = fopen(inname, "w");
		fprintf(p, "%d %d %d\n", n, m, k);
		fclose(p);
		fprintf(log, "Output Done.\nRun std to get %s.ans.\n", prefix);
		fclose(log);
		sprintf(command, "(time ../AnalogueHeart/gambler < %s.in > %s.ans) 2>> gen.log", prefix, prefix);
		system(command);
		log = fopen("gen.log", "a");
		fprintf(log, "Answer done.\n");
		return ;
	}
	int randint(int lbd, int rbd, int interval = 1) {
		uniform_int_distribution<> gen(0, (rbd - lbd) / interval);
		return lbd + gen(randgen) * interval;
	}
	int isprime(int x) {
		if (x == 1) return 0;
		int i;
		for (i = 2; i * i <= x; ++i) {
			if (x % i == 0) return 0;
		}
		return 1;
	}
	int randprime(int lbd, int rbd) {
		int x;
		do x = randint(lbd, rbd); while (!isprime(x));
		return x;
	}
	void main() {
		int caseid;
		log = fopen("gen.log", "w");
		fprintf(log, "Generating test data:\n");
		for (caseid = 1; caseid <= 14; ++caseid) {
			fprintf(log, "Generating testcase #%d:\n", caseid);
			switch (caseid) {
				case 1: n = m = k = 1; break;
				case 2: n = m = 1, k = 20211123; break;
				case 3: n = 1, m = 666, k = 65300; break;
				case 4: n = 9, m = 1, k = 12563478; break;
				case 5: n = 8, m = 2000, k = 1; break;
				case 6: n = 10, m = 2000, k = 440000000; break;
				case 7: n = 10, m = 1983, k = 994593600; break;
				case 8: n = 9, m = 2000, k = 821620800; break;
				case 9: n = 10, m = 2000, k = 908107200; break;
				case 10: n = 10, m = 1997, k = 616215600; break;
				case 11: n = 10, m = 1999, k = 898405200; break;
				case 12: n = 10, m = 2000, k = 20210526; break;
				case 13: n = 10, m = 2000, k = randprime(900000000, 1000000000); break;
				case 14: n = 10, m = 1998, k = randint(900000000, 1000000000); break;
				default: fprintf(log, "[Warning] Skipping testcase #%d or no config.\n", caseid); continue;
			}
			output(caseid);
		}
		fprintf(log, "Test data done.\nGenerating down:\n");
		for (caseid = 1; caseid <= 3; ++caseid) {
			fprintf(log, "Generating down case #%d:\n", caseid);
			switch (caseid) {
				case 1: n = 3, m = 9, k = 1; break;
				case 2: n = 3, m = 9, k = 10; break;
				case 3: n = 10, m = 2000, k = 20201003; break;
				default: fprintf(log, "[Error] No config for down case #%d.\n", caseid);
			}
			output(caseid, 1);
		}
		fclose(log);
		return ;
	}
	#undef cmax
	#undef cmin
	#undef dmax
	#undef dmin
}
int main(){
	Generator::main();
	return 0;
}