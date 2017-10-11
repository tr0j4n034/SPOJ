using System;

namespace Practice
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            const int MAX = 1000005;
            int[] primes = new int[MAX];
            int[] lp = new int[MAX];
            int[] phi = new int[MAX];

            for (int i = 2; i < MAX; i ++) {
                if (primes[i] > 0) {
                    continue;
                }
                for (int j = i; j < MAX; j += i) {
                    primes[j] = 1;
                    lp[j] = i;
                }
            }
            phi[1] = 1;
            for (int i = 2; i < MAX; i ++) {
                int j = i;
                while (j % lp[i] == 0) {
                    j /= lp[i];
                }
                phi[i] = phi[j] * (lp[i] - 1) * i / j / lp[i];
            }

            int T, N;
            T = Convert.ToInt32(Console.ReadLine());
            while (T -- > 0) {
                N = Convert.ToInt32((Console.ReadLine()));
                Console.WriteLine(phi[N]);
            }
        }
    }
}
